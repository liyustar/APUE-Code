/* Our own header, to be included before all standard system headers */

#ifndef _APUE_H
#define _APUE_H

#include <sys/types.h>
#include <sys/stat.h>

#include <stdio.h>		/* for convenience */
#include <stdlib.h>		/* for convenience */
#include <string.h>		/* for convenience */
#include <unistd.h>		/* for convenience */
#include <signal.h>
#define MAXLINE 4096			/* max line length */

typedef void Sigfunc(int);

void	err_dump(const char *, ...);
void	err_msg(const char *, ...);
void	err_quit(const char *, ...);
void	err_exit(int, const char *, ...);
void	err_ret(const char *, ...);
void	err_sys(const char *, ...);

#endif	/* _APUE_H */
