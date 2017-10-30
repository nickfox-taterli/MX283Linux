/*
 * Copyright 2009-2010 Freescale Semiconductor, Inc. All Rights Reserved.
 */

/*
 * The code contained herein is licensed under the GNU General Public
 * License. You may obtain a copy of the GNU General Public License
 * Version 2 or later at the following locations:
 *
 * http://www.opensource.org/licenses/gpl-license.html
 * http://www.gnu.org/copyleft/gpl.html
 */

/*
 * This "boot applet" assists the boot ROM by initializing the hardware platform
 * to facilitate and optimize booting. For example, it initializes the external
 * memory controller, so applications can be loaded directly to external SDRAM.
 * This work is not done in the ROM, because it is platform dependent.
 */

////////////////////////////////////////////////////////////////////////////////
#include "types.h"
#include "error.h"

#include "registers/regsrtc.h"
#include "registers/regspower.h"
#include "registers/regsdigctl.h"
#include "registers/regsicoll.h"
#include "registers/hw_irq.h"
#include "hw/power/hw_power.h"
#include "hw/icoll/hw_icoll.h"
#include "hw/core/hw_core.h"
#include "hw/lradc/hw_lradc.h"
#include "hw/digctl/hw_digctl.h"
#include "drivers/power/ddi_power.h"
#include "registers/regsuartdbg.h"
#include "registers/regsclkctrl.h"
#include "registers/regslradc.h"
#include "registers/regsrtc.h"
#include <stdarg.h>

/* for debugging and testing */
#include "registers/regspinctrl.h"

#define BATTERY_BRWNOUT_BITFIELD_VALUE 20 /* 20 = 3.2V */
#define BOOTUP_CHARGE_4P2_CURRENT_LIMIT 780
#define SSP0_PIN_DRIVE_12mA 0x2


bool bBatteryReady = false;

