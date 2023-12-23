#include <stdio.h>
#define SIZE 10
void bubble(int arr[], int n)
{
	int tmp;
	for (int i = 0 ; i < n -1 ; i++)
	{
		for (int j =0 ; j < n-1 -i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	
	bubble(arr,SIZE);
	for (int i = 0 ; i < SIZE ; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}