/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:48:35 by nschutz           #+#    #+#             */
/*   Updated: 2023/06/05 16:17:07 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static char	*next_line(char *buf, char *zs)
{
	char		*nl;
	size_t		i;

	i = 0;
	nl = (char *)malloc(ft_strlen(buf) - ft_strlen(ft_strchr(buf, '\0')));
	while (&buf[i] != ft_strchr(buf, '\0'))
		nl[i] = buf[i];
	zs = ft_strjoin(nl, zs);
	return (zs);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*zs;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE))
	{
		if (ft_strchr(buf, '\0'))
		{
			zs = next_line(buf, zs);
			buf = ft_strchr(buf, '\0') + 1;
			return (zs);
		}
		else
			zs = ft_strjoin(buf, zs);
	}
	return (zs);
}
