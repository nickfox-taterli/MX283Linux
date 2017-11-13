/* This is a generated file, don't edit */

#define NUM_APPLETS 91
#define KNOWN_APPNAME_OFFSETS 4

const uint16_t applet_nameofs[] ALIGN2 = {
110,
251,
395,
};

const char applet_names[] ALIGN1 = ""
"arp" "\0"
"ash" "\0"
"awk" "\0"
"cat" "\0"
"clear" "\0"
"cp" "\0"
"crond" "\0"
"crontab" "\0"
"cut" "\0"
"date" "\0"
"dd" "\0"
"devmem" "\0"
"df" "\0"
"dmesg" "\0"
"echo" "\0"
"env" "\0"
"expr" "\0"
"false" "\0"
"find" "\0"
"free" "\0"
"fsync" "\0"
"getopt" "\0"
"grep" "\0"
"head" "\0"
"hexdump" "\0"
"hostname" "\0"
"ifconfig" "\0"
"init" "\0"
"insmod" "\0"
"ionice" "\0"
"kill" "\0"
"less" "\0"
"link" "\0"
"linuxrc" "\0"
"ln" "\0"
"login" "\0"
"ls" "\0"
"lsmod" "\0"
"makedevs" "\0"
"mdev" "\0"
"mesg" "\0"
"mkdir" "\0"
"mkfifo" "\0"
"mknod" "\0"
"mktemp" "\0"
"modprobe" "\0"
"more" "\0"
"mount" "\0"
"mv" "\0"
"netstat" "\0"
"nice" "\0"
"nl" "\0"
"nproc" "\0"
"nslookup" "\0"
"ping" "\0"
"poweroff" "\0"
"ps" "\0"
"pscan" "\0"
"pwd" "\0"
"readahead" "\0"
"readlink" "\0"
"realpath" "\0"
"reboot" "\0"
"renice" "\0"
"rm" "\0"
"rmdir" "\0"
"rmmod" "\0"
"route" "\0"
"sed" "\0"
"seq" "\0"
"sh" "\0"
"shred" "\0"
"shuf" "\0"
"sleep" "\0"
"sort" "\0"
"split" "\0"
"strings" "\0"
"sync" "\0"
"tail" "\0"
"time" "\0"
"top" "\0"
"touch" "\0"
"true" "\0"
"udhcpc" "\0"
"uevent" "\0"
"umount" "\0"
"uniq" "\0"
"unlink" "\0"
"uptime" "\0"
"usleep" "\0"
"vi" "\0"
;

