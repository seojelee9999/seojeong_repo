/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:13:22 by seojelee          #+#    #+#             */
/*   Updated: 2023/10/14 15:59:58 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	if ((dst == 0 && src == 0) || len == 0)
		return (dst);
	if (src > dst)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		i = len -1;
		while (i >= 0)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			if (i == 0)
				break ;
			i--;
		}
	}
	return (dst);
}
