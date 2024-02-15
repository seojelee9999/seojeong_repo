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

#include "minitalk.h"

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
		exit (0);
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

int	ft_strlen(const char *s)
{
	int	cnt;

	cnt = 0;
	while (*s)
	{
		cnt++;
		s++;
	}
	return (cnt);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	flag;

	i = 0;
	flag = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		flag = 1;
		i++;
	}
	if (str[i] == '+' && flag != 1)
		i++;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (flag == 1)
		result *= -1;
	return (result);
}
