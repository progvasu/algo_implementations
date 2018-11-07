// Find the max sum k dim square submatrix

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// min function macro
#define MAX(X, Y) ((X > Y ? X : Y))

// function signatures
// int findMaxKSq(int, int, int, int);
// void printResult(int, int, int, int, int, int, int, int);
// void printMatrix(int, int, int, int, int, int, int);

void printMatrix(int row, int col, int A[row][col], int a_max, int b_max, int c_max, int d_max)	{
	int i, j;
	for (i = a_max ; i <= c_max ; i++)	{
		for (j = b_max ; j <= d_max ; j++)	{
			printf("%5d", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printResult(int row, int col, int A[row][col], int max, int a_max, int b_max, int c_max, int d_max)	{
	printf("Maximum Sum is %d\n\n", max);
	printMatrix(row, col, A, a_max, b_max, c_max, d_max);
}

int findMaxKSq(int row, int col, int A[row][col], int k)	{
	int a, b, c, d, sum, i, j, l;
	// a, b, c, d - represents the  sub matrix coordinates
	// (a,b) - top left & (c, d) - bottom right
	// i, j - these coordinates are for iterating through the submatrix to find the maximum sum
	// sum - temporary sum for a submatrix
	// l - length of the square matrix

	int max = -1, a_max, b_max, c_max, d_max;
	// max - maximum sum found so far
	// a_, b_, c_, d_ max - for storing the coordinates of maximum rect submatrix

	// brute force solution
	// finding every possible sub matrix
	for (a = 0 ; a < row - k ; a++)	{
		for (b = 0 ; b < col - k ; b++)	{
			c = a + k - 1;
			d = b + k - 1;

			// found a submatrix here
			// now finding the sum of all elements
			sum = 0;
			for (i = a ; i <= c ; i++)	{
				for (j = b ; j <= d ; j++)	{
					sum += A[i][j];
				}
			}
			if (sum > max)	{
				max = sum;
				a_max = a;
				b_max = b;
				c_max = c;
				d_max = d;
			}
		}
	}

	int max_brute = max;

	// optmized version
	
	// calculating matrix M which stores sum of matrixs (0, 0) to (i, j)
	int M[row][col];

	// calculating column sums first
	// intialization first row
	i = 0;
	for (j = 0 ; j < col ; j++)
		M[i][j] = A[i][j];
	// induction
	for (i = 1 ; i < row ; i++)	{
		for (j = 0 ; j < col ; j++)	{
			M[i][j] = M[i - 1][j] + A[i][j];
		}
	}

	// using this M to calculate our original M
	// first column remains the same
	for (i = 0 ; i < row ; i++)	{
		for (j = 1 ; j < col ; j++)	{
			M[i][j] += M[i][j - 1];
		}
	}

	max = -1;
	// using this M for optimized version calculations
	for (a = 0 ; a < row - k ; a++)	{
		for (b = 0 ; b < col - k ; b++)	{
			c = a + k - 1;
			d = b + k - 1;
			
			// found a submatrix here
			// now finding the sum of all elements
			// need to take care of base cases
			if (a > 0 && b > 0)	{
				sum = M[c][d] - M[a - 1][d] - M[c][b -1] + M[a - 1][b - 1];
			}
			else	{
				// one of the a or b is zero
				if (a > 0)	{
					// sub matrix that touches the first column
					sum = M[c][d] - M[a - 1][d];
				}
				else if (b > 0)	{
					// sub matrix that touches the first row
					sum = M[c][d] - M[c][b - 1];	
				}
				else	{
					// sub matrix that touches both the first row and column
					sum = M[c][d];
				}
			}
			if (max < sum)	{
				max = sum;
				a_max = a;
				b_max = b;
				c_max = c;
				d_max = d;	
			}
		}
	}

	int max_opti = max;

	if (max_brute != max_opti)
		return 0;
	else
		return 1;
}

int main()	{
	srand(time(0));
	
	// test results
	int test;

	// input
	int row = 10, col = 10;
	int A[row][col];
	int i, j;
	int k = 5;
	int iter = 1000000;

	while(iter--)	{
		// random input matrix
		for (i = 0 ; i < row ; i++)	{
			for (j = 0 ; j < col ; j++)	{
				A[i][j] = rand() % 50 - rand() % 50;	
			}
		}

		int test = findMaxKSq(row, col, A, k);

		if (test == 0)	{
			printf("ERROR\n");
		}
	}

	return 0;
}