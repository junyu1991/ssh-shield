#ifndef LOGHEADER
#define LOGHEADER

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

enum LEVEL
{
	DEBUG=1, INFO, WARN, ERROR, FATAL
};

struct log_file {
	char *log_file;
	char *fmt;
	int file_fd;
};

/**
* 初始化logger
*/
void log_init(char* log_file);

/**
* 日志打印
*/
void log_write(char *message, enum LEVEL level);

/**
* 关闭当前日志
*/
void close_log();

#endif
