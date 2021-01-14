/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilsong <ilsong@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 20:22:09 by ilsong            #+#    #+#             */
/*   Updated: 2021/01/14 15:56:42 by ilsong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_freeline(char *line, size_t rlen)
{
	char	*temp;

	temp = line;
	while (*line && --rlen)
		*line++ = '\0';
	free(temp);
	temp = NULL;
	return ;
}

void	ft_delline(char *subline, char *nl_loc)
{
	if (!subline || !nl_loc)
		return ;
	nl_loc++;
	while (*nl_loc)
		*subline++ = *nl_loc++;
	*subline = '\0';
	return ;
}

char	*ft_mkline(char *subline, char *buff, size_t rlen)
{
	char	*join;

	if (subline == NULL)
	{
		subline = (char *)malloc(sizeof(char) * 1);
		*subline = '\0';
	}
	buff[rlen] = 0;
	join = ft_strjoin(subline, buff);
	free(subline);
	subline = join;
	return (subline);
}

char	*ft_strdup(char *s)
{
	char	*buff;
	char	*ptr;
	size_t	slen;

	slen = 0;
	while (s[slen] != '\n' && s[slen])
		slen++;
	if (!(buff = (char *)malloc(sizeof(char) * (slen + 1))))
		return (0);
	ptr = buff;
	while (*s)
	{
		if (*s == '\n')
			break ;
		*buff++ = *s++;
	}
	*buff = '\0';
	return (ptr);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	char			*nl_loc;
	size_t			rlen;
	static char		*sub_line[OPEN_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0 || FOPEN_MAX < fd || !line)
		return (-1);
	while ((rlen = read(fd, buff, BUFFER_SIZE)) && !(ft_strchr(buff, '\n')))
		sub_line[fd] = ft_mkline(sub_line[fd], buff, rlen);
	sub_line[fd] = ft_mkline(sub_line[fd], buff, rlen);
	*line = ft_strdup(sub_line[fd]);
	nl_loc = ft_strchr(sub_line[fd], '\n');
	ft_delline(sub_line[fd], nl_loc);
	if (!rlen && !nl_loc)
	{
		ft_freeline(sub_line[fd], rlen);
		return (0);
	}
	return (1);
}
