/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psaudell <psaudell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 14:52:32 by psaudell          #+#    #+#             */
/*   Updated: 2026/10/22 16:36:32 by psaudell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h> 

char	*get_next_line(int	fd);

#endif