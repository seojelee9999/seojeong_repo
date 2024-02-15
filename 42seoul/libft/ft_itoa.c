/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:22:04 by seojelee          #+#    #+#             */
/*   Updated: 2023/10/08 15:18:15 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	allocate_num(long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		cnt++;
	}
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		index;
	long	m;

	m = (long)n;
	index = allocate_num(m);
	result = (char *)malloc(sizeof(char) * (index + 1));
	if (result == 0)
		return (0);
	result[index] = 0;
	if (n < 0)
	{
		result[0] = '-';
		m *= -1;
	}
	if (n == 0)
		result[0] = '0';
	index--;
	while (m > 0)
	{
		result[index--] = m % 10 + '0';
		m /= 10;
	}
	return (result);
}
