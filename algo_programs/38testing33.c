// Testing program 38 with a large number of inputs

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int test(int l)	{
	int n = 10;
	int a[n], i, j, max, max_b;

	// initialising array with 10 random numbers
	for(i = 0 ; i < n ; i++)
		a[i] = (rand() % 100);

	// using brute force method
	max_b = 0;
	for(j = 1 ; j < n ; j++)	{
		for (i = j - 1 ; i >= 0 && i >= j - l ; i--)	{
			if (a[j] - a[i] > max_b)
				max_b = a[j] - a[i];
		}
	}

	// using optimized solution where running time = O(n)
	max = 0;

	int queue[n], t = 0, h = -1, test_iter = 0, temp;
	i = 0;

	for (j = 1 ; j < n ; j++)	{
		if (a[j] - a[i] > max)
			max = a[j] - a[i];

		while (h >= t && a[queue[h]] > a[j]) 
			h--;

		queue[++h] = j;

		if (t <= h && a[i] > a[queue[t]])
			i = queue[t++];
		
		if (j - i >= l)
			i = queue[t++];
	}

	
	// print array
	for (i = 0 ; i < n ; i++)
		printf("%4d", a[i]);
		
	if (max == max_b)	{
		printf("  Correct\n");
		return 1;
	}
	else	{
		printf("  Failed\n\n");
		printf("BF = %d\tOT = %d\n", max_b, max);
		return 0;
	}
}

int main()	{
	int l;
	printf("Enter one time value of l: ");
	scanf("%d", &l);

	int n = 10000;
	
	while(n-- >= 0 && test(l));

	return 0;
}
