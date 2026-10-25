#include "get_next_line.h"

int	main(void)
{
/*	int		fd_r;
	int		n;
	char	buf[21];
	ssize_t	ret;

	n = 1;
	fd_r = open("main.c", O_RDONLY);
	ret = read(fd_r, buf, 20);
	buf[ret] = '\0';
	printf("/////// La valeur des octets de ret : %ld\n", ret);
	while (ret > 0)
	{
		printf("Tour %d: <%s>\n", n, buf);
		printf("/////// La valeur des octets de ret : %ld\n", ret);
		n++;
		ret = read(fd_r, buf, 20);
		buf[ret] = '\0';
	}
	printf("/////// La valeur des octets de ret : %ld\n", ret);*/
	printf("Buffer : %d\n", BUFFER_SIZE);
	return (0);
}
