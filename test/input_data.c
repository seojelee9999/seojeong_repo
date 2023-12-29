/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:32:20 by seojelee          #+#    #+#             */
/*   Updated: 2023/12/27 11:32:22 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	input_data(int ac, char **av, t_list *list)
{
	int		i;
	int		j;
	char	**ch;

	i = 1;
	while (i < ac)
	{
		j = 0;
		ch = ft_split(av[i], 32);
		if (!ch)
			return (0);
		while (ch[j])
		{
			if (!checker(ch[j], list))
			{
				write(1, "Error\n", 6);
				exit(1);
			}
			append_last(list, ft_atoi(ch[j]));
			j++;
		}
		free_result(ch, j);
		i++;
	}
	return (1);
}

int	checker(char *av, t_list *list)
{
	long	n;
	int		flag;
	int		i;

	i = 0;
	if (av[0] == '-')
		i++;
	while (av[i])
	{
		if (!('0' <= av[i] && av[i] <= '9'))
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
	flag = 0;
	n = push_atol(av);
	if (-2147483648 <= n && n <= 2147483647)
		flag++;
	if (flag == 0)
		return (0);
	if (!check_stack(list, (int)n))
		return (0);
	return (1);
}
