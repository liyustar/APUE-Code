#include "apue.h"
#include <sys/wait.h>

#define TEST_2

char *env_init[] = { "USER=unknown", "PATH=/tmp", NULL };

int main() {
	pid_t pid;

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
		if (execle("/home/lyx/Work/apue/8/8-9", "echoall", "myarg1",
					"MY ARG2", (char *)0, env_init) < 0)
			err_sys("execle error");
	}
	
	if (waitpid(pid, NULL, 0) < 0)
		err_sys("wait error");

	if ((pid = fork()) < 0) {
		err_sys("fork error");
	} else if (pid == 0) {
		if (execlp("/home/lyx/Work/apue/8/8-9", "8-9", "only 1 arg", (char *)0) < 0)
			err_sys("execlp error");
	}

	exit(0);
}
