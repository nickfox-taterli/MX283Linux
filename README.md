# EasyARM i.MX283A V1.02 新软件计划

------

我觉得周立功板子性价比不错，最大的问题就是资料老旧，所以现在我要移植**Linux 4.13.2内核**和**U-Boot 2017.9**,后期有精力可能还会做wiringPi和对应的文件系统吧.这是兴趣而已,也有可能突然就停掉项目.

重要的内核文件位置:

> * zImage @ 0x400000
> * dtb @ 0x800000

------

## 怎么编译

针对u-boot和kernel,都可以把源码目录中的config-default复制成.config,然后加上交叉编译器,make即可.针对imx-bootlets,把u-boot这个文件复制到他的目录下,然后执行build脚本即可.

交叉编译工具需要通过apt-get下载,针对bootlets要用fsl官方工具,否则编译不能执行.

## 暂不支持功能

- [ ] OTP 写入,非驱动工具:[NXP官网下载][1]
- [ ] HSADC 2Mbps DMA[LRADC够用,暂时不开发.]
- [ ] PXP加速器 [暂时不知道用在哪里.]
- [ ] 温度传感应用层程序
- [ ] RTC [因为还没接电池]
- [ ] PERFMON [用不上]
- [ ] devmem2 软件[还没空移植]
- [ ] Qt mesa [CPU实现OpenGL,好像空间不太够.]
- [ ] 快速启动[现在zImage小,但是解压时间长,过段时间评估换压缩方法,需要修改分区.]


  [1]: https://cache.nxp.com/secured/assets/downloads/en/programmers/imx_otp_tools.zip?__gda__=1508346574_4ca3d5e7de1d228ba9a805d6c64ba89a&fileExt=.zip "IMX-OTP-TOOL"
