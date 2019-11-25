#ifndef LOGHEADER
#define LOGHEADER

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

enum LEVEL
{
	DEBUG, INFO, WARN, ERROR, FATAL
};

struct log_file {
	char *log_file;
	char *fmt;
	int file_fd;
};

/**
* 初始化logger
*/
struct log_file* log_init(char* log_file);

/**
* 日志打印
*/
void log_write(char *message, enum LEVEL level, const struct log_file *logconfig);

/**
* 关闭当前日志
*/
void close_log(struct log_file *log);

#endif
