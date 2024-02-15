/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:04:37 by seojelee          #+#    #+#             */
/*   Updated: 2023/10/14 16:53:40 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_words(char const *s, char c)
{
	int	i;
	int	result;
	int	flag;

	result = 0;
	i = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] != c && flag == 0)
		{
			result++;
			flag = 1;
		}
		if (flag == 1 && s[i] == c)
			flag = 0;
		i++;
	}
	return (result);
}

void	r_write(char *result, char const *s, int start, int i)
{
	int	result_index;

	result_index = 0;
	while (start < i)
		result[result_index++] = s[start++];
	result[result_index] = 0;
}

int	free_result(char **result, int r_index)
{
	int	i;

	i = 0;
	while (i < r_index)
	{
		free(result[i]);
		i++;
	}
	free (result);
	return (0);
}

int	allocate(char **result, char const *s, char c)
{
	int	i;
	int	r_index;
	int	start;

	r_index = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[r_index] = (char *)malloc(sizeof(char) * (i - start + 1));
			if (result[r_index] == 0)
				return (free_result(result, r_index));
			r_write(result[r_index++], s, start, i);
			if (s[i] == 0)
				break ;
		}
		i++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = (char **)malloc(sizeof(char *) * (num_words(s, c) + 1));
	if (result == 0)
		return (0);
	if (allocate(result, s, c) == 0)
		return (0);
	result[num_words(s, c)] = 0;
	return (result);
}
