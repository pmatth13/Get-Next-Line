/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaudell <psaudell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:52:38 by psaudell          #+#    #+#             */
/*   Updated: 2026/10/26 17:20:51 by psaudell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
} */

char	*ft_check(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] || str == NULL)
	{
		if (str[i] == '\n')
			return (&str[i]);
		i++;
	}
	if (str[i] == '\0')
		return (str);
	return (NULL);
}

int main(void)
{
	char *str;

	str = NULL;
	ft_check(str);
	printf("%s\n", str);
	return (0);
}