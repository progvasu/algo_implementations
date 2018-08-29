// Find max(aj - ai) where j > i - Given a sequence of n numbers

#include<stdio.h>

int main()	{
	int arr[] = {11, 22, 15, 18, 34, 21, 17, 25, 10, 26};
	int arr_len = 10, max = 0, i, j;
	
	i = 0;
	for (j = 1 ; j < arr_len ; j++)	{
		if (arr[j] - arr[i] > max)
			max = arr[j] - arr[i];
		if (arr[j] < arr[i])
			i = j;
	}

	printf("Maximum difference = %d\n", max);

	return 0;
}
