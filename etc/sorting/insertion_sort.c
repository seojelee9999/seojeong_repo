#include <stdio.h>
#define SIZE 10

void insert(int arr[], int n)
{
	int i,j,tmp;
	for (i = 1 ; i< n ; i++)
	{
		tmp = arr[i];
		for (j = i - 1; j >= 0 && arr[j] >tmp;j-- )
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = tmp; 
	}

}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	
	insert(arr,SIZE);
	for (int i = 0 ; i < SIZE ; i++)
	{
		printf("%d ",arr[i]);
	}
	return 0;
}