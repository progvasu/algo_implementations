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
	int k1, k2, int p1, int p2, fneg, lneg;

	if (prod > 0)	{
		if (prod > result[0])	{
			result[0] = prod;
			result[left] = i;
			result[right] = j;
		}
	}
	else {
		p1 = arr[i];
		p2 = arr[j];
		k1 = i;
		k2 = j;
		while(k1 <= k2)	{
			if (arr[k1] > 0)
				k1++;
			if (arr[k2] > 0)
				k2--;
		}
	}
}

int main()	{
	srand(time(0));
	int n = 10;
	int a[n], i, j, pro, max_ele = 10;
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
			if (i < j)
				maxProduct(a, i, j - 1, result);
			i = j + 1;
		}
	}

	return 0;
}
