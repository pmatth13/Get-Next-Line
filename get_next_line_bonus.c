/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaudell <psaudell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:52:35 by psaudell          #+#    #+#             */
/*   Updated: 2026/10/31 16:31:59 by psaudell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *s1, char *s2)
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
	size_t	len;
	size_t	cap;
	size_t	start;

	if (BUFFER_SIZE <= 0)
		return (ft_free(NULL, stock));
	ret = 1;
	len = ft_strlen(stock);
	cap = len;
	start = 0;
	while (ret > 0 && !ft_newline(&stock[start]))
	{
		stock = ft_grow(stock, len, &cap, len + BUFFER_SIZE);
		if (!stock)
			return (NULL);
		start = len;
		ret = read(fd, &stock[len], BUFFER_SIZE);
		if (ret == -1)
			return (ft_free(stock, NULL));
		len = len + ret;
		stock[len] = '\0';
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD)
		return (NULL);
	stock[fd] = ft_return_buff(fd, stock[fd]);
	if (!stock[fd] || *stock[fd] == '\0')
	{
		free(stock[fd]);
		stock[fd] = NULL;
		return (NULL);
	}
	line = ft_line(stock[fd]);
	if (!line)
	{
		free(stock[fd]);
		stock[fd] = NULL;
		return (NULL);
	}
	stock[fd] = ft_new_stock(stock[fd], line);
	return (line);
}
