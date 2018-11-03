// Given an arbitrary number of cuts maximize the cost of cutting

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void print_cut_points(int rows, int cols, int T[rows][cols], int i, int j, int *l)	{
    if (i + 1 == j)
		return;
	else	{
		printf("Rod: %d ==== %d\n", l[i], l[j]);
		printf("Cut At: %d\n\n", l[T[j][i]]);
		print_cut_points(rows, cols, T, i, T[j][i], l);
		print_cut_points(rows, cols, T, T[j][i], j , l);
	}
}

int main()	{
	srand(time(0));

	// input
	// number of cuts
	int c = 3;
	// number of points to consider
	int n = c + 2;
	// cuts - left and right points gives left and right end points
	// int l[5] = {0, 25, 50, 75, 100};
	int l[5] = {0, 75, 90, 95, 100};

	// state table
	int T[n][n];
	int i, j, k, len_rod, temp;

	// initialization
	// everything to zero
	for (i = 0 ; i < n ; i++)
		for (j = 0 ; j < n ; j++)
			T[i][j] = 0;

    // for zero cuts
    for (i = 0 ; i < n - 1 ; i++)
		T[i][i + 1] = 0;

	// for exactly one cut
	for (i = 0 ; i < n - 2 ; i++)	{
		T[i][i + 2] = l[i + 2] - l[i];
        T[i + 2][i] = i + 1;
	}

	// we just fill the upper half of the matrix -  makes sense
	// diagonal filling - could also do horizontal filling - easy
	for (len_rod = 2 ; len_rod < n ; len_rod++)	{
		// for every row
		for (i = 0 ; i < n - len_rod ; i++)	{
			j = i + len_rod;
            T[i][j] = l[j] - l[i];
            temp = 999999;
            for (k = i + 1 ; k < j ; k++)	{
				if (temp > (T[i][k] + T[k][j]))	{
					temp = T[i][k] + T[k][j];
					T[j][i] = k;
				}
            }
            T[i][j] += temp;
		}
	}

	// printing state table
	printf("%5c", ' ');
	for (j = 0 ; j < n ; j++)
		printf("%5d", j);
	printf("\n");
	for (i = 0 ; i < n ; i++)	{
		printf("%5d", i);
		for (j = 0 ; j < n ; j++)	{
            printf("%5d", T[i][j]);
		}
		printf("\n");
	}

	// backtracking to find the optimal points were the cuts are supposed to be made
    printf("\n");
    print_cut_points(n, n, T, 0, n - 1, l);

	return 0;
}
