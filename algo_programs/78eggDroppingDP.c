// we have a large building with number of floors = 1000 lets say and number of eggs given are k (3 < k < 10)
// for a given k we want to know the min trials required to find where the min floor where the egg breaks

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// max function macro
#define MAX(X, Y) ((X > Y ? X : Y))

int main()	{
	srand(time(0));

	// input
	int nf = 30;
	int neggs = 2;

	// state table
	int T[nf + 1][neggs + 1];
	// backtracking table
	int B[nf + 1][neggs + 1];

	int i, j, k, temp;

	// initializing everything to zero for debugging
	for (i = 0 ; i <= nf ; i++)
		for (j = 1 ; j <= neggs ; j++)	{
			T[i][j] = 0;
			B[i][j] = 0;	
		}

	// base case
	// first column j = 1 - starting with 1 egg not zero eggs
	// number of trails required = number of floors
	for (i = 0 ; i <= nf ; i++)	{
		T[i][1] = i;
		B[i][1] = i;
	}

	// first row - zero floors = zero trials required irrespective of number of eggs available
	// second row - 1 floor - just 1 trial required
	for (j = 1 ; j <= neggs ; j++)	{
		T[0][j] = 0;
		B[0][j] = 0;

		T[1][j] = 1;
		B[1][j] = 1;
	}

	// induction
	for (i = 2 ; i <= nf ; i++)	{
		for (j = 2 ; j <= neggs ; j++)	{
			T[i][j] = 1;
			B[i][j] = k;

			// initialize k = 1
			k = 1;
			temp = MAX(T[k - 1][j - 1], T[i - k][j]);
			for (k = 2 ; k <= i ; k++)	{
				if (temp > MAX(T[k - 1][j - 1], T[i - k][j]))	{
					temp = MAX(T[k - 1][j - 1], T[i - k][j]);
					B[i][j] = k;
				}
			}
			T[i][j] += temp;
		}
	}

	// printf state table
	printf("%5c", ' ');
	for (j = 1 ; j <= neggs ; j++)
		printf("%5d", j);
	printf("\n");

	for (i = 0 ; i <= nf ; i++)	{
		printf("%5d", i);

		for (j = 1 ; j <= neggs ; j++)
			printf("%5d", T[i][j]);

		printf("\n");
	}
	printf("\n");

	printf("Minimum number of trails required: %d\n\n", T[nf][neggs]);

	// backtracking using extra space

	printf("Backtracking state table: \n");
	printf("%5c", ' ');
	for (j = 1 ; j <= neggs ; j++)
		printf("%5d", j);
	printf("\n");

	for (i = 0 ; i <= nf ; i++)	{
		printf("%5d", i);

		for (j = 1 ; j <= neggs ; j++)
			printf("%5d", B[i][j]);

		printf("\n");
	}
	printf("\n");

	return 0;
}