/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:12:04 by nschutz           #+#    #+#             */
/*   Updated: 2023/06/12 12:26:59 by nschutz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			j;
	char			*mem;
	unsigned char	i;

	j = 0;
	i = (unsigned char)c;
	if (c < 0 || c > 127)
		return (0);
	mem = (char *)s;
	while (j < ft_strlen(s))
	{
		if (mem[j] == i)
			return (&mem[j]);
		j++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	c = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s1 && s2 && c)
	{
		while (s1[i])
		{
			c[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			c[i] = s2[j];
			i++;
			j++;
		}
		c[i] = '\0';
		return (c);
	}
	return (0);
}
