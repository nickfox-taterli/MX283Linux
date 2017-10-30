/*
 * Freescale MX28EVK board
 *
 * (C) Copyright 2011 Freescale Semiconductor, Inc.
 *
 * Author: Fabio Estevam <fabio.estevam@freescale.com>
 *
 * Based on m28evk.c:
 * Copyright (C) 2011 Marek Vasut <marek.vasut@gmail.com>
 * on behalf of DENX Software Engineering GmbH
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <asm/gpio.h>
#include <asm/io.h>
#include <asm/arch/imx-regs.h>
#include <asm/arch/iomux-mx28.h>
#include <asm/arch/clock.h>
#include <asm/arch/sys_proto.h>
#include <linux/mii.h>
#include <miiphy.h>
#include <netdev.h>
#include <errno.h>

DECLARE_GLOBAL_DATA_PTR;

#define	MUX_CONFIG_SSP0	(MXS_PAD_3V3 | MXS_PAD_8MA | MXS_PAD_PULLUP)
#define	MUX_CONFIG_GPMI	(MXS_PAD_3V3 | MXS_PAD_4MA | MXS_PAD_NOPULL)
#define	MUX_CONFIG_ENET	(MXS_PAD_3V3 | MXS_PAD_8MA | MXS_PAD_PULLUP)
#define	MUX_CONFIG_EMI	(MXS_PAD_3V3 | MXS_PAD_12MA | MXS_PAD_NOPULL)
#define	MUX_CONFIG_SSP2	(MXS_PAD_3V3 | MXS_PAD_4MA | MXS_PAD_PULLUP)
#define	MUX_CONFIG_LCD	(MXS_PAD_3V3 | MXS_PAD_4MA | MXS_PAD_NOPULL)


/*
 * Functions
 */
