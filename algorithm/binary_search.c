#include <stdio.h>

int binary_search(int data[], int n, int key)
{
	int high,low,mid;
	low = 0;
	high = n -1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (data[mid] == key)
			return (mid);
		else if (data[mid] >= key)
			high = mid - 1;
		else if (data[mid] <= key)
			low = mid + 1;
	}
	return (-1);
}
int main()
{
	int arr[] = {2,4,6,8,10,12,14,17,20,50};
	printf("%d",binary_search(arr, 10, 49));
}