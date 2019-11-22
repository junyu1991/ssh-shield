#ifndef LOGHEADER
#define LOGHEADER

#include <stdio.h>
#include <stdlib.h>

struct {
	char *log_file;
	char *fmt;
} log_file;

void init(struct log_file *config);

void log(char *message);
void info(char *message);
void error(char *message);
void debug(char *message);

#endif