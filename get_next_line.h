/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaudell <psaudell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:52:32 by psaudell          #+#    #+#             */
/*   Updated: 2026/11/01 12:22:43 by psaudell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_newline(char *str);
char	*ft_free(char *s1, char *s2);
char	*ft_grow(char *stock, size_t len, size_t *cap, size_t need);
size_t	ft_strlen(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

#endif