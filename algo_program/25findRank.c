// Given a value of x find the rank of the input number
#include<stdio.h>

int main()	{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int b[] = {7, 6, 0, 9, 1, 4, 8, 3, 2, 5};
	int a_len = 10, b_len = 10, i, rank = 1, x;

	printf("Enter the element to find the rank: ");
	scanf("%d", &x);

	// find rank in a
	for (i = 0 ; i < a_len ; i++)	{
		if (a[i] > x)
			rank++;
	}

	printf("Rank in a is %d\n", rank);

	rank = 1;
	// find rank in b
	for (i = 0 ; i < b_len ; i++)	{
		if (b[i] > x)
			rank++;
	}

	printf("Rank in b is %d\n", rank);

	return 0;
}
