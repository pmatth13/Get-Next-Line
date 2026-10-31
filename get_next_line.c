/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaudell <psaudell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:52:35 by psaudell          #+#    #+#             */
/*   Updated: 2026/10/31 11:40:43 by psaudell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_line(char *stock)
{
	char	*new_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stock)
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	while (j < i)
	{
		new_line[j] = stock[j];
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}

static char	*ft_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

static char	*ft_return_buff(int fd, char *stock)
{
	ssize_t	ret;
	char	*buf;

	ret = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (ft_free(stock, NULL));
	while (ret > 0 && !ft_newline(stock))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (ft_free(stock, buf));
		buf[ret] = '\0';
		stock = ft_join_to_buff(stock, buf);
		if (!stock)
			return (ft_free(NULL, buf));
	}
	ft_free(NULL, buf);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;

	stock = NULL;
	stock = ft_return_buff(fd, stock);
	if (!stock || *stock == '\0')
	{
		free(stock);
		stock = NULL;
	}
	return (stock);
}
