/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaudell <psaudell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:52:38 by psaudell          #+#    #+#             */
/*   Updated: 2026/11/01 13:42:44 by psaudell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_newline(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(char	*str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_grow(char *stock, size_t len, size_t *cap, size_t need)
{
	char	*new_stock_cap;
	size_t	i;

	i = 0;
	if (need <= *cap)
		return (stock);
	if (*cap == 0)
		*cap = 1;
	while (need > *cap)
		*cap = *cap * 2;
	new_stock_cap = malloc(sizeof(char) * (*cap + 1));
	if (!new_stock_cap)
		return (ft_free(stock, NULL));
	while (i < len)
	{
		new_stock_cap[i] = stock[i];
		i++;
	}
	new_stock_cap[len] = '\0';
	free(stock);
	return (new_stock_cap);
}
