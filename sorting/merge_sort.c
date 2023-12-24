#include <stdio.h>

#define SIZE 10

void merge_sort(int list[], int left, int right);
void merge(int list[], int left, int mid, int right);
int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	merge_sort(arr,0,9);
	for(int i = 0 ; i < SIZE; i++)
		printf("%d ",arr[i]);
}
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}
void merge(int list[], int left, int mid, int right)
{
	int i;
	int	j;
	int k;
	int tmp[SIZE];

	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (list[i] > list[j])
			tmp[k++] = list[j++];
		else
			tmp[k++] = list[i++];			
	}
	if (i <= mid)
	{
		while (i <= mid)
			tmp[k++] = list[i++];
	}
	else
	{
		while (j <= right)
			tmp[k++] = list[j++];
	}
	for (i = left; i <= right ; i++)
		list[i] = tmp[i];
}