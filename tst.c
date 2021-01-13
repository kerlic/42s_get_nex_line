
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFFER_SIZE 1024

char* ft_strchr(const char* str, int c)
{
	while (*str)
	{
		if (*(unsigned char*)str == (unsigned char)c)
			return ((char*)str);
		str++;
	}
	if (*(unsigned char*)str == (unsigned char)c)
		return ((char*)str);
	return (0);
}

size_t	ft_strlen(const char* str)
{
	size_t n;

	n = 0;
	while (*str++)
		n++;
	return (n);
}


char* ft_strjoin(char const* s1, char const* s2)
{
	char* str;
	char* ptr;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	ptr = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		* str++ = *s2++;
	*(str) = 0;
	return (ptr);
}

void	ft_freeline(char* line)
{
	if (line)
		free(line);
}

int	get_next_line(int fd, char** line)
{
	char			buff[BUFFER_SIZE + 1];
	size_t			rlen;
	static	char* result;
	char* join;

	if (BUFFER_SIZE <= 0 || fd == -1)
		return (-1);
	while ((rlen = read(fd, buff, BUFFER_SIZE)) || ft_strchr(buff, '\n'))
	{
		buff[rlen] = 0;
		join = ft_strjoin(result, buff);
		ft_freeline(result);
		result = join;
	}
	if (rlen < BUFFER_SIZE)
		return (0);
	*line = result;
	return (1);
}

int		main(int argc, char** argv)
{
	char* line;
	int		ret;
	int		fd;

	if (argc == 0)
		return(0);
	//	fd = 0;

	fd = open(argv[1], O_RDONLY);
	int fd2 = open(argv[2], O_RDONLY);
	int fd3 = open(argv[3], O_RDONLY);


	/*	while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("get_next_line : %s\n", line);
			printf("return value : %d\n\n", ret);
			free(line);
		}
		printf("get_next_line : %s\n", line);
		printf("return value : %d\n", ret);
		free(line);
		char *line2;
		ret = get_next_line(fd, &line2);
		printf("get_next_line : %s\n", line2);
		printf("return value : %d\n", ret);
		free(line2);
		char *line3;
		ret = get_next_line(fd, &line3);
		printf("get_next_line : %s\n", line3);
		printf("return value : %d\n", ret);
		free(line3);
	*/

	ret = get_next_line(fd, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n\n", ret);
	free(line);

	ret = get_next_line(fd2, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n\n", ret);
	free(line);

	ret = get_next_line(fd3, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n\n", ret);
	free(line);

	ret = get_next_line(fd, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n\n", ret);
	free(line);

	ret = get_next_line(fd2, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n\n", ret);
	free(line);

	ret = get_next_line(fd3, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n\n", ret);
	free(line);

	ret = get_next_line(fd, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n", ret);
	free(line);

	ret = get_next_line(fd, &line);
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n", ret);
	free(line);
	while (1)
		;

	return (0);
}
