// Find max(aj - ai) where j - l <= i < j i.e. sell the stocks within l days

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	srand(time(0));
	int n = 7;
	int a[n], i, j, l, max;

	// initialising array with 10 random numbers
	for(i = 0 ; i < n ; i++)
		a[i] = (rand() % 100);

	// random array
	printf("Input Array: ");
	for(i = 0 ; i < n ; i++)
		printf("%d  ", a[i]);
	printf("\n");

	printf("Enter the value of 'l' within [1, %d]: ", n - 1);
	scanf("%d", &l);

	// using brute force method
	max = 0;
	for(j = 1 ; j < n ; j++)	{
		for (i = j - 1 ; i >= 0 && i >= j - l ; i--)	{
			if (a[j] - a[i] > max)
				max = a[j] - a[i];
		}
	}

	printf("Answer using brute force solution is %d\n", max);

	// using optimized solution where running time = O(n)
	max = 0;

	// need a DS - somewhat like a queue
	int queue[n], t = 0, h = 0, test_iter = 0, temp;
	queue[h] = 0;
	i = 0;

	for (j = 1 ; j < n ; j++)	{
		if (a[j] - a[i] > max)
			max = a[j] - a[i];

		while (h >= 0 && a[queue[h]] > a[j]) 
			h--;

		queue[++h] = j;

		// testing
		temp = i;

		// smartly picking next minimum value of i
		// -1 because j will be incremented in the next iteration
		t = 0;
		// if queue has a smaller element than the current i
		

		while (j - i - 1 > l)
			i = queue[t++];

		// testing - print program status 
		// i, j, max
		printf("i = %d, j = %d, max = %d\n", temp, j, max);
		// queue status
		printf("Queue: ");
		for(test_iter = 0 ; test_iter <= h ; test_iter++)
			printf("%d  ", queue[test_iter]);
		printf("\nh = %d, t = %d, new_i = %d\n\n", h, t, i);
	}

	printf("Answer using optimized algo = %d\n", max);

	return 0;
}
