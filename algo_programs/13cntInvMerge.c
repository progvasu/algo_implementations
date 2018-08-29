#include<stdio.h>

unsigned long int merge_count(int *input_array, int min, int mid, int max)	{
	int count = 0;
	int i = min, j = mid + 1, k = 0;
	int temp[max - min + 1];

	while (i <= mid && j <= max)	{
		if (input_array[i] <= input_array[j])	{
			temp[k++] = input_array[i++];
		}
		else if (input_array[i] > input_array[j])	{
			temp[k++] = input_array[j++];
			count = count + (mid - i + 1);
		}
	}

	// are elements remaining in min - mid
	while(i <= mid)	{
		temp[k++] = input_array[i++];
	}

	while(j <= max)	{
		temp[k++] = input_array[j++];
	}

	// copying array back to original array
	for (i = 0 ; i < k ; i++)	{
		input_array[min++] = temp[i];
	}

	return count;
}

unsigned long int count_inversions(int *input_array, int min, int max)	{
	if (min >= max)
		return 0;

	int mid = (min + max) / 2;
	int left_count = count_inversions(input_array, min, mid);
	int right_count = count_inversions(input_array, mid + 1, max);
	int merge_coun = merge_count(input_array, min, mid, max);

	return left_count + right_count + merge_coun;
}

int main()	{
	//int input_array[] = {1, 3, 5, 2, 4, 6};
	FILE *ptr;
	int input_array[100000], i = 0;

	ptr = fopen("./data/IntegerArray.txt", "r");

	while (!feof (ptr))	{
      fscanf (ptr, "%d", input_array + i);
      i++;
    }

    fclose (ptr);

    // calling count_inversions

    printf("%lu", count_inversions(input_array, 0, 99999));

    //for (int i = 0 ; i <= 5 ; i++)
	//	printf("%d", input_array[i]);

	return 0;
}
