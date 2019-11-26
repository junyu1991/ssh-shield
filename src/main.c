#include "all_headers.h"


void test_log() {
	log_init("./logs/test.log");
	log_write("DEBUG message", DEBUG);
	log_write("INFO message", INFO);
	log_write("ERROR message", ERROR);
	log_write("WARN message", WARN);
	log_write("FATA message", FATAL);
	close_log();
}

int main(int argc, char *argv[]) 
{
	test_log();
	return 0;
}
