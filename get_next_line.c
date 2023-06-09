/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:48:35 by nschutz           #+#    #+#             */
/*   Updated: 2023/06/09 12:06:07 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static void	nl_buffer(char *buf, size_t i)
{
	int	j;

	j = 0;
	while (buf[i] != '\0')
	{
		buf[j] = buf[i];
		j++;
		i++;
	}
	buf[j] = '\0';
}

static char	*next_line(char *buf)
{
	char	*nl;
	size_t	i;

	i = 0;
	nl = (char *) malloc(ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n')) + 1);
	if (!nl)
		return (NULL);
	while (buf[i] != '\n')
	{
		if (buf[i] == '\0')
		{
			nl[i] = '\0';
			return (nl);
		}
		nl[i] = buf[i];
		i++;
	}
	nl[i] = '\0';
	nl_buffer(buf, i + 1);
	return (nl);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*zs;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = (int)read(fd, buf, BUFFER_SIZE);
	if (i < 0)
		return (NULL);
	zs = next_line(buf);
	if (!zs)
		return (NULL);
	return (zs);
}

int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	int		fd2;
	int		fd3;

	fd1 = open("tests/test.txt", O_RDONLY);
	fd2 = open("tests/test2.txt", O_RDONLY);
	fd3 = open("tests/test3.txt", O_RDONLY);
	i = 1;
	while (i < 7)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}

