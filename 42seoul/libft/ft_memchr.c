/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:44:37 by seojelee          #+#    #+#             */
/*   Updated: 2023/10/14 14:48:16 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*tmp_s;
	size_t				i;

	tmp_s = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (tmp_s[i] == (unsigned char)c)
		{
			tmp_s += i;
			return ((void *)tmp_s);
		}
		i++;
	}
	return (0);
}
