// implementing max sum sub sequence using optimized prefix sum's

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	srand(time(0));
	int n = 10000, i, j, max = 0, sum = 0, max_ele = 100;
	int a[n + 1], left, right;

	// generating a random array of n numbers - including negatives
	for(i = 1 ; i <= n ; i++)	{
		a[i] = (rand() % max_ele) - max_ele / 2;
	}

	// random input array
	for(i = 1 ; i <= n ; i++)	{
		printf("%d  ", a[i]);
	}
	printf("\n");

	// using brute force prefix sum
	// computing all prefix sums
	int p[n + 1];
	p[0] = 0; // dummmy value
	for(i = 1 ; i <= n ; i++)
		p[i] = p[i - 1] + a[i];

	// finding max diff(pj - pi) where j > i
	i = 0;
	max = 0;
	for (j = 1 ; j <= n ; j++)	{
		if (p[j] - p[i] > max)	{
			left = i + 1;
			right = j; // including j
			max = p[j] - p[i];
		}

		if (p[j] < p[i])
			i = j;
	}

	printf("Max sum subsequence using brute force = %d\n", max);
	printf("Left = %d, Right = %d\n\n", left, right);
	//printf("Max sub seqeunce: ");
	//while(left <= right)
	//	printf("%d  ", a[left++]);
	//printf("\n\n");

	// using the optimized function
	sum = 0;
	max = 0;
	left = 1;
	int temp = left;
	for (j = 1 ; j <= n ; j++)	{
		sum = sum + a[j];
		if (sum > max)	{
			max = sum;
			right = j;
			left = temp;			
		}

		if (sum < 0)	{
			sum = 0;
			temp = j + 1;
		}
	}

	printf("Max sum using optimized version: %d\n", max);
	printf("Left  = %d, Right = %d\n", left, right);

	return 0;
}
