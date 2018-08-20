// Counting comparisons in Quick Sort implementation
// Algorithm 2 - Having median of first, middle and last as pivot

#include<stdio.h>

int partition(int *input_array, int l , int r)	{
	// choosing median of first middle and last as pivot
	int pivot;
	int i = l + 1, temp, j;

	int med_index, middle;

	middle = l + ((r - l) / 2);

	if (((input_array[l] <= input_array[middle]) && (input_array[middle] <= input_array[r])) || ((input_array[l] >= input_array[middle]) && (input_array[middle] >= input_array[r])))
		med_index = middle;
	else if (((input_array[middle] <= input_array[l]) && (input_array[l] <= input_array[r])) || ((input_array[middle] >= input_array[l]) && (input_array[l] >= input_array[r])))
		med_index = l;
	else if (((input_array[l] <= input_array[r]) && (input_array[r] <= input_array[middle])) || ((input_array[l] >= input_array[r]) && (input_array[r] >= input_array[middle])))
		med_index = r;

//	for (j = l ; j <= r ; j++)
//		printf("%d  ", input_array[j]);
//	printf("\nleft = %d, middle = %d,  right = %d, median = %d", l, middle, r, med_index);
//	printf("\nleft = %d, middle = %d,  right = %d, median = %d\n\n", input_array[l], input_array[middle], input_array[r], input_array[med_index]);

	temp = input_array[med_index];
	input_array[med_index] = input_array[l];
	input_array[l] = temp;
	pivot = input_array[l];

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
//	int input_array[] = {2, 20, 1, 15, 3, 11, 13, 6, 16, 10, 19, 5, 4, 9, 8, 14, 18, 17, 7, 12};
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

//    for (int i = 0 ; i <= 19 ; i++)
//		printf("%d", input_array[i]);

	return 0;
}

