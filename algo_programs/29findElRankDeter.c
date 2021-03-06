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

	for (i = min ; i <= max - 1; i++)	{
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
		printf("reached\n");
		// just sort the numbers and return the mid element
		sort(a, min, max);

		// testing
		printf("Middle element = %d\n", a[min + (max - min) / 2]);

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

	// moving medians to the front of the array
	for (i = min, j = min + 2 ; j <= max; i++, j += 5)	{
		// swap a[i] with a[j]
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}

	// testing - print out the array
	printf("S: ");
	for (temp = min ; temp <= max ; temp++)
		printf("%d  ", a[temp]);
	printf("\n");
	// return 0;

	// testing - print out the array
	// for (i = min ; i <= max ; i++)
	// 	printf("%d  ", a[i]);
	// printf("\n");
	// return 0;

	printf("%d - %d - %d\n", min, min + i - 1, (i - 1)/2 + 1);
	// return 0;

	return findEle(a, min, min + i - 1, (i - 1)/2 + 1);
}

int findEle(int *arr, int i, int j, int rank)	{
	int pivot_pos, pivot_ele, k;

	// finding a good pivot position
	// this should not change my original array - messes up with recursive calls
	// create a copy of arr
	int arr_copy[j - i + 1], ind = 0;
	for (k = i ; k <= j ; k++)
		arr_copy[ind++] = arr[k];

	pivot_ele = findGoodPivot(arr_copy, 0, ind - 1);

	// testing pivot ele
	printf("Pivot ele: %d\n", pivot_ele);

	// find pivot position
	for (k = i ; k <= j ; k++)	{
		if (pivot_ele == arr[k])	{
			pivot_pos = k;
			break;
		}
	}

	// testing
	// return pivot_pos;

	// swapping with the first element
	int temp = arr[pivot_pos];
	arr[pivot_pos] = arr[i];
	arr[i] = temp;

	// find the partition point
	k = partition(arr, i, j);

	if (rank == (j - k + 1))
		return arr[k];
	else if (rank < (j - k + 1))
		findEle(arr, k + 1, j, rank);
	else	{
		printf("recur: %d - %d - %d\n", i, k - 1, rank - (j - k + 1));
		findEle(arr, i, k - 1, rank - (j - k + 1));
	}
}


int main()	{
	// int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
	// int b[] = {4, 3, 5, 0, 2, 1, 7, 6};
	// int a_len = 8, b_len = 8, pos, rank;

	int a[] = {5, 8, 14, 15, 26, 27, 31, 34, 39, 41, 47, 53, 59, 61, 63, 74, 76, 87, 88, 92, 99, 100};
	int b[] = {76, 63, 34, 27, 100, 41, 87, 59, 92, 5, 14, 39, 8, 47, 26, 15, 88, 53, 61, 74, 99, 31};
	int a_len = 22, b_len = 22, pos, rank;
	int i;

	printf("Enter the rank of the element: ");
	scanf("%d", &rank);

	printf("I: ");
	for (i = 0 ; i < b_len ; i++)
		printf("%d  ", b[i]);
	printf("\n");

	pos = findEle(b, 0, b_len - 1, rank);

	// testing - print array b
	printf("B: ");
	for (i = 0 ; i < b_len ; i++)
		printf("%d  ", b[i]);
	printf("\n");

	printf("Our Answer = %d\n", pos);
	printf("Correct Answer = %d\n", a[a_len - rank]);

	return 0;
}
