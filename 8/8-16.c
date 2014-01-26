#include "apue.h"
#include <signal.h>

int main() {
	pid_t pid;

	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid != 0) {
		sleep(2);	/* parent */
		exit(2);
	}

	/* first child */
	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid != 0) {
		sleep(4);	/* parent */
		abort();
	}

	/* second child */
	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid != 0) {
		execl("/bin/dd", "dd", "if=/etc/termcap", "of=/dev/null", NULL);
		exit(7);	/* should't get here */
	}

	/* third child */
	if ((pid = fork()) < 0)
		err_sys("fork error");
	else if (pid != 0) {
		sleep(8);	/* parent */
		exit(0);
	}

	/* forth child */
	sleep(6);
	kill(getpid(), SIGKILL);	/* terminate w/signal, no core dump */
	exit(6);	/* should't get here */
}
