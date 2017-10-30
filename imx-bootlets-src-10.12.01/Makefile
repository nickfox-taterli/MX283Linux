DEV_IMAGE=./

DFT_UBOOT=$(DEV_IMAGE)/u-boot

all: build_prep gen_bootstream

build_prep:


gen_bootstream: boot_prep power_prep

	@echo "by using the rootfs/boot/u-boot"
	sed -i 's,[^ *]u_boot.*;,\tu_boot="$(DFT_UBOOT)";,' uboot_ivt.bd
	./elftosb -f imx28 -c ./uboot_ivt.bd -o imx28_ivt_uboot.sb
	

# TODO
#	@echo "generating uuc boot stream image"

power_prep:
	@echo "build power_prep"
	$(MAKE) -C power_prep ARCH=mx28

boot_prep:
	@echo "build boot_prep"
	$(MAKE) -C boot_prep  ARCH=mx28


distclean: clean
clean:
	-rm -rf *.sb
	$(MAKE) -C boot_prep clean ARCH=mx28
	$(MAKE) -C power_prep clean ARCH=mx28

.PHONY: all build_prep boot_prep power_prep distclean clean

