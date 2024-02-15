/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:39:58 by seojelee          #+#    #+#             */
/*   Updated: 2023/10/13 19:49:38 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char n, int fd)
{
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			if (n == -2147483648)
			{
				write(fd, "2147483648", 10);
				return ;
			}
			n *= -1;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			n %= 10;
		}
		if (n < 10)
		{
			ft_putchar(n + '0', fd);
		}
	}
}
