/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:30:26 by seojelee          #+#    #+#             */
/*   Updated: 2023/10/06 13:39:25 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		cnt;
	char	*result;

	result = 0;
	cnt = 0;
	while (s[cnt])
		cnt++;
	i = 0;
	while (i <= cnt)
	{
		if (s[i] == (char)c)
			result = (char *)s + i;
		i++;
	}
	return (result);
}
