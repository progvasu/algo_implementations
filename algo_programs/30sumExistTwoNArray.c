// Given a number x find two numbers in the given array such that ai + aj = x - Sorting using quick sort

#include<stdio.h>

int partition(int *arr, int min, int max)	{
	int pivot = arr[min];
	int i, j, temp;
	i = min + 1;
	j = min + 1;

	for (j ; j <= max ; j++)	{
		if (arr[j] < pivot)	{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
		}
	}

	// swap pivot in it's correct pos
	temp = arr[min];
	arr[min] = arr[i - 1];
	arr[i - 1] = temp;

	return i - 1;
}

void quicksort(int *arr, int min, int max)	{
	int pivot_pos;
	
	// base case
	if (min >= max)
		return;

	// assuming first element to be the pivot element
	pivot_pos = partition(arr, min, max);

	quicksort(arr, min, pivot_pos - 1);
	quicksort(arr, pivot_pos + 1, max);
}

int main()	{
	int arr[] = {10, 2, 5, 1, 9, 4, 7, 8, 6, 3};
	int arr_len = 9, x;

	printf("Enter the sum to be found: ");
	scanf("%d", &x);

	// sorting array using quick sort
	quicksort(arr, 0, 9);

	// testing
	int i;
	printf("Sorted Array: ");
	for (i = 0 ; i <= arr_len ; i++)	{
		printf("%d  ", arr[i]);
	}
	printf("\n");

	// logic for finding the two numbers
	int l = 0, r = arr_len;
	while (l <= r)	{
		if (arr[l] + arr[r] == x)	{
			printf("Numbers are: %d %d\n", arr[l], arr[r]);
			break;
		}
		else if (arr[l] + arr[r] < x)	{
			l++;
		}
		else
			r--;
	}

	if (l > r)
		printf("No such numbers exist in the input array\n");

	return 0;
}
