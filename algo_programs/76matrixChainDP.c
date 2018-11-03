// Matrix Chain Multiplication
// Find best parenthesization that leads to the minimum number of operations

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print_optimal_paren(int rows, int cols, int M[rows][cols], int i, int j)	{
    if (i == j)
		printf("A%d", i + 1);
	else	{
		// printf("%d - %d - %d\n", i, j, M[j][i]);
		// print_optimal_paren(rows, cols, M, i, M[j][i]);
		// print_optimal_paren(rows, cols, M, M[j][i] + 1, j);
		printf(" (");
		print_optimal_paren(rows, cols, M, i, M[j][i]);
		print_optimal_paren(rows, cols, M, M[j][i] + 1, j);
		printf(") ");
	}
}

int main()	{
	srand(time(0));

	// input format
	// number of matrices
	// int n = 5;
	// index's
	// int p[6] = {1, 10, 5, 2, 25, 4};

	 int n = 6;
	 int p[7] = {30, 35, 15, 5, 10, 20, 25};

	// int n = 4;
	// int p[5] = {40, 20, 30, 10, 30};
	// int p[5] = {10, 20, 30, 40, 30};

	//int n = 2;
	// int p[3] = {10, 20, 30};

	// state table
	int M[n][n], i, j, l, temp, k;

	// we store the backtracking matrix in the lower half below the diagonal

	// initializing everything to zero for debugging purposes
	// for (i = 0 ; i < n ; i++)
	//	for (j = 0 ; j < n ; j++)
	//		M[i][j] = 0;

	// initialization
	// for a single matrix - zero operations required
	for (i = 0 ; i < n ; i++)
		M[i][i] = 0;

	// for two matrices only one way to multiply
	for (i = 0 ; i < n - 1; i++)	{
		M[i][i + 1] = p[i] * p[i + 1] * p[i + 2];
		M[i + 1][i] = i;
	}

	// induction
	// l here denotes the length of the matrix chain that we are currently considering
	// also storing the backtracking values
	for (l = 2 ; l < n ; l++)	{
		// for every row - we move diagonally
		for (i = 0 ; i < n - l ; i++)	{
			j = i + l;

			// initial value of k = i
			M[i][j] = M[i][i] + M[i + 1][j] + p[i] * p[i + 1] * p[j + 1];
			M[j][i] = i;

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

	// backtracking to get matrix divisions
	printf("Matrix Order: ");
	print_optimal_paren(n, n, M, 0, n - 1);

	// horizontal filling

	// state table
	int H[n][n];

	// initialization - diagonalization
	// for a single matrix - zero operations required
	for (i = 0 ; i < n ; i++)
		H[i][i] = 0;

	// for two matrices only one way to multiply
	for (i = 0 ; i < n - 1; i++)	{
		H[i][i + 1] = p[i] * p[i + 1] * p[i + 2];
		H[i + 1][i] = i;
	}

	// induction
	for (l = 2 ; l < n ; l++)	{
		i = n - 1 - l;
		for (j = n - l; j < n ; j++)	{
			// initial value of k = i
			H[i][j] = H[i][i] + H[i + 1][j] + p[i] * p[i + 1] * p[j + 1];
			H[j][i] = i;

			for(k = i + 1 ; k < j ; k++)	{
				temp = H[i][k] + H[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
				if (H[i][j] > temp)	{
					H[i][j] = temp;
					H[j][i] = k;
				}
			}
		}
	}

	// does this new state table matches the diagonal one
	int same = 1;
	for (i = 0 ; i < n ; i++)	{
		for (j = 0 ; j < n ; j++)	{
			if (M[i][j] != H[i][j])	{
				same = 0;
				break;
			}
		}
	}

	printf("\n\nHorizontal Filling: ");
	if (same)
		printf("matches");
	else
		printf("doesn't match");
	printf("\n");

	return 0;
}
