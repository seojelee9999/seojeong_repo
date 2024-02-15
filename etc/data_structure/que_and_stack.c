//12789번 스택과 큐를 이용하여 구현

#include <stdio.h>
#include <stdlib.h>
int stack[1000];
int	top = -1;

typedef struct s_node{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
}	t_node;

typedef struct s_list{
	t_node	*head;
	int		size;
}	t_list;
void	append_last(t_list *list, int data);
void	enqueue(t_list *list, int data);
t_node	*create_node(int data);
void	free_first_node(t_list *list);
int		dequeue(t_list *list);
int		pop();
void	push(int n);
int		is_empty();
int main()
{
	int	n;
	int cnt;
	int	m;

	cnt = 1;
	scanf("%d", &n);

	t_list *list;
	list = (t_list *)malloc(sizeof(t_list));
	list->size = 0;
	for (int i = 0 ; i < n ; i++)
	{
		scanf("%d",&m);
		enqueue(list, m);
	}
	int tmp;
	while (list->size)
	{
		if (!is_empty()) //스택차있으면 검사
		{
			if (stack[top] == cnt)//스택에 해당값 존재하는경우
			{
				cnt++;
				pop();
			}
			else
			{
				tmp = dequeue(list);
				if (tmp == cnt)//큐에 존재하는경우
				{
					cnt++;
				}
				else
				{
					push(tmp); //스택에넣기
				}
			}
		}
		else //스택 비어있음
		{
			tmp = dequeue(list);
			if (tmp == cnt)
			{
				cnt++;
			}
			else
			{
				push(tmp);
			}
		}
	}
	if (cnt == n+1)
	{
		printf("Nice");
		return (0);
	}
	while (top != -1)
	{
		if (cnt != pop())
		{
			printf("Sad");
			return (0);
		}
		cnt++;
	}
	printf("Nice");
}
void	free_first_node(t_list *list)
{
	t_node *tmp;

	tmp = list->head;
	list->head->prev->next = list->head->next;
	list->head->next->prev = list->head->prev;
	list->head = list->head->next;
	free(tmp);
	list->size--;
}

void	enqueue(t_list *list, int data)
{
	append_last(list, data);
}


int	dequeue(t_list *list)
{
	int res;

	res = list->head->data;
	free_first_node(list);
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
void	append_last(t_list *list, int data)
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
	list->size++;
}
int pop()
{
	return (stack[top--]);
}

void	push(int n)
{
	stack[++top] = n;
}
int		is_empty()
{
	if (top == -1)
		return (1);
	return (0);
}