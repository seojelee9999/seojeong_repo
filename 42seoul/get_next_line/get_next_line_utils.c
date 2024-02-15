/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:45:15 by seojelee          #+#    #+#             */
/*   Updated: 2023/10/29 12:23:33 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_next_line(char *buffer)
{
	int	i;

	if (!buffer)
		return (0);
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s, char *t)
{
	char	*result;
	int		i;
	int		r_index;

	r_index = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + ft_strlen(t) + 1));
	if (!result)
	{
		if (s)
			free (s);
		return (0);
	}
	i = 0;
	if (s)
	{
		while (s[i])
			result[r_index++] = s[i++];
		free (s);
	}
	i = 0;
	while (t[i])
		result[r_index++] = t[i++];
	result[r_index] = 0;
	return (result);
}

int	ft_strlen(const char *s)
{
	int	cnt;

	if (!s)
		return (0);
	cnt = 0;
	while (*s)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;

	i = 0;
	while (i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (1);
}

char	*ft_calloc(int count, int size)
{
	unsigned char	*result;
	int				i;

	if (count * size == 0)
		return (0);
	i = 0;
	result = (unsigned char *)malloc(count * size);
	if (result == 0)
		return (0);
	while (i < count * size)
	{
		result[i] = 0;
		i++;
	}
	return ((char *) result);
}
