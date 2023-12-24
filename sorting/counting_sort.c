#include <stdio.h>
#define MAX 10000
void	counting_sort(int arr[], int n);

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0};
	counting_sort(arr,10);
	for (int i = 0 ; i< 10 ; i++)
		printf("%d ",arr[i]);
}
void	counting_sort(int arr[], int n)
{
	int cnt[MAX + 1]; //cnt 배열의 크기는 배열의 최댓값+1 : 배열의 값이 cnt배열의 인덱스 번호로 들어가기 때문이다.
	int tmp[MAX + 1];
	for (int i = 0; i < MAX + 1; i++)
		cnt[i] = 0;
	for (int i = 0; i < n; i++)
		cnt[arr[i]]++;
	for (int i = 0; i < MAX; i++)
		cnt[i + 1] += cnt[i];
	for (int i = n - 1; i >= 0; i--)
	{
		tmp[cnt[arr[i]] - 1] = arr[i];
		cnt[arr[i]]--;
	}
	for (int i = 0 ; i< n ;i ++)
		arr[i] = tmp[i];
}
