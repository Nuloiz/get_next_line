/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nschutz <nschutz@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 13:12:04 by nschutz           #+#    #+#             */
/*   Updated: 2023/06/05 13:12:04 by nschutz          ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	int		k;
	char	*str;

	k = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
		k = 1;
	}
	if (!s2)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			str[i] = s1[i];
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	if (k == 1)
		free(s1);
	return (str);
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
	while (j <= ft_strlen(s))
	{
		if (mem[j] == i)
			return (&mem[j]);
		j++;
	}
	return (0);
}
