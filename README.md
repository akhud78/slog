# slog
Simple logger

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
slog: 09:34:10 [STATUS] Hello!
$ cat log.txt 
slog: 09:34:10 [ERROR] Logger in a file mode!
$ grep "slog:" /var/log/syslog
Nov 15 09:34:10 spb slog: [WARNING] This message goes to syslog
```