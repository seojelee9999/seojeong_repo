/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:23:22 by seojelee          #+#    #+#             */
/*   Updated: 2023/12/28 12:23:23 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_node(t_list *list1, t_list *list2)
{
	if (list2->size == 0)
		return ;
	append_first(list1, list2->head->data, list2->head->idx);
	del_node(list2);
}

void	del_node(t_list *list)
{
	t_node	*tmp;

	tmp = list->head;
	list->head->prev->next = list->head->next;
	list->head->next->prev = list->head->prev;
	list->head = list->head->next;
	(list->size)--;
	free(tmp);
}

int	check_stack(t_list *list, int n)
{
	int		i;
	int		flag;
	t_node	*tmp;

	i = 0;
	flag = 0;
	tmp = list->head;
	while (i < list->size)
	{
		if (n == tmp->data)
			flag = 1;
		tmp = tmp->next;
		i++;
	}
	if (flag == 1)
		return (0);
	else
		return (1);
}

void	free_node(t_list *list)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (i < list->size)
	{
		tmp = list->head;
		list->head = list->head->next;
		free(tmp);
	}
}

void	make_sequence(t_list *list)
{
	t_node	*tmp_i;
	t_node	*tmp_j;
	int		i;
	int		j;

	i = 0;
	tmp_i = list->head;
	while (i < list->size)
	{
		tmp_i->idx = 0;
		i++;
		tmp_i = tmp_i->next;
	}
	i = 0;
	tmp_i = list->head;
	while (i < list->size)
	{
		j = 0;
		tmp_j = list->head;
		while (j < list->size)
		{
			if (tmp_i->data > tmp_j->data)
				(tmp_i->idx)++;
			tmp_j = tmp_j->next;
			j++;
		}
		tmp_i = tmp_i->next;
		i++;
	}
}
