#include "all_headers.h"

static void handle_events(int fd, int *wd, int argc, char *argv[])
{
	char buf[4096] __attribute__ ((aligned(__alignof__(struct inotify_event))));
	const struct inotify_event *event;
	int i;
	ssize_t len;
	char *ptr;

	for(;;) {
		len = read(fd, buf, sizeof buf);
		if(len == -1 && errno != EAGAIN) {
			perror("read");
			log_write("Read inotify_event error", ERROR);
			return;
		}
		if(len<=0)
			break;
		for(ptr=buf;ptr<buf+len;ptr+=sizeof(struct inotify_event)+event->len) {
			event = (const struct inotify_event *)ptr;
			if(event->mask & IN_CLOSE_WRITE) {
				log_write("IN_CLOSE_WRITE: ", INFO);
				
			}
		}
	}
}

int notify_enable()
{
	return -1;
}

void start() 
{
	char buf;
	int fd, i, poll_num;
	struct notify_file notify_files[2];
	nfds_t nfds;
	struct pollfd poll_fd;
	int temp_wd;

	fd = inotify_init1(IN_NONBLOCK);
	if(fd == -1) {
		log_write("Initialize inotify failed.", ERROR);
		exit(EXIT_FAILURE);
	}
	temp_wd = inotify_add_watch(fd, BTMP, IN_OPEN|IN_CLOSE);
	if(temp_wd == -1) {
		log_write("Add watch to btmp file failed", ERROR);
		exit(EXIT_FAILURE);
	} else {
		notify_files[0].wd = temp_wd;
		notify_files[0].pathname = BTMP;
	}

	temp_wd = inotify_add_watch(fd, UTMP, IN_OPEN|IN_CLOSE);
	if(temp_wd == -1) {
		log_write("Add watch to utmp file failed", ERROR);
		exit(EXIT_FAILURE);
	} else {
		notify_files[1].wd = temp_wd;
		notify_files[1].pathname = UTMP;
	}

	poll_fd.fd = fd;
	poll_fd.events = POLLIN;
	log_write("Start inotify epoll listening..");
	while(1) {
		poll_num = poll(fds, nfds, -1);
	}
}
