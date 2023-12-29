/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:22:03 by seojelee          #+#    #+#             */
/*   Updated: 2023/12/28 12:22:03 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_list *stack_a, t_list *stack_b, int ac)
{
	if (ac == 2)
	{
		if (stack_a->head->idx == 1 && stack_a->head->next->idx == 0)
			change("sa", stack_a, stack_b);
	}
	else if (ac == 3)
		hard_coding_3(stack_a, stack_b);
	else if (ac == 5)
		hard_coding_5(stack_a, stack_b);
}

void	hard_coding_3(t_list *a, t_list *b)
{
	int		max_idx;
	int		min_idx;

	make_sequence(a);
	min_idx = search_want_idx(a, 0);
	max_idx = search_want_idx(a, 2);
	if ((max_idx == 1 && min_idx == 0) || (max_idx == 0 && min_idx == 2))
	{
		if (max_idx == 1)
			change("rra", a, b);
		else
			change("ra", a, b);
		change("sa", a, b);
	}
	else if (max_idx == 1 && min_idx == 2)
		change("rra", a, b);
	else if (max_idx == 2 && min_idx == 1)
		change("sa", a, b);
	else if (max_idx == 0 && min_idx == 1)
		change("ra", a, b);
}

void	hard_coding_5(t_list *a, t_list *b)
{
	int	i;
	int	j;

	j = 0;
	while (j++ < 2)
	{
		i = search_want_idx(a, j - 1);
		if (i > a->size / 2)
			while (i++ < a->size)
				change("rra", a, b);
		else
			while (i-- > 0)
				change("ra", a, b);
		change("pb", a, b);
	}
	hard_coding_3(a, b);
	change("pa", a, b);
	change("pa", a, b);
	make_sequence(a);
}