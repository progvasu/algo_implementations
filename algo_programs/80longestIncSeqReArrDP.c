// find the longest increasing sequence after reordering

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	srand(time(0));

	// input
	int n = 12, i, j;
	// int inp[n];
	int inp[12] = {12, 7, 10, 8, 1, 6, 5, 14, 4, 9, 10, 2};

	// state table
	int LIS[n], LDS[n];
	// backtracking table
	int pie_lis[n], pie_lds[n];

	// initializing 
	for (i = 0 ; i < n ; i++)	{
		LIS[i] = 1;
		pie_lis[i] = -1;
		LDS[i] = 1;
		pie_lds[i] = -1;
	}

	// induction
	// LIS calculation
	for (i = 1 ; i < n ; i++)	{
		for (j = 0 ; j < i ; j++)	{
			if (inp[j] <= inp[i] && (LIS[j] + 1) > LIS[i])	{
				LIS[i] = LIS[j] + 1;
				pie_lis[i] = j;
			}
		}
	}
	// LDS calculation
	for (i = n - 1 ; i >= 0 ; i--)	{
		for (j = i + 1 ; j < n ; j++)	{
			if (inp[j] <= inp[i] && (LDS[j] + 1) > LDS[i])	{
				LDS[i] = LDS[j] + 1;
				pie_lds[i] = j;
			}
		}
	}

	// print state table
	printf("INX: ");
	for (i = 0 ; i < n ; i++)
		printf("%4d", i);
	printf("\n");
	printf("INP: ");
	for (i = 0 ; i < n ; i++)
		printf("%4d", inp[i]);
	printf("\n\n");
	printf("LIS: ");
	for (i = 0 ; i < n ; i++)
		printf("%4d", LIS[i]);
	printf("\n");
	printf("PIE: ");
	for (i = 0 ; i < n ; i++)
		printf("%4d", pie_lis[i]);
	printf("\n\n");
	printf("LDS: ");
	for (i = 0 ; i < n ; i++)
		printf("%4d", LDS[i]);
	printf("\n");
	printf("PIE: ");
	for (i = 0 ; i < n ; i++)
		printf("%4d", pie_lds[i]);
	printf("\n\n");

	// result
	int max = -1, max_index = -1;
	for (i = 0 ; i < n ; i++)	{
		if (LIS[i] + LDS[i] - 1 > max)	{
			max = LIS[i] + LDS[i] - 1;
			max_index = i;
		}
	}

	printf("Length of max increasing subsequence: %d\n\n", max);

	return 0;
}