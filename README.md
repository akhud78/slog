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
11:06:31 [i] Hello!
$ cat log.txt 
11:06:31 [E] Logger in a file mode!
11:06:31 [d] This is debug message
11:06:31 [t] This is trace message
$ grep "slog\[" /var/log/syslog
Aug  4 11:06:31 spb slog[13281]: [W] This message goes to syslog
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
