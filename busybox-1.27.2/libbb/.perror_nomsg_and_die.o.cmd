cmd_libbb/perror_nomsg_and_die.o := armv5-fsl-linux-gnueabi-gcc -Wp,-MD,libbb/.perror_nomsg_and_die.o.d   -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D"BB_VER=KBUILD_STR(1.27.2)" -DBB_BT=AUTOCONF_TIMESTAMP  -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -fno-builtin-strlen -finline-limit=0 -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -static-libgcc -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin-printf -Os     -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(perror_nomsg_and_die)"  -D"KBUILD_MODNAME=KBUILD_STR(perror_nomsg_and_die)" -c -o libbb/perror_nomsg_and_die.o libbb/perror_nomsg_and_die.c

deps_libbb/perror_nomsg_and_die.o := \
  libbb/perror_nomsg_and_die.c \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/stdc-predef.h \
  include/platform.h \
    $(wildcard include/config/werror.h) \
    $(wildcard include/config/big/endian.h) \
    $(wildcard include/config/little/endian.h) \
    $(wildcard include/config/nommu.h) \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/lib/gcc/armv5-fsl-linux-gnueabi/7.2.0/include-fixed/limits.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/lib/gcc/armv5-fsl-linux-gnueabi/7.2.0/include-fixed/syslimits.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/limits.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/libc-header-start.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/features.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/cdefs.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/wordsize.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/long-double.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/gnu/stubs.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/gnu/stubs-soft.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/posix1_lim.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/local_lim.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/linux/limits.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/posix2_lim.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/xopen_lim.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/uio_lim.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/byteswap.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/byteswap.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/typesizes.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/byteswap-16.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/endian.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/endian.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/uintn-identity.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/lib/gcc/armv5-fsl-linux-gnueabi/7.2.0/include/stdint.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/stdint.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/wchar.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/stdint-intn.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/stdint-uintn.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/lib/gcc/armv5-fsl-linux-gnueabi/7.2.0/include/stdbool.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/unistd.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/posix_opt.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/environments.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/lib/gcc/armv5-fsl-linux-gnueabi/7.2.0/include/stddef.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/confname.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/getopt_posix.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/getopt_core.h \

libbb/perror_nomsg_and_die.o: $(deps_libbb/perror_nomsg_and_die.o)

$(deps_libbb/perror_nomsg_and_die.o):
