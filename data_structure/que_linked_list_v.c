//백준 1158번 링크드리스트를 이용한 큐로 문제해결

#include <stdio.h>
#include <stdlib.h>

typedef struct s_node{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
}	t_node;

typedef struct s_list{
	t_node	*head;
	int		size;
}	t_list;
void	append_first(t_list *list, int data);
void	enqueue(t_list *list, int data);
t_node	*create_node(int data);
void	free_last_node(t_list *list);
int		dequeue(t_list *list);

int main()
{
	t_list	*list;
	int		n;
	int		m;
	int		k;

	list = (t_list *)malloc(sizeof(t_list));
	list->size = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		enqueue(list, i + 1);
	k = 0;
	printf("<");
	while (list->size != 0)
	{
		k = 0;
		while (k++ < m - 1)
			list->head = list->head->prev;
		if (list->size != 1)
			printf("%d, ",dequeue(list));
		else
			printf("%d>",dequeue(list));
	}
}

void	free_last_node(t_list *list)
{
	t_node *tmp;

	if (list->size == 0)
	{
		free(list);
		return ;
	}
	tmp = list->head->prev;
	list->head->prev->prev->next = list->head;
	list->head->prev = list->head->prev->prev;
	free(tmp);
	list->size--;
}

void	enqueue(t_list *list, int data)
{
	append_first(list, data);
}


int	dequeue(t_list *list)
{
	int res;

	res = list->head->prev->data;
	free_last_node(list);
	return (res);
}

t_node	*create_node(int data)
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	new->next = new;
	new->prev = new;
	new->data = data;
	return (new);
}
void	append_first(t_list *list, int data)
{
	t_node *new;

	new = create_node(data);
	if (list->head == 0)
	{
		list->head = new;
		list->size++;
		return ;
	}
	new->next = list->head;
	new->prev = list->head->prev;
	list->head->prev->next = new;
	list->head->prev = new;
	list->head = new;
	list->size++;
}
