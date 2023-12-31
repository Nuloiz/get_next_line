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

char	*ft_calloc(int size, int count)
{
	int		i;
	char	*out;

	out = malloc(size * count);
	if (out == NULL)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		out[i] = 0;
		i ++;
	}
	return (out);
}

char	*ft_strchr(char *s, int c)
{
	size_t			j;
	unsigned char	i;

	j = 0;
	i = (unsigned char)c;
	if (!s)
		return (0);
	while (j < ft_strlen(s))
	{
		if (s[j] == i)
			return (&s[j]);
		j++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(ft_strlen(s) + 1);
	if (ptr == NULL)
		return (0);
	i = 0;
	while (i < ft_strlen(s))
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	if (!s1)
		return (ft_strdup((char *)s2));
	c = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s2 && c)
	{
		while (s1[i])
		{
			c[i] = s1[i];
			i++;
		}
		while (s2[j])
			c[i++] = s2[j++];
		c[i] = '\0';
		return (c);
	}
	return (0);
}
