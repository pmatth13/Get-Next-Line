#include "get_next_line.h"

int	main(void)
{
	int	fd_r;

	fd_r = open("README.md", O_RDONLY);
	get_next_line(fd_r);
	return (0);
}