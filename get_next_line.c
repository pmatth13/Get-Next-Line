/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaudell <psaudell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:52:35 by psaudell          #+#    #+#             */
/*   Updated: 2026/10/31 15:12:55 by psaudell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free(char *s1, char *s2)
{
	free(s1);
	free(s2);
	return (NULL);
}

static char	*ft_new_stock(char *stock, char *line)
{
	int		len_s;
	int		len_l;
	int		len_ns;
	int		i;
	char	*new_stock;

	len_s = ft_strlen(stock);
	len_l = ft_strlen(line);
	len_ns = len_s - len_l ;
	i = 0;
	if (len_ns == 0)
		return (ft_free(stock, NULL));
	new_stock = malloc(sizeof(char) * (len_ns + 1));
	if (!new_stock)
		return (ft_free(stock, NULL));
	while (len_l < len_s)
	{
		new_stock[i] = stock[len_l];
		len_l++;
		i++;
	}
	new_stock[i] = '\0';
	free(stock);
	return (new_stock);
}

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

static char	*ft_return_buff(int fd, char *stock)
{
	ssize_t	ret;
	char	*buf;

	if (BUFFER_SIZE <= 0)
	{
		free(stock);
		return (NULL);
	}
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
	char		*line;

	if (fd < 0)
		return (NULL);
	stock = ft_return_buff(fd, stock);
	if (!stock || *stock == '\0')
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	line = ft_line(stock);
	if (!line)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	stock = ft_new_stock(stock, line);
	return (line);
}
