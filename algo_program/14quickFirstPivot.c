// Counting comparisons in Quick Sort implementation
// Algorithm 1 - Having 1st element as pivot

#include<stdio.h>

int partition(int *input_array, int l , int r)	{
	// choosing first element as pivot
	int pivot = input_array[l];
	int i = l + 1, temp, j;
	for (j = i ; j <= r ; j++)	{
		if (input_array[j] < pivot)	{
			temp = input_array[i];
			input_array[i] = input_array[j];
			input_array[j] = temp;
			i++;
		}
	}

	temp = input_array[l];
	input_array[l] = input_array[i - 1];
	input_array[i - 1] = temp;

	return i - 1;
}

long int count_comparisons(int *input_array, int l, int r)	{
	if (l >= r)	return 0;

	int p = partition(input_array, l, r);
	int left = count_comparisons(input_array, l, p - 1);
	int right = count_comparisons(input_array, p + 1, r);

	return (r - l) + left + right;
}

int main()	{
	// int input_array[] = {1, 3, 5, 2, 4, 6};
	FILE *ptr;
	int input_array[10000], i = 0;
	ptr = fopen("./data/QuickSort.txt", "r");

	while (!feof (ptr))	{
      fscanf (ptr, "%d", input_array + i);
      i++;
    }

    fclose (ptr);

    // calling count_inversions

    printf("%lu\n", count_comparisons(input_array, 0, 9999));

    //for (int i = 0 ; i <= 5 ; i++)
	//	printf("%d", input_array[i]);

	return 0;
}
