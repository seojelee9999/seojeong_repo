#include <stdio.h>

void q_sort(int arr[], int start, int end) {
    if (start >= end) return; // Base case

    int pivot = arr[start]; // Choose the first element as the pivot
    int low = start + 1;
    int high = end;

    while (low <= high) {
        while (low <= end && arr[low] < pivot) low++;
        while (high > start && arr[high] > pivot) high--;

        if (low < high) {
            // Swap arr[low] and arr[high]
            int tmp = arr[low];
            arr[low] = arr[high];
            arr[high] = tmp;
        } else {
            break;
        }
    }

    // Swap arr[start] (pivot) with arr[high]
    int tmp = arr[start];
    arr[start] = arr[high];
    arr[high] = tmp;

    // Recursively sort the two partitions
    q_sort(arr, start, high - 1);
    q_sort(arr, high + 1, end);
}

int main()
{
	int arr[] = {1,3,5,7,9,2,4,6,8,0,42};
	q_sort(arr, 0, 10);
	for (int i = 0; i < 11; i++)
		printf("%d ", arr[i]);
}