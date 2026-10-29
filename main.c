/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaudell <psaudell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 18:29:26 by psaudell          #+#    #+#             */
/*   Updated: 2026/10/29 15:11:16 by psaudell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	 int	fd_r;
	 char	*line;

	fd_r = open("main.c", O_RDONLY);
	while((line = get_next_line(fd_r)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	return (0);
}
