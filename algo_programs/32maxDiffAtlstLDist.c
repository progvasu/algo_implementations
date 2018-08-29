// Find max(aj - ai) where j >= i + l i.e. wait for atleast l days before selling a stock

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	srand(time(0));
	int a[30], max_ele = 100, i, j, l, max = 0, n = 30;

	// generate 30 random numbers
	for (i = 0 ; i < n ; i++)
		a[i] = (rand() % max_ele);

	// testing
	printf("Input array is: ");
	for(i = 0 ; i < n ; i++)
		printf("%d  ", a[i]);
	printf("\n");

	printf("Enter the value of 'l' i.e. the min gap (b/w 1 and 29 inclusive): ");
	scanf("%d", &l);

	// using brute force to find the correct answer
	for (j = l ; j < n ; j++)	{
		i = j - l;
		while (i >= 0)	{
			if (a[j] - a[i] > max)
				max = a[j] - a[i];
			i--;
		}
	}

	printf("Brute force answer = %d\n", max);
	max = 0;

	// optimized answer
	i = 0;
	for (j = l ; j < n ; j++)	{
		if (a[j] - a[i] > max)
			max = a[j] - a[i];
		if (a[j - l + 1] < a[i])
			i = j - l + 1;
		// here i keeps track of the minimum element in the range [0, j - l]
	}

	printf("O(n) answer is %d\n", max);

	return 0;
}
