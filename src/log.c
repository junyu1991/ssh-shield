#include "all_headers.h"

struct log_file* log_init(char* log_file) {
	struct log_file* log = (struct log_file*)malloc(sizeof(struct log_file));
	//fmt = [debug-level] [log-time] caller-info: message
	char *fmt = "[%s] [%s] %s : %s\n";
	int file_fd = open(log_file, O_WRONLY|O_APPEND|O_CREAT, 0666);
	if(file_fd < 0) {
		perror("open");
		return log;
	}
	log->file_fd = file_fd;
	log->fmt = fmt;
	log->log_file = log_file;
	return log;
}

int write_to_file(char *message, int log_file) {
	long message_size = string_length(message);
	printf("%s", message);
	return write(log_file, message, message_size);
}


void log_write(char *message, enum LEVEL level, const struct log_file *logconfig) {
	
	char *time_str = now_time_str();
	char *caller = caller_info();
	long total_size = string_length(time_str) + string_length(caller) + string_length(message) + string_length(logconfig->fmt)-8;

	char *s;//= (char *)malloc(sizeof(char) * total_size);
	switch(level) {
		case INFO:
			s = (char *)malloc(sizeof(char) * (total_size + 4));
			sprintf(s, logconfig->fmt, "info", time_str, caller, message);
			write_to_file(s, logconfig->file_fd);
			break;
		case DEBUG:
			s = (char *)malloc(sizeof(char) * (total_size + 5));
			sprintf(s, logconfig->fmt, "debug", time_str, caller, message);
			write_to_file(s, logconfig->file_fd);
			break;
		case ERROR:
			s = (char *)malloc(sizeof(char) * (total_size + 5));
			sprintf(s, logconfig->fmt, "error", time_str, caller, message);
			write_to_file(s, logconfig->file_fd);
			break;
		case WARN:
			s = (char *)malloc(sizeof(char) * (total_size + 4));
			sprintf(s, logconfig->fmt, "warn", time_str, caller, message);
			write_to_file(s, logconfig->file_fd);
			break;
		case FATAL:
			s = (char *)malloc(sizeof(char) * (total_size + 5));
			sprintf(s, logconfig->fmt, "fatal", time_str, caller, message);
			write_to_file(s, logconfig->file_fd);
		default:
			perror("Unknown debug level.");
			s = (char *)malloc(sizeof(char) * (total_size + 6));
			sprintf(s, logconfig->fmt, "unknown", time_str, caller, message);
			write_to_file(s, logconfig->file_fd);
			printf("%s", s);
			break;
	}

	free(time_str);
	free(caller);
	free(s);
}

void close_log(struct log_file *log) {
	if(log!=NULL && log->file_fd > 0){
		close(log->file_fd);
	}
	free(log);
}
