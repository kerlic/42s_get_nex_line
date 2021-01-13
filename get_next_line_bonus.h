/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:49:13 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/13 14:52:25 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

//# ifndef BUFFER_SIZE
//#  define BUFFER_SIZE 4000
//# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif


int		get_next_line(int fd, char** line);
char	*ft_strcp(char *str, char *src, int is_buff);
char	*ft_strchr(const char* str, int c);
char	*ft_strjoin(char* subline, char* buff);
size_t	ft_strlen(const char* str);


# endif
