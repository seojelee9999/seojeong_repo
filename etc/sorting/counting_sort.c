#include <stdio.h>

void	count_sort(int list[], int n, int max_num)
{
	int cnt[max_num + 1];
	int tmp[n];
	for (int i = 0 ; i< max_num + 1; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++)
		cnt[list[i]]++;
	for (int i = 0; i < max_num; i++)
		cnt[i + 1] += cnt[i];
	for (int i = n - 1; i >= 0; i--)
	{
		tmp[cnt[list[i]] - 1] = list[i];
		cnt[list[i]]--;
	}
	for (int i = 0 ; i< n; i++)
		list[i] = tmp[i];
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	count_sort(arr,10,9);
	for (int i = 0; i < 10; i++)
		printf("%d ",arr[i]);
}