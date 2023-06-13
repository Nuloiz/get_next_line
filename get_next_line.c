/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:48:35 by nschutz           #+#    #+#             */
/*   Updated: 2023/06/13 10:14:51 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/*static void	nl_buffer(char *buf, size_t i)
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
}*/

/*static char	*next_line(char *buf)
{
	char	*nl;
	size_t	i;

	i = 0;
	if (buf[0] == '\n')
	{
		nl = (char *) malloc(ft_strlen("\n") + 1);
		nl[0] = '\n';
		nl_buffer(buf, 1);
		return (nl);
	}
	nl = (char *) malloc(ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n')) + 1);
	if (!nl)
		return (NULL);
	while (buf[i] != '\n')
	{
		if (buf[i] == '\0')
		{
			nl[i] = '\0';
			buf[0] = '\0';
			return (nl);
		}
		nl[i] = buf[i];
		i++;
	}
	nl[i] = '\0';
	nl_buffer(buf, i + 1);
	return (nl);
}*/

/*char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*zs;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = (int)read(fd, buf, BUFFER_SIZE);
	if (i <= 0)
		return (NULL);
	buf[i] = '\0';
	zs = next_line(buf);
	if (!zs)
		return (NULL);
	return (zs);
}*/

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
	while (i < 8)
	{
		line = get_next_line(fd3);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}

static int	next_line(char *buf, int fd)
{
	char	*nl;
	int		i;

	nl = (char *) malloc(BUFFER_SIZE + 1);
	if (!nl)
		return (0);
	i = 1;
	while (!ft_strchr(buf, '\n') && i != 0)
	{
		i = (int)read(fd, buf, BUFFER_SIZE + 1);
		if (i < 0)
		{
			free(nl);
			return (0);
		}
	}
	buf = ft_strjoin(buf, nl);
	buf[i] = '\0';
	return (1);
}

static char	*give_line(char *buf)
{
	int		i;
	char	*zs;

	i = 0;
	zs = malloc(ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n')) + 1);
	if (!zs)
		return (0);
	while (buf[i] != '\n' && buf[i] != '\0')
	{
		zs[i] = buf[i];
		i++;
	}
	zs[i] = '\0';
	return (zs);
}

static void	nl_buffer(char *buf)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	i = ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\n')) + 1;
	while (buf[i] != '\0')
	{
		buf[j] = buf[i];
		buf[i] = '\0';
		j++;
		i++;
	}
	while (buf[j] != '\0')
	{
		buf[j] = '\0';
		j++;
	}
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*zs;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	i = next_line(buf, fd);
	if (i == 0)
		return (0);
	zs = give_line(buf);
	nl_buffer(buf);
	return (zs);
}
