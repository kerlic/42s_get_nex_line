/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:33:34 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/13 14:52:39 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

//# ifndef BUFFER_SIZE
//#  define BUFFER_SIZE 9999
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
