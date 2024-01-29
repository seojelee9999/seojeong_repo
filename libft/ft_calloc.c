/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:49:33 by seojelee          #+#    #+#             */
/*   Updated: 2023/10/14 13:12:11 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*result;
	size_t			i;

	i = 0;
	result = (unsigned char *)malloc(count * size);
	if (result == 0)
		return (0);
	while (i < count * size)
	{
		result[i] = 0;
		i++;
	}
	return ((void *) result);
}
