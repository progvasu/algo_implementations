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

	// base case - if the number of elements are less than 5
	if (max - min + 1 <= 5)	{
		// just sort the numbers and return the mid element
		sort(a, min, max);

		// testing
		//printf("Middle element = %d\n", a[min + (max - min) / 2]);

		// return the middle element
		return a[min + (max - min) / 2];
	}

	// sorting in groups of 5
	for (i = min ; i + 4 <= max ; i = i + 5)	{
		sort(a, i, i + 4);
	}
	// sorting remaining element group (< 5) if any
	if (i < max)
		sort(a, i, max);

	// testing - print out the array
	//for (i = min ; i <= max ; i++)
	//	printf("%d  ", a[i]);
	//	printf("\n");
	 	//return 0;

	// moving medians to the front of the array
	for (i = min, j = min + 2 ; j <= max; i++, j += 5)	{
		// swap a[i] with a[j]
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	// testing - print out the array
	//for (i = min ; i <= max ; i++)
	//	printf("%d  ", a[i]);
	//	printf("\n");
	// 	return 0;

	return findEle(a, min, min + i - 1, (i - 1)/2); // check this
}

int findEle(int *arr, int i, int j, int rank)	{
	int pivot_pos;

	// finding good pivot position
	pivot_pos = findGoodPivot(arr, i, j);

	// testing
	//return 0;

	// swapping with the first element
	int temp = arr[pivot_pos];
	arr[pivot_pos] = arr[i];
	arr[i] = temp;

	// find the partition point
	int k;
	k = partition(arr, i, j);

	if (rank == (j - k + 1))
		return k;
	else if (rank < (j - k + 1))
		findEle(arr, k + 1, j, rank);
	else
		findEle(arr, i, k - 1, rank - (j - k + 1));
}

int main()	{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
	int b[] = {4, 3, 5, 0, 2, 1, 7, 6};
	int a_len = 8, b_len = 8, pos, rank;

	printf("Enter the rank of the element: ");
	scanf("%d", &rank);

	pos = findEle(b, 0, b_len - 1, rank);

	printf("Our Answer = %d\n", b[pos]);
	printf("Correct Answer = %d\n", a_len - rank);

	return 0;
}
