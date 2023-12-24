#include <stdio.h>
#include <stdlib.h>

void	quick_sort(int list[], int start, int end);

int	main()
{
	int list[] = {1,3,5,7,9,2,4,6,8,0};
	quick_sort(list,0,9);
	for (int i = 0 ; i< 10 ;i++)
		printf("%d ",list[i]);
}
void	quick_sort(int list[], int start, int end)
{
	int	pibot;
	int	tmp;
	int	high;
	int	low;

	pibot = start;
	low = pibot + 1;
	high = end;
	if (start < end)
	{
		while (low <= high)
		{
			while (list[low] < list[pibot])
				low++;
			while (list[high] > list[pibot])
				high--;
			if (low > high)
			{
				tmp = list[pibot];
				list[pibot] = list[high];
				list[high] = tmp;
			}
			else
			{
				tmp = list[high];
				list[high] = list[low];
				list[low] = tmp;
			}
		}
		quick_sort(list, start, high -1);
		quick_sort(list, high + 1, end);
	}
}