// A rank is given we are supposed to find the element which has that rank 'r'
// Method 1 - By Sorting

#include<stdio.h>

void merge(int *arr, int left, int mid, int right)	{
	int temp[right - left + 1], k = 0, i = left, j = mid + 1;

	while(i <= mid && j <= right)	{
		if (arr[i] <= arr[j])	{
			temp[k++] = arr[i++];
		}
		else	{
			temp[k++] = arr[j++];
		}
	}

	while(i <= mid)	{
		temp[k++] = arr[i++];
	}

	while(j <= right)	{
		temp[k++] = arr[j++];
	}

	// copying elements back to the original array
	for(i = 0 ; i < k ; i++)
		arr[left++] = temp[i];
}

void mergesort(int *arr, int i, int j)	{
	if (i >= j)
		return;
	int mid;
	mid = (i + j) / 2;
	mergesort(arr, i, mid);
	mergesort(arr, mid + 1, j);
	merge(arr, i, mid, j);
}

int main()	{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int b[] = {7, 6, 0, 9, 1, 4, 8, 3, 2, 5};
	int a_len = 10, b_len = 10, i, rank, ele;

	printf("Enter the rank to find the element: ");
	scanf("%d", &rank);

	// sorting the input list - using merge sort
	mergesort(b, 0, 9);
	// testing - printing sorting array
	// for (i = 0 ; i < b_len ; i++)
	//	printf("%d  ", b[i]);

	// rank in sorted array a
	printf("Element in a is %d\n", a_len - rank);

	// rank in b 
	printf("Element in b is %d\n", b_len - rank);

	return 0;
}
