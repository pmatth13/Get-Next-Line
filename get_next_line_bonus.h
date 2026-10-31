/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaudell <psaudell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:52:32 by psaudell          #+#    #+#             */
/*   Updated: 2026/10/31 16:32:46 by psaudell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_join_to_buff(char *buffer, char *str);
char	*ft_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

#endif