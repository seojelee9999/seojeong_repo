/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:18:22 by seojelee          #+#    #+#             */
/*   Updated: 2023/12/28 12:18:23 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change(char *command, t_list *stack_a, t_list *stack_b)
{
	if (!ft_strcmp(command, "sa"))
		swap_top_node(stack_a);
	if (!ft_strcmp(command, "sb"))
		swap_top_node(stack_b);
	if (!ft_strcmp(command, "ss"))
	{
		swap_top_node(stack_a);
		swap_top_node(stack_b);
	}
	if (!ft_strcmp(command, "pa"))
		move_node(stack_a, stack_b);
	if (!ft_strcmp(command, "pb"))
		move_node(stack_b, stack_a);
	if (!ft_strcmp(command, "rra"))
		stack_a->head = stack_a->head->prev;
	if (!ft_strcmp(command, "rrb"))
		stack_b->head = stack_b->head->prev;
	change_extends(command, stack_a, stack_b);
	write(1, command, ft_strlen(command));
	write(1, "\n", 1);
}

void	change_extends(char *command, t_list *stack_a, t_list *stack_b)
{
	if (!ft_strcmp(command, "rrr"))
	{
		stack_a->head = stack_a->head->prev;
		stack_b->head = stack_b->head->prev;
	}
	if (!ft_strcmp(command, "ra"))
		stack_a->head = stack_a->head->next;
	if (!ft_strcmp(command, "rb"))
		stack_b->head = stack_b->head->next;
	if (!ft_strcmp(command, "rr"))
	{
		stack_a->head = stack_a->head->next;
		stack_b->head = stack_b->head->next;
	}
}
