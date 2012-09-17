#include "apue.h"

int isRun(int y)
{
	if (y%4==0 && y%100!=0)
		return 1;
	else return 0;
}

int
main(void)
{
	int clock=0, old=0;
	int d=0;
	for ( ; old<=clock; d++) {
		old = clock;
		clock = d*24*3600*100;
		printf("clock: %d\n", clock);
	}
	printf("day: %d\n", d);
	exit(0);
}


		


