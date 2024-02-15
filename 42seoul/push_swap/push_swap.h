/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojelee <seojelee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:21:50 by seojelee          #+#    #+#             */
/*   Updated: 2023/12/28 12:21:51 by seojelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
	int				idx;
}	t_node;

typedef struct s_list{
	t_node	*head;
	int		size;
}	t_list;
t_node	*new_node(int data);
t_list	*new_list(void);
int		append_last(t_list *list, int data);
int		append_first(t_list *list, int data, int idx);
void	swap_top_node(t_list *list);
void	del_node(t_list *list);
int		move_node(t_list *list1, t_list *list2);
int		input_data(int ac, char **av, t_list *list);
int		checker(char *av, t_list *list);
int		check_stack(t_list *list, int n);
char	**ft_split(char const *s, char c);
int		allocate(char **result, char const *s, char c);
int		free_result(char **result, int r_index);
void	r_write(char *result, char const *s, int start, int i);
int		num_words(char const *s, char c);
long	push_atol(const char *str);
int		ft_atoi(const char *str);
int		change(char *command, t_list *stack_a, t_list *stack_b);
void	free_node(t_list *list);
int		ft_strlen(char *ch);
void	change_extends(char *command, t_list *stack_a, t_list *stack_b);
int		sorting(t_list *stack_a, t_list *stack_b, int ac);
int		hard_coding(t_list *a, t_list *b);
void	make_sequence(t_list *list);
int		ft_strcmp(char *a, char *b);
#endif
