/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:43:59 by seojelee          #+#    #+#             */
/*   Updated: 2023/10/15 18:53:41 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	start_index(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = 0;
	while (s1[i])
	{
		flag = 0;
		j = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				flag = 1;
			j++;
		}
		if (flag == 0)
			return (i);
		i++;
	}
	return (i);
}

size_t	last_index(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	int		flag;

	if (ft_strlen(s1) == 0)
		return (0);
	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		flag = 0;
		j = 0;
		while (set[j])
		{
			if (set[j] == s1[i])
				flag = 1;
			j++;
		}
		if (flag == 0)
			return (i);
		if (i == 0)
			return (0);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	last;
	size_t	index;

	index = 0;
	start = start_index(s1, set);
	last = last_index(s1, set);
	if (last < start)
		return (ft_strdup(""));
	if (last == 0)
		return (ft_strdup(s1));
	result = (char *)malloc(sizeof(char) * last - start + 2);
	if (result == 0)
		return (0);
	if (last == start)
	{
		result[0] = s1[start];
		result[1] = 0;
		return (result);
	}
	while (start <= last)
		result[index++] = s1[start++];
	result[index] = 0;
	return (result);
}
