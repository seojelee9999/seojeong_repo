/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:37:33 by seojelee          #+#    #+#             */
/*   Updated: 2023/10/14 13:09:33 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;
	size_t	j;

	if (dst == 0 && dstsize == 0)
		return (0);
	i = 0;
	len_src = ft_strlen(src);
	j = 0;
	while (dst[i])
		i++;
	len_dest = i;
	while (src[j] && i + 1 < dstsize)
		dst[i++] = src[j++];
	dst[len_dest + j] = 0;
	if (dstsize >= len_dest)
		return (len_dest + len_src);
	return (len_src + dstsize);
}
