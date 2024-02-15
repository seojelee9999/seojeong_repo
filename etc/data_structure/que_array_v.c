//백준 1158번 배열을 이용한 큐로 문제해결


#include <stdio.h>

int	front = 0;
int	rear = 0;
int	arr[5000];

void	enqueue(int n, int data) 
{
	arr[rear++ % n] = data;
}

int	dequeue(int n)
{
	return (arr[front++ % n]);
}

int is_empty()
{
	if (front == rear)
		return (1);
	return (0);
}

int main()
{
	int n,m,k,res;
	scanf("%d %d",&n, &m);
	for (int i = 0; i < n ; i++)
		enqueue(n, i+1);
	k = 0;
	printf("<");
	while (!is_empty())
	{
		res = dequeue(n);
		if (++k % m == 0)
		{
			if (is_empty())
				printf("%d",res);
			else
				printf("%d, ",res);
		}
		else
			enqueue(n,res);
	}
	printf(">");
}