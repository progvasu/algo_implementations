// testing program 81

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function signatures
// void findMaxRect(int, int, int);

int findMaxRect(int row, int col, int A[row][col])	{
	int a, b, c, d, sum, i, j;
	// a, b, c, d - represents the  sub matrix coordinates
	// (a,b) - top left & (c, d) - bottom right
	// i, j - these coordinates are for iterating through the submatrix to find the maximum sum
	// sum - temporary sum for a submatrix

	int max = -1, a_max, b_max, c_max, d_max;
	// max - maximum sum found so far
	// a_, b_, c_, d_ max - for storing the coordinates of maximum rect submatrix

	// brute force solution
	// finding every possible sub matrix
	for (a = 0 ; a < row ; a++)	{
		for (b = 0 ; b < col ; b++)	{
			for (c = a ; c < row ; c++)	{
				for (d = b ; d < col ; d++)	{
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
	for (a = 0 ; a < row ; a++)	{
		for (b = 0 ; b < col ; b++)	{
			for (c = a ; c < row ; c++)	{
				for (d = b ; d < col ; d++)	{
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
		}
	}

	int max_opt = max;

	if (max_brute != max_opt)
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

	int iter = 10000;

	while(iter--)	{
		// random input matrix
		for (i = 0 ; i < row ; i++)	{
			for (j = 0 ; j < col ; j++)	{
				A[i][j] = rand() % 50 - rand() % 50;	
			}
		}

		int test = findMaxRect(row, col, A);

		if (test == 0)	{
			printf("ERROR\n");
		}
	}

	return 0;
}