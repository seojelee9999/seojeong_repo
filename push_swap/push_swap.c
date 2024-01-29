/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:20:51 by seojelee          #+#    #+#             */
/*   Updated: 2023/12/28 12:20:52 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_node	*tmp;

	if (ac == 1)
		return (0);
	stack_a = new_list();
	if (!stack_a)
		return (0);
	stack_b = new_list();
	if (!stack_b)
		return (0);
	if (!input_data(ac, av, stack_a))
		exit(1);
	make_sequence(stack_a);
	if (!sorting(stack_a, stack_b, stack_a->size))
		return (0);
	tmp = stack_a->head;
}
