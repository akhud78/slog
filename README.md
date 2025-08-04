# slog
Simple logger

## Test
- Build
```
mkdir build
cd build
cmake ../src
make
```
- Run
```
$ ./slog
10:50:17 [i] Hello!
$ cat log.txt 
10:50:17 [E] Logger in a file mode!
$ grep "slog\[" /var/log/syslog
Aug  4 10:50:17 spb slog[12855]: [W] This message goes to syslog
```
## Buildroot
### package
- Config.in
```
config BR2_PACKAGE_SLOG
	bool "slog"
	select BR2_PACKAGE_SLOG
	help
	  slog - simple logger

	  https://github.com/akhud78/slog
```
- slog.mk
```
SLOG_SITE = $(call github,akhud78,slog,$(SLOG_VERSION))
SLOG_VERSION = HEAD
SLOG_SUBDIR = src

$(eval $(cmake-package))
```
### rebuild
```
$ cd luckfox-pico/sysdrv/source/buildroot/buildroot-2023.02.6/
$ make slog-dirclean
$ make slog-rebuild
```

### copy to target
```
$ HOST='root@luckfox.local'; PASS='luckfox'
$ sshpass -p $PASS scp output/build/slog-HEAD/src/slog $HOST:/tmp
```
