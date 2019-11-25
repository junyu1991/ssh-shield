#include "all_headers.h"

long string_length(const char *string)
{
	long i = 0;
	while(string[i++] != '\0');
	return i;
}

char * now_time_str() {
	time_t now;
	struct tm *tm_now;
	int result_size = 32 * sizeof(char);
	char *result = malloc(result_size);
	time(&now);
	tm_now = localtime(&now);
	strftime(result, result_size, "%Y-%m-%d %H:%M:%S", tm_now);
	return result;
}

char * caller_info() {
	int nptrs;
	void *buffer[BT_BUF_SIZE];
	char **strings;
	char * result;
	int result_size;
	int i =0;
	nptrs = backtrace(buffer, BT_BUF_SIZE);
	printf("backtrace() returned %d address\n", nptrs);
	strings = backtrace_symbols(buffer, nptrs);
	if(strings == NULL) {
		perror("backtrace_symbols");
	} else {
		result_size = string_length(strings[0]);
		result = malloc(result_size * sizeof(char));
		strcpy(result, strings[0]);
	}

	free(strings);
	return result;
}