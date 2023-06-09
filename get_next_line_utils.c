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
