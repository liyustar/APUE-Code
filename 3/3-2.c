#include <fcntl.h>
#include <unistd.h>

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int
main(void)
{
	int fd;
	fd = creat("file.hole", S_IWUSR | S_IRUSR );

	write(fd, buf1, 10);
	lseek(fd, 16384, SEEK_SET);
	write(fd, buf2, 10);
	
	return 0;
}
