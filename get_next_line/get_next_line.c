/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <muteallfocus7@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:37:29 by acmaghou          #+#    #+#             */
/*   Updated: 2021/11/25 17:08:57 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 42

static int	locate_char(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i++])
		if (s[i] == c)
			return (i);
	return (0);
}

static char	*get_one_line(char *s)
{
	char	*res;

	res = ft_substr(s, 0, locate_char(s, '\n'));
	return (res);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str;
	char		*line;
	int			i;

	if (!str)
		str = malloc(1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 1;
	while (i > 0 && !locate_char(str, '\n') )
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
			return (free(buffer), NULL);
		buffer[i] = '\0';
		str = ft_strjoin(str, buffer);
	}
	line = get_one_line(str);
	str = ft_substr(str, locate_char(str, '\n') + 1,
			ft_strlen(str) - locate_char(str, '\n'));
	free(buffer);
	return (line);
}

int	main(void)
{
	int fd = open("theEnd.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	return (0);
}