int board_early_init_f(void)
{
	/* IO0 clock at 480MHz */
	mxs_set_ioclk(MXC_IOCLK0, 480000);
	/* IO1 clock at 480MHz */
	mxs_set_ioclk(MXC_IOCLK1, 480000);

	/* SSP0 clock at 96MHz */
	mxs_set_sspclk(MXC_SSPCLK0, 96000, 0);
	/* SSP2 clock at 160MHz */
	mxs_set_sspclk(MXC_SSPCLK2, 160000, 0);

	/* DUART */
	mxs_iomux_setup_pad(MX28_PAD_PWM0__DUART_RX);
	mxs_iomux_setup_pad(MX28_PAD_PWM1__DUART_TX);

	/* MMC0 */
	mxs_iomux_setup_pad(MX28_PAD_SSP0_DATA0__SSP0_D0 | MUX_CONFIG_SSP0);
	mxs_iomux_setup_pad(MX28_PAD_SSP0_DATA1__SSP0_D1 | MUX_CONFIG_SSP0);
	mxs_iomux_setup_pad(MX28_PAD_SSP0_DATA2__SSP0_D2 | MUX_CONFIG_SSP0);
	mxs_iomux_setup_pad(MX28_PAD_SSP0_DATA3__SSP0_D3 | MUX_CONFIG_SSP0);
	mxs_iomux_setup_pad(MX28_PAD_SSP0_DATA4__SSP0_D4 | MUX_CONFIG_SSP0);
	mxs_iomux_setup_pad(MX28_PAD_SSP0_DATA5__SSP0_D5 | MUX_CONFIG_SSP0);
	mxs_iomux_setup_pad(MX28_PAD_SSP0_DATA6__SSP0_D6 | MUX_CONFIG_SSP0);
	mxs_iomux_setup_pad(MX28_PAD_SSP0_DATA7__SSP0_D7 | MUX_CONFIG_SSP0);
	mxs_iomux_setup_pad(MX28_PAD_SSP0_CMD__SSP0_CMD | MUX_CONFIG_SSP0);
	mxs_iomux_setup_pad(MX28_PAD_SSP0_DETECT__SSP0_CARD_DETECT |
		(MXS_PAD_8MA | MXS_PAD_3V3 | MXS_PAD_NOPULL));
	mxs_iomux_setup_pad(MX28_PAD_SSP0_SCK__SSP0_SCK |
		(MXS_PAD_12MA | MXS_PAD_3V3 | MXS_PAD_NOPULL));
	mxs_iomux_setup_pad(MX28_PAD_GPMI_CE1N__GPIO_0_17 | MUX_CONFIG_SSP0);


#ifdef CONFIG_NAND_MXS
	/* GPMI NAND */
	mxs_iomux_setup_pad(MX28_PAD_GPMI_D00__GPMI_D0 | MUX_CONFIG_GPMI);
	mxs_iomux_setup_pad(MX28_PAD_GPMI_D01__GPMI_D1 | MUX_CONFIG_GPMI);
	mxs_iomux_setup_pad(MX28_PAD_GPMI_D02__GPMI_D2 | MUX_CONFIG_GPMI);
	mxs_iomux_setup_pad(MX28_PAD_GPMI_D03__GPMI_D3 | MUX_CONFIG_GPMI);
	mxs_iomux_setup_pad(MX28_PAD_GPMI_D04__GPMI_D4 | MUX_CONFIG_GPMI);
	mxs_iomux_setup_pad(MX28_PAD_GPMI_D05__GPMI_D5 | MUX_CONFIG_GPMI);
	mxs_iomux_setup_pad(MX28_PAD_GPMI_D06__GPMI_D6 | MUX_CONFIG_GPMI);
	mxs_iomux_setup_pad(MX28_PAD_GPMI_D07__GPMI_D7 | MUX_CONFIG_GPMI);
	mxs_iomux_setup_pad(MX28_PAD_GPMI_CE0N__GPMI_CE0N | MUX_CONFIG_GPMI);
	mxs_iomux_setup_pad(MX28_PAD_GPMI_RDY0__GPMI_READY0 | MUX_CONFIG_GPMI);
	mxs_iomux_setup_pad(MX28_PAD_GPMI_RDN__GPMI_RDN |
		(MXS_PAD_3V3 | MXS_PAD_8MA | MXS_PAD_PULLUP));
	mxs_iomux_setup_pad(MX28_PAD_GPMI_WRN__GPMI_WRN | MUX_CONFIG_GPMI);
	mxs_iomux_setup_pad(MX28_PAD_GPMI_ALE__GPMI_ALE | MUX_CONFIG_GPMI);
	mxs_iomux_setup_pad(MX28_PAD_GPMI_CLE__GPMI_CLE | MUX_CONFIG_GPMI);
	mxs_iomux_setup_pad(MX28_PAD_GPMI_RESETN__GPMI_RESETN | MUX_CONFIG_GPMI);
#endif

	/* FEC0 */
	mxs_iomux_setup_pad(MX28_PAD_ENET0_MDC__ENET0_MDC | MUX_CONFIG_ENET);
	mxs_iomux_setup_pad(MX28_PAD_ENET0_MDIO__ENET0_MDIO | MUX_CONFIG_ENET);
	mxs_iomux_setup_pad(MX28_PAD_ENET0_RX_EN__ENET0_RX_EN | MUX_CONFIG_ENET);
	mxs_iomux_setup_pad(MX28_PAD_ENET0_TX_EN__ENET0_TX_EN | MUX_CONFIG_ENET);
	mxs_iomux_setup_pad(MX28_PAD_ENET0_RXD0__ENET0_RXD0 | MUX_CONFIG_ENET);
	mxs_iomux_setup_pad(MX28_PAD_ENET0_RXD1__ENET0_RXD1 | MUX_CONFIG_ENET);
	mxs_iomux_setup_pad(MX28_PAD_ENET0_TXD0__ENET0_TXD0 | MUX_CONFIG_ENET);
	mxs_iomux_setup_pad(MX28_PAD_ENET0_TXD1__ENET0_TXD1 | MUX_CONFIG_ENET);
	mxs_iomux_setup_pad(MX28_PAD_ENET_CLK__CLKCTRL_ENET | MUX_CONFIG_ENET);
	/* FEC0 Reset */
	mxs_iomux_setup_pad(MX28_PAD_LCD_D16__GPIO_1_16 |
		(MXS_PAD_12MA | MXS_PAD_3V3 | MXS_PAD_PULLUP));

	/* EMI */
	mxs_iomux_setup_pad(MX28_PAD_EMI_D00__EMI_DATA0 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D01__EMI_DATA1 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D02__EMI_DATA2 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D03__EMI_DATA3 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D04__EMI_DATA4 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D05__EMI_DATA5 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D06__EMI_DATA6 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D07__EMI_DATA7 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D08__EMI_DATA8 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D09__EMI_DATA9 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D10__EMI_DATA10 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D11__EMI_DATA11 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D12__EMI_DATA12 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D13__EMI_DATA13 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D14__EMI_DATA14 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_D15__EMI_DATA15 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_ODT0__EMI_ODT0 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_DQM0__EMI_DQM0 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_DQM1__EMI_DQM1 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_DDR_OPEN_FB__EMI_DDR_OPEN_FEEDBACK | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_CLK__EMI_CLK | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_DQS0__EMI_DQS0 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_DQS1__EMI_DQS1 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_DDR_OPEN__EMI_DDR_OPEN | MUX_CONFIG_EMI);

	mxs_iomux_setup_pad(MX28_PAD_EMI_A00__EMI_ADDR0 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_A01__EMI_ADDR1 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_A02__EMI_ADDR2 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_A03__EMI_ADDR3 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_A04__EMI_ADDR4 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_A05__EMI_ADDR5 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_A06__EMI_ADDR6 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_A07__EMI_ADDR7 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_A08__EMI_ADDR8 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_A09__EMI_ADDR9 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_A10__EMI_ADDR10 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_A11__EMI_ADDR11 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_A12__EMI_ADDR12 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_A13__EMI_ADDR13 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_A14__EMI_ADDR14 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_BA0__EMI_BA0 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_BA1__EMI_BA1 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_BA2__EMI_BA2 | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_CASN__EMI_CASN | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_RASN__EMI_RASN | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_WEN__EMI_WEN | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_CE0N__EMI_CE0N | MUX_CONFIG_EMI);
	mxs_iomux_setup_pad(MX28_PAD_EMI_CKE__EMI_CKE | MUX_CONFIG_EMI);

	/* I2C */
	mxs_iomux_setup_pad(MX28_PAD_I2C0_SCL__I2C0_SCL);
	mxs_iomux_setup_pad(MX28_PAD_I2C0_SDA__I2C0_SDA);
	mxs_iomux_setup_pad(MX28_PAD_PWM0__I2C1_SCL);
	mxs_iomux_setup_pad(MX28_PAD_PWM1__I2C1_SDA);

	/* LCD */
	mxs_iomux_setup_pad(MX28_PAD_LCD_D00__LCD_D0 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D01__LCD_D1 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D02__LCD_D2 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D03__LCD_D3 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D04__LCD_D4 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D05__LCD_D5 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D06__LCD_D6 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D07__LCD_D7 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D08__LCD_D8 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D09__LCD_D9 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D10__LCD_D10 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D11__LCD_D11 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D12__LCD_D12 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D13__LCD_D13 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D14__LCD_D14 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_D15__LCD_D15 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_RD_E__LCD_VSYNC | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_WR_RWN__LCD_HSYNC | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_RS__LCD_DOTCLK | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_CS__LCD_ENABLE | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_LCD_RESET__GPIO_3_30 | MUX_CONFIG_LCD);
	mxs_iomux_setup_pad(MX28_PAD_PWM3__GPIO_3_28 | MUX_CONFIG_LCD); /* LCD contrast */


#ifdef	CONFIG_CMD_USB
	mxs_iomux_setup_pad(MX28_PAD_SSP2_SS1__USB1_OVERCURRENT);
        mxs_iomux_setup_pad(MX28_PAD_SSP2_SS2__USB0_OVERCURRENT);
#endif

	/* Power on LCD */
	gpio_direction_output(MX28_PAD_LCD_RESET__GPIO_3_30, 1);

	/* Set contrast to maximum */
	gpio_direction_output(MX28_PAD_PWM3__GPIO_3_28, 1);

	return 0;
}

