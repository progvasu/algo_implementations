// longest increasing subsequence for a given sequence
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	srand(time(0));
	// srand(5);

	// input
	int n = 12;
	// int inp[n];
	int inp[12] = {12, 7, 10, 8, 1 ,6, 5, 14, 4, 9, 10, 2};
	int i, j;

	// random input
	// for(i = 0 ; i < n ; i++)	{
	// 	inp[i] = rand() % 30;
	// }

	// state table
	int LIS[n];
	// backtracking table
	int pie[n];

	// initialization
	for (i = 0 ; i < n ; i++)	{
		LIS[i] = 1;
		pie[i] = -1;
	}

	// induction
	for (i = 1 ; i < n ; i++)	{
		for (j = 0 ; j < i ; j++)	{
			if (inp[j] <= inp[i] && (LIS[j] + 1) > LIS[i])	{
				LIS[i] = LIS[j] + 1;
				pie[i] = j;
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
	printf("\n");
	printf("LIS: ");
	for (i = 0 ; i < n ; i++)
		printf("%4d", LIS[i]);
	printf("\n");
	printf("PIE: ");
	for (i = 0 ; i < n ; i++)
		printf("%4d", pie[i]);
	printf("\n\n");

	// result
	int max = -1, max_index = -1;
	for (i = 0 ; i < n ; i++)	{
		if (LIS[i] > max)	{
			max = LIS[i];
			max_index = i;
		}
	}

	printf("Length of max increasing subsequence: %d\n\n", max);

	// backtracking
	i = max_index;

	// easy to find the increasing order
	printf("Max increasing subsequence (in decreasing order!): ");
	while (i != -1)	{
		printf("%4d", inp[i]);
		i = pie[i];
	}
	printf("\n");

	return 0;
}