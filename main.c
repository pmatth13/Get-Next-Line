#include "get_next_line.h"

int	main(void)
{
	int	fd_r;
	int	fd_test;

	fd_r = open("README.md", O_RDONLY);
	//get_next_line(fd_r);
	printf("%d\n", fd_r);
	printf("valeur de close: %d\n", close(fd_r));
	fd_test = open("main.c", O_RDONLY);
	printf("%d\n", fd_test);
	close(fd_test);
	return (0);
}
