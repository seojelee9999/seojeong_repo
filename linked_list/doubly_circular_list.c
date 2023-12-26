#include <stdio.h>
#include <stdlib.h>
typedef struct s_node{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
} t_node;

typedef struct s_list{
	t_node	*head;
	int		size;
} t_list;

t_node	*new_node(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->next = new;
	new->prev = new;
	new->data = data;
	return (new);
}
t_list	*new_list()
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return 0;
	new->head = 0;
	new->size = 0;
	return (new);
}

void append_node(t_list *list, int data)
{
	t_node	*node;

	node = new_node(data);
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

void	swap_top_node(t_list *list) //sa//sb//ss
{
	int tmp;
	tmp = list->head->prev->data;
	list->head->prev->data = list->head->prev->prev->data;
	list->head->prev->prev->data = tmp;
}
void	del_node(t_list *list)
{
	t_node *tmp;
	
	tmp = list->head->prev;
	list->head->prev->prev->next = list->head;
	list->head->prev = list->head->prev->prev;
	(list->size)--;
	free(tmp);
}

void	move_node(t_list *list1, t_list *list2)//pa pb
{
	if (list2->size == 0)
		return ;
	append_node(list1, list2->head->prev->data);
	del_node(list2);
}

int main()
{
	t_list *list1, *list2;
	list1 = new_list();
	list2 = new_list();
	append_node(list1,4);
	append_node(list1,5);
	append_node(list1,6);
	append_node(list1,7);
	printf("%d\n",list1->head->data);
	printf("%d\n",list1->head->next->data);
	printf("%d\n",list1->head->next->next->data);
	printf("%d\n",list1->head->prev->data);
	move_node(list2,list1);
	move_node(list2,list1);
	move_node(list2,list1);
	printf("%d\n",list2->head->data);
	printf("%d\n",list2->head->next->data);
	printf("%d\n",list2->head->next->next->data);
	printf("%d\n",list2->head->prev->data);
}