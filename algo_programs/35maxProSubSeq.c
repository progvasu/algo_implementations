// Find the subsequence whose product is maximum

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int product(int *arr, int l, int r)	{
	int result = 1;
	while(l <= r)
		result *= arr[l++];

	return result;
}

void maxProduct(int *arr, int i, int j, int *result)	{ // j including
	int prod = product(arr, i, j);
	int k1, k2, p1, p2;

	if (prod > 0)	{
		if (prod > result[0])	{
			result[0] = prod;
			result[1] = i;
			result[2] = j;
		}
	}
	else {
		k1 = i;
		k2 = j;
		while(arr[k1] > 0)
			k1++;
		while(arr[k2] > 0)
			k2--;
		p1 = product(arr, i, k1);
		p2 = product(arr, k2, j);
		if (p1 > p2)	{
			if ((prod / p1) > result[0])	{
				result[0] = prod / p1;
				result[1] = k1 + 1;
				result[2] = j;
			}
		}
		else	{
			if ((prod / p2) > result[0])	{
				result[0] = prod / p2;
				result[1] = i;
				result[2] = k2 - 1;
			}
		}
	}
}

int main()	{
	srand(time(0));
	int n = 10;
	int a[n], i, j, pro, max_ele = 10, not_zero = 1;
	int result[] = {0, 0, 0}; // max, left, right
	
	// randomly initialize an array
	for(i = 0 ; i < n ; i++)
		a[i] = (rand() % max_ele) - max_ele / 3;	

	// input random array
	for(i = 0 ; i < n ; i++)
		printf("%d ", a[i]);
	printf("\n\n");

	// breaking on the breakpoints
	i = 0;
	for(j = 0 ; j < n ; j++)	{
		// found a breakpoint
		if (a[j] == 0)	{
			not_zero = 0;
			if (i < j)
				maxProduct(a, i, j - 1, result);
			i = j + 1;
		}
	}

	// if no element is zero then
	if (not_zero == 1)
		maxProduct(a, 0, n - 1, result);
	else	{
		// for last subsequence after breakpoint zero
		if (i <= n - 1)
			maxProduct(a, i, n - 1, result);
	}

	// printing result
	printf("Maximum product is %d\n", result[0]);
	printf("Left index = %d\tRight Index = %d\n", result[1], result[2]);

	return 0;
}
