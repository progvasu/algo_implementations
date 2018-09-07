// finding k ~ 10^5 smallest numbers in n ~ 10^9 for this program we take n ~ 10^6 because of file size limitations
// we use las vegas method to find the median 

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int *a, int l, int r)	{
	int i, j, temp, pivot = a[l];
	i = l + 1;

	for (j = i ; j <= r ; j++)	{
		if (a[j] < pivot)	{
			temp = a[j];
			a[j] = a[i];
			a[i] = temp;
			i++;
		}
	}

	temp = a[i - 1];
	a[i - 1] = a[l];
	a[l] = temp;

	return i - 1;
}

void findMedian(int *a, int l, int r, int rank)	{
	int pivot_pos = l + (rand() % (r - l + 1));

	// replacing first element with pivot_pos
	int temp;
	temp = a[pivot_pos];
	a[pivot_pos] = a[l];
	a[l] = temp;

	// find the partition point
	int part = partition(a, l, r);

	if (rank == (r - part + 1))	{
		return;
	}
	else if (rank < (r - part + 1))	{
		findMedian(a, part + 1, r, rank);
	}
	else	{
		findMedian(a, l, part - 1, rank - (r - l + 1));
	}
}

int main()	{
	srand(time(0));
	// tesing 
 	int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	
	findMedian(a, 0, 8, 4);

	int i;
	for (i = 0 ; i < 9 ; i++)
		printf("%4d", a[i]);

	return 0;
}
