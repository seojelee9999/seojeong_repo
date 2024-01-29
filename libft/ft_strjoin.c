/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 13:27:08 by seojelee          #+#    #+#             */
/*   Updated: 2023/10/14 16:56:05 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, char const *s2)
{
	size_t	len_sum;
	char	*result;
	size_t	i;
	size_t	r_index;

	r_index = 0;
	len_sum = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len_sum + 1));
	if (!result)
		return (0);
	i = 0;
	while (s1[i])
		result[r_index++] = s1[i++];
	i = 0;
	while (s2[i])
		result[r_index++] = s2[i++];
	result[r_index] = 0;
	return (result);
}
