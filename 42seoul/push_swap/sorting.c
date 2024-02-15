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

int	sorting(t_list *stack_a, t_list *stack_b, int ac)
{
	if (ac == 2)
		if (stack_a->head->idx == 1 && stack_a->head->next->idx == 0)
			change("sa", stack_a, stack_b);
	if (ac == 3)
		if (!hard_coding(stack_a, stack_b))
			return (0);
	return (1);
}

int	hard_coding(t_list *a, t_list *b)
{
	t_node	*tmp;

	tmp = a->head;
	if (tmp->idx == 0 && tmp->next->idx == 2 && tmp->prev->idx == 1)
	{
		change("rra", a, b);
		change("sa", a, b);
	}
	else if (tmp->idx == 1 && tmp->next->idx == 2 && tmp->prev->idx == 0)
		change("rra", a, b);
	else if (tmp->idx == 1 && tmp->next->idx == 0 && tmp->prev->idx == 2)
		change("sa", a, b);
	else if (tmp->idx == 2 && tmp->next->idx == 0 && tmp->prev->idx == 1)
		change("ra", a, b);
	else if (tmp->idx == 2 && tmp->next->idx == 1 && tmp->prev->idx == 0)
	{
		change("ra", a, b);
		change("sa", a, b);
	}
	return (1);
}
