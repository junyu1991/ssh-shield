# ifndef NOTIFY_HEADER
# define NOTIFY_HEADER

#define BTMP "/var/log/btmp"
#define UTMP "/var/log/utmp"

//检查当前环境notify是否可用
bool notify_enable();
//退出notify，释放notify资源
int exit(int notifyfd);
//开始inotify监控文件
void start();

#endif