#define APPLET_NO_arp 0
#define APPLET_NO_ash 1
#define APPLET_NO_awk 2
#define APPLET_NO_cat 3
#define APPLET_NO_clear 4
#define APPLET_NO_cp 5
#define APPLET_NO_crond 6
#define APPLET_NO_crontab 7
#define APPLET_NO_cut 8
#define APPLET_NO_date 9
#define APPLET_NO_dd 10
#define APPLET_NO_devmem 11
#define APPLET_NO_df 12
#define APPLET_NO_dmesg 13
#define APPLET_NO_echo 14
#define APPLET_NO_env 15
#define APPLET_NO_expr 16
#define APPLET_NO_false 17
#define APPLET_NO_find 18
#define APPLET_NO_free 19
#define APPLET_NO_fsync 20
#define APPLET_NO_getopt 21
#define APPLET_NO_grep 22
#define APPLET_NO_head 23
#define APPLET_NO_hexdump 24
#define APPLET_NO_hostname 25
#define APPLET_NO_ifconfig 26
#define APPLET_NO_init 27
#define APPLET_NO_insmod 28
#define APPLET_NO_ionice 29
#define APPLET_NO_kill 30
#define APPLET_NO_less 31
#define APPLET_NO_link 32
#define APPLET_NO_linuxrc 33
#define APPLET_NO_ln 34
#define APPLET_NO_login 35
#define APPLET_NO_ls 36
#define APPLET_NO_lsmod 37
#define APPLET_NO_makedevs 38
#define APPLET_NO_mdev 39
#define APPLET_NO_mesg 40
#define APPLET_NO_mkdir 41
#define APPLET_NO_mkfifo 42
#define APPLET_NO_mknod 43
#define APPLET_NO_mktemp 44
#define APPLET_NO_modprobe 45
#define APPLET_NO_more 46
#define APPLET_NO_mount 47
#define APPLET_NO_mv 48
#define APPLET_NO_netstat 49
#define APPLET_NO_nice 50
#define APPLET_NO_nl 51
#define APPLET_NO_nproc 52
#define APPLET_NO_nslookup 53
#define APPLET_NO_ping 54
#define APPLET_NO_poweroff 55
#define APPLET_NO_ps 56
#define APPLET_NO_pscan 57
#define APPLET_NO_pwd 58
#define APPLET_NO_readahead 59
#define APPLET_NO_readlink 60
#define APPLET_NO_realpath 61
#define APPLET_NO_reboot 62
#define APPLET_NO_renice 63
#define APPLET_NO_rm 64
#define APPLET_NO_rmdir 65
#define APPLET_NO_rmmod 66
#define APPLET_NO_route 67
#define APPLET_NO_sed 68
#define APPLET_NO_seq 69
#define APPLET_NO_sh 70
#define APPLET_NO_shred 71
#define APPLET_NO_shuf 72
#define APPLET_NO_sleep 73
#define APPLET_NO_sort 74
#define APPLET_NO_split 75
#define APPLET_NO_strings 76
#define APPLET_NO_sync 77
#define APPLET_NO_tail 78
#define APPLET_NO_time 79
#define APPLET_NO_top 80
#define APPLET_NO_touch 81
#define APPLET_NO_true 82
#define APPLET_NO_udhcpc 83
#define APPLET_NO_uevent 84
#define APPLET_NO_umount 85
#define APPLET_NO_uniq 86
#define APPLET_NO_unlink 87
#define APPLET_NO_uptime 88
#define APPLET_NO_usleep 89
#define APPLET_NO_vi 90

#ifndef SKIP_applet_main
int (*const applet_main[])(int argc, char **argv) = {
arp_main,
ash_main,
awk_main,
cat_main,
clear_main,
cp_main,
crond_main,
crontab_main,
cut_main,
date_main,
dd_main,
devmem_main,
df_main,
dmesg_main,
echo_main,
env_main,
expr_main,
false_main,
find_main,
free_main,
fsync_main,
getopt_main,
grep_main,
head_main,
hexdump_main,
hostname_main,
ifconfig_main,
init_main,
modprobe_main,
ionice_main,
kill_main,
less_main,
link_main,
init_main,
ln_main,
login_main,
ls_main,
lsmod_main,
makedevs_main,
mdev_main,
mesg_main,
mkdir_main,
mkfifo_main,
mknod_main,
mktemp_main,
modprobe_main,
more_main,
mount_main,
mv_main,
netstat_main,
nice_main,
nl_main,
nproc_main,
nslookup_main,
ping_main,
halt_main,
ps_main,
pscan_main,
pwd_main,
readahead_main,
readlink_main,
realpath_main,
halt_main,
renice_main,
rm_main,
rmdir_main,
modprobe_main,
route_main,
sed_main,
seq_main,
ash_main,
shred_main,
shuf_main,
sleep_main,
sort_main,
split_main,
strings_main,
sync_main,
tail_main,
time_main,
top_main,
touch_main,
true_main,
udhcpc_main,
uevent_main,
umount_main,
uniq_main,
unlink_main,
uptime_main,
usleep_main,
vi_main,
};
#endif

const uint8_t applet_install_loc[] ALIGN1 = {
0x12,
0x13,
0x13,
0x34,
0x13,
0x21,
0x11,
0x31,
0x13,
0x33,
0x11,
0x31,
0x13,
0x22,
0x12,
0x31,
0x01,
0x11,
0x21,
0x22,
0x13,
0x13,
0x21,
0x11,
0x11,
0x31,
0x33,
0x21,
0x31,
0x41,
0x33,
0x32,
0x11,
0x22,
0x31,
0x31,
0x13,
0x33,
0x13,
0x33,
0x13,
0x21,
0x12,
0x33,
0x13,
0x01,
};
