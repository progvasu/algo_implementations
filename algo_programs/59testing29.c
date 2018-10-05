// testing program 29
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
		// just sort the numbers and return the mid element
		sort(a, min, max);

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

	// find pivot position
	for (k = i ; k <= j ; k++)	{
		if (pivot_ele == arr[k])	{
			pivot_pos = k;
			break;
		}
	}

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
		findEle(arr, i, k - 1, rank - (j - k + 1));
	}
}

int main()	{
	srand(time(0));

	// number of tests to be carried out
	int iter = 1000000;

	// random size of random aray
	int n, i = 0, rank, our_ans, correct_ans;

	while (iter--)	{
		// always bigger than 10 - max size 60 
		n = 10 + rand() % 51;

		// define array of this size
		int a[n];

		// populate array
		for(i = 0 ; i < n ; i++)
			a[i] = rand() % 1000;

		// choosing random value of rank to be found
		rank = 1 + rand() % n;

		our_ans = findEle(a, 0, n - 1, rank);

		// sort a
		sort(a, 0, n - 1);
		correct_ans = a[n - rank];

		if (our_ans != correct_ans)	{
			for(i = 0 ; i < n ; i++)	{
				printf("%d ", a[i]);
			}
			printf("\n");
			printf("Our ans = %d, Correct ans = %d\n", our_ans, correct_ans);
			break;
		}
		else	{
			printf("I: ");
			for(i = 0 ; i < n ; i++)	{
				printf("%d ", a[i]);
			}
			printf("\n");
			printf("Rank = %d, Our ans = %d, Correct ans = %d\n\n", rank, our_ans, correct_ans);
		}
	}

	return 0;
}