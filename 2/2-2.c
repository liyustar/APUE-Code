#include "apue.h"
#include <errno.h>
#include <limits.h>

static void pr_sysconf(char *, int);
static void pr_pathconf(char *, char *, int);

int
main(int argc, char *argv[])
{
	
	if (argc != 2)
		err_quit("usage: a.out <dirname>");

#ifdef CHILD_MAX
	printf("CHILD_MAX defined to be %d\n", CHILD_MAX+0);
#else
	printf("no symbol for CHILD_MAX\n");
#endif
#ifdef _SC_CHILD_MAX
	pr_sysconf("CHILD_MAX =", _SC_CHILD_MAX);
#else
	printf("no symbol for _SC_CHILD_MAX\n");
#endif
#ifdef ARG_MAX
	printf("ARG_MAX defined to be %d\n", ARG_MAX+0);
#else
	printf("no symbol for ARG_MAX\n");
#endif
#ifdef _SC_ARG_MAX
	pr_sysconf("ARG_MAX =", _SC_ARG_MAX);
#else
	printf("no symbol for _SC_ARG_MAX\n");
#endif
#ifdef ATEXIT_MAX
	printf("ATEXIT_MAX defined to be %d\n", ATEXIT_MAX+0);
#else
	printf("no symbol for ATEXIT_MAX\n");
#endif
#ifdef _SC_ATEXIT_MAX
	pr_sysconf("ATEXIT_MAX =", _SC_ATEXIT_MAX);
#else
	printf("no symbol for _SC_ATEXIT_MAX\n");
#endif
#ifdef IOV_MAX
	printf("IOV_MAX defined to be %d\n", IOV_MAX+0);
#else
	printf("no symbol for IOV_MAX\n");
#endif
#ifdef _SC_IOV_MAX
	pr_sysconf("IOV_MAX =", _SC_IOV_MAX);
#else
	printf("no symbol for _SC_IOV_MAX\n");
#endif
#ifdef LINE_MAX
	printf("LINE_MAX defined to be %d\n", LINE_MAX+0);
#else
	printf("no symbol for LINE_MAX\n");
#endif
#ifdef _SC_LINE_MAX
	pr_sysconf("LINE_MAX =", _SC_LINE_MAX);
#else
	printf("no symbol for _SC_LINE_MAX\n");
#endif
#ifdef NAME_MAX
	printf("NAME_MAX defined to be %d\n", NAME_MAX+0);
#else
	printf("no symbol for NAME_MAX\n");
#endif
#ifdef _PC_NAME_MAX
	pr_pathconf("NAME_MAX =", argv[1], _PC_NAME_MAX);
#else
	printf("no symbol for _PC_NAME_MAX\n");
#endif
	exit(0);
}

static void
pr_sysconf(char *mesg, int name)
{
	long val;

	fputs(mesg, stdout);
	errno = 0;
	if ((val = sysconf(name)) < 0) {
		if (errno != 0) {
			if (errno == EINVAL)
				fputs(" (not supported)\n", stdout);
			else
				err_sys("sysconf error");
		} else {
			fputs(" (no limit)\n", stdout);
		}
	} else {
		printf(" %ld\n", val);
	}
}

static void
pr_pathconf(char *mesg, char *path, int name)
{
	long val;

	fputs(mesg, stdout);
	errno = 0;
	if ((val = pathconf(path, name)) < 0) {
		if (errno != 0) {
			if (errno == EINVAL)
				fputs(" (not supported)\n", stdout);
			else
				err_sys("pathconf error, path = %s", path);
		} else {
			fputs(" (no limit)\n", stdout);
		}
	} else {
		printf(" %ld\n", val);
	}
}