/* 从主电源5V启动(这个操作可能会被多次尝试,直到确切的启动失败.) */
void MasterPower_Boot( void )
{

    uint32_t vdddctrl, vddactrl, vddioctrl, i;

    HW_POWER_5VCTRL_SET(BM_POWER_5VCTRL_VBUSVALID_5VDETECT);

    HW_POWER_CTRL_CLR(BM_POWER_CTRL_POLARITY_VBUSVALID |
                      BM_POWER_CTRL_POLARITY_VDD5V_GT_VDDIO );

    HW_POWER_CTRL_CLR(BM_POWER_CTRL_VBUSVALID_IRQ |
                      BM_POWER_CTRL_VDD5V_GT_VDDIO_IRQ );

    vdddctrl = HW_POWER_VDDDCTRL_RD();
    vddactrl = HW_POWER_VDDACTRL_RD();
    vddioctrl = HW_POWER_VDDIOCTRL_RD();

    HW_POWER_VDDDCTRL_SET(BM_POWER_VDDDCTRL_DISABLE_FET |
                          BM_POWER_VDDDCTRL_ENABLE_LINREG |
                          BM_POWER_VDDDCTRL_PWDN_BRNOUT);

    HW_POWER_VDDACTRL_SET(BM_POWER_VDDACTRL_DISABLE_FET |
                          BM_POWER_VDDACTRL_ENABLE_LINREG |
                          BM_POWER_VDDACTRL_PWDN_BRNOUT);

    HW_POWER_VDDIOCTRL_SET(BM_POWER_VDDIOCTRL_DISABLE_FET |
                           BM_POWER_VDDIOCTRL_PWDN_BRNOUT);


    HW_POWER_DCDC4P2.B.CMPTRIP = 31;

    HW_POWER_DCDC4P2.B.TRG = 0;
    HW_POWER_5VCTRL.B.HEADROOM_ADJ = 0x4;

    HW_POWER_DCDC4P2.B.DROPOUT_CTRL = 0x8;  
    HW_POWER_5VCTRL.B.CHARGE_4P2_ILIMIT = 0x3f;

    BF_SET(POWER_DCDC4P2, ENABLE_4P2);  

    BF_SET(POWER_CHARGE, ENABLE_LOAD);

    HW_POWER_5VCTRL.B.CHARGE_4P2_ILIMIT = 0;

    HW_POWER_DCDC4P2.B.TRG = 0;

    hw_power_EnableMaster4p2( true );

    hw_power_Enable4p2DcdcInput(true);

    if(HW_POWER_CTRL_RD() & BM_POWER_CTRL_VBUSVALID_IRQ)
    {

        hw_digctl_MicrosecondWait(100);
        hw_power_PowerDown();

        return;
    }

    i = HW_POWER_5VCTRL.B.CHARGE_4P2_ILIMIT;

    while(i < hw_power_ConvertCurrentToSetting(
                BOOTUP_CHARGE_4P2_CURRENT_LIMIT))
    {
        i++;
        HW_POWER_5VCTRL.B.CHARGE_4P2_ILIMIT = i;
        hw_digctl_MicrosecondWait(100);
    }

    hw_digctl_MicrosecondWait(100000);

    HW_POWER_CTRL_CLR(BM_POWER_CTRL_DCDC4P2_BO_IRQ);

    if(!bBatteryReady)
    {
        /* 关闭 4.2V 电源域 */
        HW_POWER_DCDC4P2.B.BO = 0;
        HW_POWER_CTRL_CLR(BM_POWER_CTRL_DCDC4P2_BO_IRQ);
        HW_POWER_CTRL_SET(BM_POWER_CTRL_ENIRQ_DCDC4P2_BO);
    }

    hw_power_EnableDcdc( true );

    if(HW_POWER_CTRL_RD() & BM_POWER_CTRL_VBUSVALID_IRQ)
    {

        hw_digctl_MicrosecondWait(100);

        hw_power_PowerDown();
        return;
    }
    HW_POWER_VDDDCTRL_WR(vdddctrl);
    hw_digctl_MicrosecondWait(20);
    HW_POWER_VDDACTRL_WR(vddactrl);
    hw_digctl_MicrosecondWait(20);
    HW_POWER_VDDIOCTRL_WR(vddioctrl);

    if( (HW_POWER_VDDDCTRL.B.DISABLE_FET == 0) ||
            (HW_POWER_VDDACTRL.B.DISABLE_FET == 0) ||
            (HW_POWER_VDDIOCTRL.B.DISABLE_FET == 0))
        BF_CLR(POWER_CHARGE, ENABLE_LOAD);

}




