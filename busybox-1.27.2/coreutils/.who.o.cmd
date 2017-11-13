cmd_coreutils/who.o := armv5-fsl-linux-gnueabi-gcc -Wp,-MD,coreutils/.who.o.d   -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D"BB_VER=KBUILD_STR(1.27.2)" -DBB_BT=AUTOCONF_TIMESTAMP  -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -fno-builtin-strlen -finline-limit=0 -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -static-libgcc -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin-printf -Os     -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(who)"  -D"KBUILD_MODNAME=KBUILD_STR(who)" -c -o coreutils/who.o coreutils/who.c

deps_coreutils/who.o := \
  coreutils/who.c \
    $(wildcard include/config/users.h) \
    $(wildcard include/config/w.h) \
    $(wildcard include/config/who.h) \
    $(wildcard include/config/feature/clean/up.h) \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/stdc-predef.h \
  include/libbb.h \
    $(wildcard include/config/feature/shadowpasswds.h) \
    $(wildcard include/config/use/bb/shadow.h) \
    $(wildcard include/config/selinux.h) \
    $(wildcard include/config/feature/utmp.h) \
    $(wildcard include/config/locale/support.h) \
    $(wildcard include/config/use/bb/pwd/grp.h) \
    $(wildcard include/config/lfs.h) \
    $(wildcard include/config/feature/buffers/go/on/stack.h) \
    $(wildcard include/config/feature/buffers/go/in/bss.h) \
    $(wildcard include/config/feature/verbose.h) \
    $(wildcard include/config/feature/ipv6.h) \
    $(wildcard include/config/feature/seamless/xz.h) \
    $(wildcard include/config/feature/seamless/lzma.h) \
    $(wildcard include/config/feature/seamless/bz2.h) \
    $(wildcard include/config/feature/seamless/gz.h) \
    $(wildcard include/config/feature/seamless/z.h) \
    $(wildcard include/config/feature/check/names.h) \
    $(wildcard include/config/feature/prefer/applets.h) \
    $(wildcard include/config/long/opts.h) \
    $(wildcard include/config/feature/getopt/long.h) \
    $(wildcard include/config/feature/pidfile.h) \
    $(wildcard include/config/feature/syslog.h) \
    $(wildcard include/config/feature/individual.h) \
    $(wildcard include/config/echo.h) \
    $(wildcard include/config/printf.h) \
    $(wildcard include/config/test.h) \
    $(wildcard include/config/test1.h) \
    $(wildcard include/config/test2.h) \
    $(wildcard include/config/kill.h) \
    $(wildcard include/config/killall.h) \
    $(wildcard include/config/killall5.h) \
    $(wildcard include/config/chown.h) \
    $(wildcard include/config/ls.h) \
    $(wildcard include/config/xxx.h) \
    $(wildcard include/config/route.h) \
    $(wildcard include/config/feature/hwib.h) \
    $(wildcard include/config/desktop.h) \
    $(wildcard include/config/feature/crond/d.h) \
    $(wildcard include/config/feature/securetty.h) \
    $(wildcard include/config/pam.h) \
    $(wildcard include/config/use/bb/crypt.h) \
    $(wildcard include/config/feature/adduser/to/group.h) \
    $(wildcard include/config/feature/del/user/from/group.h) \
    $(wildcard include/config/ioctl/hex2str/error.h) \
    $(wildcard include/config/feature/editing.h) \
    $(wildcard include/config/feature/editing/history.h) \
    $(wildcard include/config/feature/editing/savehistory.h) \
    $(wildcard include/config/feature/tab/completion.h) \
    $(wildcard include/config/feature/username/completion.h) \
    $(wildcard include/config/feature/editing/vi.h) \
    $(wildcard include/config/feature/editing/save/on/exit.h) \
    $(wildcard include/config/pmap.h) \
    $(wildcard include/config/feature/show/threads.h) \
    $(wildcard include/config/feature/ps/additional/columns.h) \
    $(wildcard include/config/feature/topmem.h) \
    $(wildcard include/config/feature/top/smp/process.h) \
    $(wildcard include/config/pgrep.h) \
    $(wildcard include/config/pkill.h) \
    $(wildcard include/config/pidof.h) \
    $(wildcard include/config/sestatus.h) \
    $(wildcard include/config/unicode/support.h) \
    $(wildcard include/config/feature/mtab/support.h) \
    $(wildcard include/config/feature/devfs.h) \
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
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/ctype.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/locale_t.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/__locale_t.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/dirent.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/dirent.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/errno.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/errno.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/linux/errno.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/asm/errno.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/asm-generic/errno.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/asm-generic/errno-base.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/fcntl.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/fcntl.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/fcntl-linux.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/struct_iovec.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/linux/falloc.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/struct_timespec.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/stat.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/inttypes.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/netdb.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/netinet/in.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/socket.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/socket.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/types.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/clock_t.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/clockid_t.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/time_t.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/timer_t.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/select.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/select.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/sigset_t.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/__sigset_t.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/struct_timeval.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/sysmacros.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/sysmacros.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/pthreadtypes.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/thread-shared-types.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/pthreadtypes-arch.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/socket_type.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/sockaddr.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/asm/socket.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/asm-generic/socket.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/asm/sockios.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/asm-generic/sockios.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/struct_osockaddr.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/in.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/rpc/netdb.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/sigevent_t.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/sigval_t.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/netdb.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/setjmp.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/setjmp.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/signal.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/signum.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/signum-generic.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/sig_atomic_t.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/siginfo_t.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/siginfo-arch.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/siginfo-consts.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/siginfo-consts-arch.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/sigevent-consts.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/sigaction.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/sigcontext.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/asm/sigcontext.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/stack_t.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/ucontext.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/sigstack.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/ss_flags.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/struct_sigstack.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/sigthread.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/paths.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/stdio.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/__FILE.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/FILE.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/libio.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/_G_config.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/__mbstate_t.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/lib/gcc/armv5-fsl-linux-gnueabi/7.2.0/include/stdarg.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/stdio_lim.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/sys_errlist.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/stdlib.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/waitflags.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/waitstatus.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/floatn.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/alloca.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/stdlib-float.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/string.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/strings.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/libgen.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/poll.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/poll.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/poll.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/ioctl.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/ioctls.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/asm/ioctls.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/asm-generic/ioctls.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/linux/ioctl.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/asm/ioctl.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/asm-generic/ioctl.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/ioctl-types.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/ttydefaults.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/mman.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/mman.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/mman-linux.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/stat.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/time.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/wait.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/termios.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/termios.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/time.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/time.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/timex.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/struct_tm.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/types/struct_itimerspec.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/param.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/param.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/linux/param.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/asm/param.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/asm-generic/param.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/pwd.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/grp.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/mntent.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/sys/statfs.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/statfs.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/utmp.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/utmp.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/utmpx.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/bits/utmpx.h \
  /home/tater/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/armv5-fsl-linux-gnueabi/sysroot/usr/include/arpa/inet.h \
  include/pwd_.h \
  include/grp_.h \
  include/shadow_.h \
  include/xatonum.h \

coreutils/who.o: $(deps_coreutils/who.o)

$(deps_coreutils/who.o):
