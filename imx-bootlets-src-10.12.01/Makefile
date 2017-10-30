export CROSS_COMPILE
MEM_TYPE ?= MEM_DDR1
export MEM_TYPE

DEV_IMAGE=./

DFT_IMAGE=$(DEV_IMAGE)/zImage
DFT_UBOOT=$(DEV_IMAGE)/u-boot

BOARD = iMX28_EVK
ARCH = mx28

all: build_prep gen_bootstream

build_prep:


gen_bootstream: boot_prep power_prep uboot.bd

	@echo "by using the rootfs/boot/u-boot"
	sed -i 's,[^ *]u_boot.*;,\tu_boot="$(DFT_UBOOT)";,' uboot_ivt.bd
	elftosb -f imx28 -c ./uboot_ivt.bd -o i$(ARCH)_ivt_uboot.sb
	

# TODO
#	@echo "generating uuc boot stream image"

power_prep:
	@echo "build power_prep"
	$(MAKE) -C power_prep ARCH=$(ARCH) BOARD=$(BOARD)

boot_prep:
	@echo "build boot_prep"
	$(MAKE) -C boot_prep  ARCH=$(ARCH) BOARD=$(BOARD)


distclean: clean
clean:
	-rm -rf *.sb
	rm -f sd_mmc_bootstream.raw
	$(MAKE) -C boot_prep clean ARCH=$(ARCH)
	$(MAKE) -C power_prep clean ARCH=$(ARCH)

.PHONY: all build_prep boot_prep power_prep distclean clean

