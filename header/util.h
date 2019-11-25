#ifndef UTILHEADER
#define UTILHEADER

#define BT_BUF_SIZE 100
/**
*计算字符串长度
*/
long string_length(const char *string);

/**
* 获取当前时间字符串
*/
char * now_time_str();

/**
* 获取调用者函数信息
* 编译时需要-rdynamic参数，如：cc -rdynamic prog.c -o prog
*/
char * caller_info();
#endif