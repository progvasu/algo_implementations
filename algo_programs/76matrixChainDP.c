// Matrix Chain Mulitplication
// Find best parenthesization that leads to the minimum number of operations

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	srand(time(0));

	// input format
	// number of matrices
	int n = 5;
	// index's
	int p[6] = {1, 10, 5, 2, 25, 4};

	// state table
	int M[n][n], i, j, l, temp, k;

	// we store the backtracking matrix in the lower half below the diagonal
	
	// initializing everything to zero for debugging purposes
	for (i = 0 ; i < n ; i++)
		for (j = 0 ; j < n ; j++)
			M[i][j] = 0;

	// initialization
	// for a single matrix - zero operations required
	for (i = 0 ; i < n ; i++)
		M[i][i] = 0;

	// for two matrices only one way to mutiply
	for (i = 0 ; i < n - 1; i++)
		M[i][i + 1] = p[i] * p[i + 1] * p[i + 2];
	
	// induction
	// l here denotes the length of the matrix chain that we are currently considering
	for (l = 2 ; l < n ; l++)	{
		// for every row
		for (i = 0 ; i < n - l ; i++)	{
			j = i + l;

			// intial value of k = i
			M[i][j] = M[i][i] + M[i + 1][j] + p[i] * p[i + 1] * p[j + 1];
			M[j][i] = k;

			for(k = i + 1 ; k < j ; k++)	{
				temp = M[i][k] + M[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
				if (M[i][j] > temp)	{
					M[i][j] = temp;
					M[j][i] = k;					
				}
			}
		}
	}

	// printing the state table
	printf("%7c", ' ');
	for (j = 0 ; j < n ; j++)
		printf("%7d", j + 1);
	printf("\n");
	for (i = 0 ; i < n ; i++)	{
		printf("%7d", i + 1);

		for (j = 0 ; j < n ; j++)
			printf("%7d", M[i][j]);

		printf("\n");
	}
	printf("\n");

	return 0;
}