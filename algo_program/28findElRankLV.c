// Find the element whose rank is given using the Las Vegas
// Randomized Algorithm

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int *arr, int min, int max)	{
	int i = min + 1, temp, j, pivot;
	pivot = arr[min];
	
	for(j = i ; j <= max ; j++)	{
		if (arr[j] < pivot)	{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
		}
	}

	temp = arr[i - 1];
	arr[i - 1] = arr[min];
	arr[min] = temp;

	return i - 1;
}

int findElement(int *arr, int min, int max, int rank)	{
	srand(time(0));
	// choosing a random pivot
	int pivot;
	pivot = (rand() % (max - min + 1)) + min;

	// swapping with the first element
	int temp = arr[pivot];
	arr[pivot] = arr[min];
	arr[min] = temp;

	// finding the partition point
	int k;
	k = partition(arr, min, max);

	// testing - is partition working?
	// int i;
	// printf("pivot choosen is %d\n", temp);
	// for(i = min ; i <= max ; i++)
	//	printf("%d   ", arr[i]);

	// already moved the pivot element to it's position

	// base case
	if(rank == (max - k + 1))
		return arr[k];
	else if(rank < (max - k + 1))
		findElement(arr, k + 1, max, rank);
	else
		findElement(arr, min, k - 1, rank - (max - k + 1));
}

int main()	{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b[] = {7, 6, 0, 9, 1, 4, 8, 3, 2, 5, 10};
	int a_len = 11, b_len = 11, i, rank, ele;

	printf("Enter the rank of the element we wish to find: ");
	scanf("%d", &rank);

	ele = findElement(b, 0, 10, rank);

	printf("Correct Answer = %d\n", a[a_len - rank]);
	printf("Calculated Answer = %d\n", ele);
	
	return 0;
}
