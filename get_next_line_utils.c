/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:39:15 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/13 01:16:06 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char* subline, char* buff)
{
    int		len;
    char	*str;
	char	*sub_end;

 	len = ft_strlen(subline) + ft_strlen(buff);
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	sub_end = ft_strcp(str, subline, 0);
	ft_strcp(sub_end, buff, 1);
	return (str);
}

size_t	ft_strlen(const char* str)
{
	size_t n;

	n = 0;
  	while (*str++)
		n++;
	return (n);
}

char	*ft_strcp(char *str, char *src, int is_buff)
{
	while (*src)
		*str++ = *src++;
	if (is_buff)
		*str = 0;
	return (str);
}

char	*ft_strchr(const char* str, int c)
{
	while (*str)
	{
		if (*(unsigned char*)str == (unsigned char)c)
			return ((char*)str);
		str++;
	}
	if (*(unsigned char*)str == (unsigned char)c)
		return ((char*)str);
	return (NULL);
}