int dram_init(void)
{
	return mxs_dram_init();
}

int board_init(void)
{
	/* Adress of boot parameters */
	gd->bd->bi_boot_params = PHYS_SDRAM_1 + 0x100;

	return 0;
}

#ifdef	CONFIG_CMD_MMC
static int mx28evk_mmc_wp(int id)
{
	if (id != 0) {
		printf("MXS MMC: Invalid card selected (card id = %d)\n", id);
		return 1;
	}

	return gpio_get_value(MX28_PAD_GPMI_CE1N__GPIO_0_17);
}

int board_mmc_init(bd_t *bis)
{
	/* Configure WP as input */
	gpio_direction_input(MX28_PAD_GPMI_CE1N__GPIO_0_17);

	return mxsmmc_initialize(bis, 0, mx28evk_mmc_wp, NULL);
}
#endif

#ifdef	CONFIG_CMD_NET

int board_eth_init(bd_t *bis)
{
	struct mxs_clkctrl_regs *clkctrl_regs =
		(struct mxs_clkctrl_regs *)MXS_CLKCTRL_BASE;
	struct eth_device *dev;
	int ret;

	ret = cpu_eth_init(bis);
	if (ret)
		return ret;

	/* MX28EVK uses ENET_CLK PAD to drive FEC clock */
	writel(CLKCTRL_ENET_TIME_SEL_RMII_CLK | CLKCTRL_ENET_CLK_OUT_EN,
	       &clkctrl_regs->hw_clkctrl_enet);

	/* Reset FEC PHYs */
	gpio_direction_output(MX28_PAD_LCD_D16__GPIO_1_16, 0);
	udelay(200);
	gpio_set_value(MX28_PAD_LCD_D16__GPIO_1_16, 1);

	ret = fecmxc_initialize_multi(bis, 0, 0, MXS_ENET0_BASE);
	if (ret) {
		puts("FEC MXS: Unable to init FEC0\n");
		return ret;
	}

	ret = fecmxc_initialize_multi(bis, 1, 3, MXS_ENET1_BASE);
	if (ret) {
		puts("FEC MXS: Unable to init FEC1\n");
		return ret;
	}

	dev = eth_get_dev_by_name("FEC0");
	if (!dev) {
		puts("FEC MXS: Unable to get FEC0 device entry\n");
		return -EINVAL;
	}

	dev = eth_get_dev_by_name("FEC1");
	if (!dev) {
		puts("FEC MXS: Unable to get FEC1 device entry\n");
		return -EINVAL;
	}

	return ret;
}

#endif
