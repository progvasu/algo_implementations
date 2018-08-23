// Given a rank r find the element using deterministic procedure
#include<stdio.h>

int partition(int *arr, int min, int max)	{
	int i = min + 1, temp, j, pivot;
	pivot = arr[min];

	for (j = i ; j <= max ; j++)	{
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

void sort(int *a, int min, int max)	{
	int i, j, temp;

	for (i = min ; i <= max - 1 ; i++)	{
		for (j = i + 1 ; j <= max ; j++)
			if (a[i] > a[j])	{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
	}
}

int findEle(int *, int, int, int);

int findGoodPivot(int *a, int min, int max)	{
	int i, j, temp;

	// sorting in groups of 5
	for (i = min; i < max ; i += 5)	{
		sort(a, i, i + 4);
	}

	// for base case
	if (max - min + 1 == 5)
		return a[min + 2];
	
	// testing - print out the array
	// for (i = min ; i <=max ; i++)
	//	printf("%d  ", a[i]);
	// printf("\n");
	// return 0;

	// moving medians to the front of the array
	for (i = min, j = min + 2 ; i <= max && j <= max; i++, j += 5)	{
		// swap a[i] with a[j]
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	return findEle(a, min, min + 4, 3);
}

int findEle(int *arr, int i, int j, int rank)	{
	int pivot_pos;

	pivot_pos = findGoodPivot(arr, i, j);
	
	// testing
	// return 0; 

	// swapping with the first element
	int temp = arr[pivot_pos];
	arr[pivot_pos] = arr[i];
	arr[i] = temp;

	// find the partition point
	int k;
	k = partition(arr, i, j);

	if (rank == (j - k + 1))
		return arr[k];
	else if (rank < (j - k + 1))
		findEle(arr, k + 1, j, rank);
	else
		findEle(arr, i, k - 1, rank - (j - k + 1));
}

int main()	{

		// assuming input array is multiple of 5
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24};
	int b[] = {18, 7, 12, 22, 11, 6, 0, 9, 1, 19, 20, 4, 21, 8, 23, 13, 3, 15, 14, 2, 17, 24, 5, 10, 16};
	int a_len = 25, b_len = 25, ele, rank;

	printf("Enter the rank of the element: ");
	scanf("%d", &rank);

	ele = findEle(b, 0, b_len - 1, rank);

	printf("Our Answer = %d\n", ele);
	printf("Correct Answer = %d\n", a_len - rank);
	
	return 0;
}