int _start( void )
{
    unsigned int value = 0;

    /* 增加SSP0推动力,否则可能启动失败. */
    HW_PINCTRL_DRIVE8_CLR(
        BM_PINCTRL_DRIVE8_BANK2_PIN07_MA |
        BM_PINCTRL_DRIVE8_BANK2_PIN06_MA |
        BM_PINCTRL_DRIVE8_BANK2_PIN05_MA |
        BM_PINCTRL_DRIVE8_BANK2_PIN04_MA |
        BM_PINCTRL_DRIVE8_BANK2_PIN03_MA |
        BM_PINCTRL_DRIVE8_BANK2_PIN02_MA |
        BM_PINCTRL_DRIVE8_BANK2_PIN01_MA |
        BM_PINCTRL_DRIVE8_BANK2_PIN00_MA);

    HW_PINCTRL_DRIVE9_CLR(
        BM_PINCTRL_DRIVE9_BANK2_PIN10_MA |
        BM_PINCTRL_DRIVE9_BANK2_PIN09_MA |
        BM_PINCTRL_DRIVE9_BANK2_PIN08_MA);

    HW_PINCTRL_DRIVE8_SET(
        (SSP0_PIN_DRIVE_12mA << BP_PINCTRL_DRIVE8_BANK2_PIN07_MA) |
        (SSP0_PIN_DRIVE_12mA << BP_PINCTRL_DRIVE8_BANK2_PIN06_MA) |
        (SSP0_PIN_DRIVE_12mA << BP_PINCTRL_DRIVE8_BANK2_PIN05_MA) |
        (SSP0_PIN_DRIVE_12mA << BP_PINCTRL_DRIVE8_BANK2_PIN04_MA) |
        (SSP0_PIN_DRIVE_12mA << BP_PINCTRL_DRIVE8_BANK2_PIN03_MA) |
        (SSP0_PIN_DRIVE_12mA << BP_PINCTRL_DRIVE8_BANK2_PIN02_MA) |
        (SSP0_PIN_DRIVE_12mA << BP_PINCTRL_DRIVE8_BANK2_PIN01_MA) |
        (SSP0_PIN_DRIVE_12mA << BP_PINCTRL_DRIVE8_BANK2_PIN00_MA));

    HW_PINCTRL_DRIVE9_SET(
        (SSP0_PIN_DRIVE_12mA << BP_PINCTRL_DRIVE9_BANK2_PIN10_MA) |
        (SSP0_PIN_DRIVE_12mA << BP_PINCTRL_DRIVE9_BANK2_PIN09_MA) |
        (SSP0_PIN_DRIVE_12mA << BP_PINCTRL_DRIVE9_BANK2_PIN08_MA));

    /* CPU时钟 = XTAL = 12MHz */
    HW_CLKCTRL_CLKSEQ_SET(BM_CLKCTRL_CLKSEQ_BYPASS_CPU);
    /* RTC BUG(会导致自动重启) */
    HW_RTC_CTRL_CLR( BM_RTC_CTRL_SFTRST );
    while( HW_RTC_CTRL.B.SFTRST == 1 );
    HW_RTC_CTRL_CLR( BM_RTC_CTRL_CLKGATE );
    while( HW_RTC_CTRL.B.CLKGATE == 1 );

    hw_power_SetPowerClkGate( false );

    HW_POWER_VDDDCTRL.B.LINREG_OFFSET = HW_POWER_LINREG_OFFSET_STEP_BELOW;
    HW_POWER_VDDACTRL.B.LINREG_OFFSET = HW_POWER_LINREG_OFFSET_STEP_BELOW;
    HW_POWER_VDDIOCTRL.B.LINREG_OFFSET = HW_POWER_LINREG_OFFSET_STEP_BELOW;

    /* 启动5V检测逻辑 */
    hw_power_EnableVbusValid5vDetect( true );

	/* 5V阈值设置 */
    hw_power_SetVbusValidThresh( VBUS_VALID_THRESH_4400 );
	
	/* 开启电池检测逻辑 */
    extern bool bHwLradcInitialized;
    bHwLradcInitialized = false;
    hw_lradc_Init(FALSE, LRADC_CLOCK_6MHZ);

    hw_lradc_EnableBatteryMeasurement( hw_lradc_AcquireBatteryMonitorDelayTrigger(),
                                       100);

	/* 电源初始化 */
    hw_power_Init();

    HW_RTC_PERSISTENT1_SET(0x800);

    bBatteryReady = false;

    BF_SET(POWER_BATTMONITOR, EN_BATADJ);
    BF_CLR(LRADC_CONVERSION, AUTOMATIC);
    BF_WR(POWER_BATTMONITOR, BATT_VAL, 525); 

    HW_POWER_BATTMONITOR.B.BRWNOUT_LVL = BATTERY_BRWNOUT_BITFIELD_VALUE;

    if( hw_power_GetVbusValid() && hw_power_GetVdd5vGtVddio() )
    {
        MasterPower_Boot();
    }
    else
    {
        hw_digctl_MicrosecondWait(1000);
        if( hw_power_GetVbusValid() && hw_power_GetVdd5vGtVddio() )
        {
            MasterPower_Boot();
        }
        else
        {
            HW_POWER_VDDIOCTRL.B.BO_OFFSET = BO_OFFSET_MAX;
            while(true)
            {
                if( HW_POWER_STS.B.VDDIO_BO )
                {
                    hw_power_PowerDown();
					break;
                }

                if( hw_power_GetVbusValid() && hw_power_GetVdd5vGtVddio() )
                {
                    MasterPower_Boot();
					break;
                }
				
                /* 检查5V是否已经插入 */
                if( ( hw_power_GetVbusValid() || hw_power_GetVdd5vGtVddio() ) == false )
                {
                    hw_power_PowerDown();
					break;
                }

                if( HW_POWER_STS.B.PSWITCH > 0 )
                {

                    HW_POWER_5VCTRL_CLR(BM_POWER_5VCTRL_PWDN_5VBRNOUT);

                    HW_POWER_5VCTRL_CLR(BM_POWER_5VCTRL_ENABLE_DCDC);

                    BF_CLR(POWER_DCDC4P2, ENABLE_DCDC);
                    BF_CLR(POWER_DCDC4P2, ENABLE_4P2);
                    BF_CLR(POWER_CHARGE, ENABLE_LOAD);

                    BF_SET(POWER_5VCTRL, DCDC_XFER);
                    hw_digctl_MicrosecondWait(1000);
                    BF_CLR(POWER_5VCTRL, DCDC_XFER);

                    BF_CLR(POWER_CTRL, ENIRQ_DCDC4P2_BO);

                    HW_POWER_MINPWR_CLR(BM_POWER_MINPWR_HALF_FETS);
                    HW_POWER_MINPWR_SET(BM_POWER_MINPWR_DOUBLE_FETS);

                    HW_POWER_VDDDCTRL.B.LINREG_OFFSET = HW_POWER_LINREG_OFFSET_STEP_BELOW;
                    HW_POWER_VDDACTRL.B.LINREG_OFFSET = HW_POWER_LINREG_OFFSET_STEP_BELOW;
                    HW_POWER_VDDIOCTRL.B.LINREG_OFFSET = HW_POWER_LINREG_OFFSET_STEP_BELOW;

                    HW_POWER_VDDDCTRL.B.DISABLE_FET = 0;
                    HW_POWER_VDDIOCTRL.B.DISABLE_FET = 0;
                    HW_POWER_VDDACTRL.B.DISABLE_FET = 0;

                    HW_POWER_VDDDCTRL.B.ENABLE_LINREG = 0;
                    HW_POWER_VDDACTRL.B.ENABLE_LINREG = 0;

                    HW_POWER_5VCTRL_SET(BM_POWER_5VCTRL_PWD_CHARGE_4P2);
                    HW_POWER_5VCTRL_SET(BM_POWER_5VCTRL_ENABLE_DCDC);

                    BF_WR(POWER_5VCTRL, CHARGE_4P2_ILIMIT, 0x8);
					
					break;

                }
            } 

        }
    }
	/* 把时钟切换到PLL. */
    if((HW_CLKCTRL_PLL0CTRL0_RD() & BM_CLKCTRL_PLL0CTRL0_POWER)
            != BM_CLKCTRL_PLL0CTRL0_POWER)
        HW_CLKCTRL_PLL0CTRL0_SET(BM_CLKCTRL_PLL0CTRL0_POWER);

    value = HW_DIGCTL_MICROSECONDS_RD();
    while ((HW_DIGCTL_MICROSECONDS_RD() - value) <  100);

    if((HW_CLKCTRL_CLKSEQ_RD() & BM_CLKCTRL_CLKSEQ_BYPASS_CPU)
            == BM_CLKCTRL_CLKSEQ_BYPASS_CPU)
        HW_CLKCTRL_CLKSEQ_CLR(BM_CLKCTRL_CLKSEQ_BYPASS_CPU);

    BF_SET(POWER_BATTMONITOR, PWDN_BATTBRNOUT_5VDETECT_ENABLE);


    HW_RTC_PERSISTENT1_CLR(0x800);

    bBatteryReady = true;

    HW_POWER_5VCTRL_CLR(BM_POWER_5VCTRL_PWDN_5VBRNOUT);

	/* 禁止DCDC */
    HW_POWER_5VCTRL_CLR(BM_POWER_5VCTRL_ENABLE_DCDC);

    BF_CLR(POWER_DCDC4P2, ENABLE_DCDC);
    BF_CLR(POWER_DCDC4P2, ENABLE_4P2);
    BF_CLR(POWER_CHARGE, ENABLE_LOAD);

    BF_SET(POWER_5VCTRL, DCDC_XFER);
    hw_digctl_MicrosecondWait(1000);
    BF_CLR(POWER_5VCTRL, DCDC_XFER);

    BF_CLR(POWER_CTRL, ENIRQ_DCDC4P2_BO);

    HW_POWER_MINPWR_CLR(BM_POWER_MINPWR_HALF_FETS);
    HW_POWER_MINPWR_SET(BM_POWER_MINPWR_DOUBLE_FETS);

    HW_POWER_VDDDCTRL.B.LINREG_OFFSET = HW_POWER_LINREG_OFFSET_STEP_BELOW;
    HW_POWER_VDDACTRL.B.LINREG_OFFSET = HW_POWER_LINREG_OFFSET_STEP_BELOW;
    HW_POWER_VDDIOCTRL.B.LINREG_OFFSET = HW_POWER_LINREG_OFFSET_STEP_BELOW;

    HW_POWER_VDDDCTRL.B.DISABLE_FET = 0;
    HW_POWER_VDDIOCTRL.B.DISABLE_FET = 0;
    HW_POWER_VDDACTRL.B.DISABLE_FET = 0;

    HW_POWER_VDDDCTRL.B.ENABLE_LINREG = 0;
    HW_POWER_VDDACTRL.B.ENABLE_LINREG = 0;

    HW_POWER_5VCTRL_SET(BM_POWER_5VCTRL_PWD_CHARGE_4P2);

	/* 使能DCDC */
    HW_POWER_5VCTRL_SET(BM_POWER_5VCTRL_ENABLE_DCDC);

    BF_WR(POWER_5VCTRL, CHARGE_4P2_ILIMIT, 0x8);

    HW_POWER_BATTMONITOR.B.BRWNOUT_LVL = BATTERY_BRWNOUT_BITFIELD_VALUE;

    BF_CLR( POWER_CTRL, BATT_BO_IRQ );
    BF_SET( POWER_CTRL, ENIRQBATT_BO );
    HW_POWER_5VCTRL_SET(BM_POWER_5VCTRL_ILIMIT_EQ_ZERO);

    HW_POWER_VDDDCTRL.B.LINREG_OFFSET = HW_POWER_LINREG_OFFSET_STEP_BELOW;

    HW_POWER_VDDDCTRL.B.DISABLE_FET = 0;
    HW_POWER_VDDDCTRL.B.ENABLE_LINREG = 0;
    HW_POWER_VDDDCTRL.B.DISABLE_STEPPING = 0;
    HW_POWER_CTRL_CLR(BM_POWER_CTRL_VDDD_BO_IRQ |
                      BM_POWER_CTRL_VDDA_BO_IRQ |
                      BM_POWER_CTRL_VDDIO_BO_IRQ);

    HW_POWER_VDDDCTRL.B.PWDN_BRNOUT = 1;
    HW_POWER_VDDACTRL.B.PWDN_BRNOUT = 1;


    HW_POWER_VDDIOCTRL.B.PWDN_BRNOUT = 1;


    /* 设置IO电压 */
    ddi_power_SetVddio(3300, 3150);
    ddi_power_SetVddd(1350, 1200);
    HW_POWER_CTRL_CLR(BM_POWER_CTRL_VDDD_BO_IRQ |
                      BM_POWER_CTRL_VDDA_BO_IRQ |
                      BM_POWER_CTRL_VDDIO_BO_IRQ |
                      BM_POWER_CTRL_VDD5V_DROOP_IRQ |
                      BM_POWER_CTRL_VBUSVALID_IRQ |
                      BM_POWER_CTRL_BATT_BO_IRQ |
                      BM_POWER_CTRL_DCDC4P2_BO_IRQ
                     );
    /* 检查不到电池,就设置为检测不到5V自动关机. */
    if (!bBatteryReady)
    {
        HW_POWER_5VCTRL_SET(BM_POWER_5VCTRL_PWDN_5VBRNOUT);

        HW_POWER_REFCTRL_SET(1 << 7);
    }

    return 0;
}
