/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 12:42:14 by seojelee          #+#    #+#             */
/*   Updated: 2023/10/13 20:04:06 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	i;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	if (ft_strlen(s) - start > len)
	{
		result = (char *)malloc(sizeof(char) * (len + 1));
		if (result == 0)
			return (0);
		while (i < len)
			result[i++] = s[start++];
	}
	else
	{
		result = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
		if (result == 0)
			return (0);
		while (s[start])
			result[i++] = s[start++];
	}
	result[i] = 0;
	return (result);
}
