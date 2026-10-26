/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaudell <psaudell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:29:26 by psaudell          #+#    #+#             */
/*   Updated: 2026/10/26 18:40:24 by psaudell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	/* int		fd_r;
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
	printf("/////// La valeur des octets de ret : %ld\n", ret);
	printf("Buffer : %d\n", BUFFER_SIZE); */
	char	*str;
	
	str = NULL;
	str = ft_join_to_buff(str, "abc");
	printf("%s\n", str);
	str = ft_join_to_buff(str, "def");
	printf("%s\n", str);
	free(str);
	return (0);
}
