#include "all_headers.h"


void test_log() {
	struct log_file *logconfig;
	logconfig = log_init("./logs/test.log");
	if(logconfig != NULL) {
		log_write("DEBUG message", DEBUG, logconfig);
		log_write("INFO message", INFO, logconfig);
		log_write("ERROR message", ERROR, logconfig);
		log_write("WARN message", WARN, logconfig);
		log_write("FATA message", FATAL, logconfig);
	}
	close_log(logconfig);
}

int main(int argc, char *argv[]) 
{
	test_log();
	return 0;
}