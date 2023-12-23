#include <stdio.h>
#define SIZE 10

void select(int arr[], int n)
{
	int min_idx;
	int tmp;
	for (int i = 0 ; i < n -1 ; i++)
	{
		min_idx = i;
		for (int j = i + 1 ; j < n ; j++)
		{
			if (arr[min_idx] > arr[j])
			{
				min_idx = j;
			}
		}
		if (arr[i] > arr[min_idx])
		{
			tmp = arr[i];
			arr[i] = arr[min_idx];
			arr[min_idx] = tmp;
		}
	}
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	
	select(arr,SIZE);
	for (int i = 0 ; i < SIZE ; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}