/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 12:52:09 by seojelee          #+#    #+#             */
/*   Updated: 2023/12/29 12:52:10 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	search_want_idx(t_list *stack_a, int idx)
{
	int		i;
	t_node	*tmp;

	tmp = stack_a->head;
	i = 0;
	while (i < stack_a->size)
	{
		if (tmp->idx == idx)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int	search_min_idx(t_list *stack_a)
{
	int		i;
	int		min;
	t_node	*tmp;

	tmp = stack_a->head;
	i = 0;
	min = tmp->idx;
	while (i < stack_a->size)
	{
		if (tmp->idx < min)
			min = tmp->idx;
		i++;
		tmp = tmp->next;
	}
	return (min);
}

int	search_max_idx(t_list *stack_a)
{
	int		i;
	int		max;
	t_node	*tmp;

	tmp = stack_a->head;
	i = 0;
	max = tmp->idx;
	while (i < stack_a->size)
	{
		if (tmp->idx > max)
			max = tmp->idx;
		i++;
		tmp = tmp->next;
	}
	return (max);
}

int	already_sort(t_list *stack_a)
{
	t_node	*tmp;
	int		i;

	tmp = stack_a->head;
	i = 0;
	while (i < stack_a->size)
	{
		if (tmp->idx != i)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}
