/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 11:32:40 by seojelee          #+#    #+#             */
/*   Updated: 2023/12/27 11:32:41 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->next = new;
	new->prev = new;
	new->data = data;
	new->idx = 0;
	return (new);
}

t_list	*new_list(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->head = 0;
	new->size = 0;
	return (new);
}

void	append_first(t_list *list, int data, int idx)
{
	t_node	*node;

	node = new_node(data);
	if (!node)
		exit(-1);
	node->idx = idx;
	if (list->head == 0)
		list->head = node;
	else
	{
		node->next = list->head;
		node->prev = list->head->prev;
		list->head->prev->next = node;
		list->head->prev = node;
		list->head = node;
	}
	(list->size)++;
}

void	append_last(t_list *list, int data)
{
	t_node	*node;

	node = new_node(data);
	if (!node)
		exit(-1);
	if (list->head == 0)
		list->head = node;
	else
	{
		node->next = list->head;
		node->prev = list->head->prev;
		list->head->prev->next = node;
		list->head->prev = node;
	}
	(list->size)++;
}

void	swap_top_node(t_list *list)
{
	int	tmp;

	tmp = list->head->data;
	list->head->data = list->head->next->data;
	list->head->next->data = tmp;
	tmp = list->head->idx;
	list->head->idx = list->head->next->idx;
	list->head->next->idx = tmp;
}
