// Coin exchange problem
// Find the total number of ways possible to pay for n

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	srand(time(0));

	// coin values
	int k = 4;
	int coin_value[k];
	coin_value[0] = 1;
	coin_value[1] = 3;
	coin_value[2] = 5;
	coin_value[3] = 7;

	// sum needed to pay - n
	int n;
	n = 8; //rand() % 100;

	// we write a dynamic programming solution for this
	// state table
	int v[n + 1][k];

	int i, j;
	
	// intialization
	// first column - number of ways we can pay i = 1 (just coins of denom 1)
	for (i = 0 ; i < n + 1 ; i++)
		v[i][0] = 1;

	// first row - if the value to be paid is zero total number of ways is one - no combination possible
	for (j = 0 ; j < k ; j++)
		v[0][j] = 1;

	// induction
	for (j = 1 ; j < k ; j++)	{
		for (i = 1 ; i < n + 1 ; i++)	{
			// initialize v[i][j] to avoid garbage values
			v[i][j] = 0;

			// we can pay at current level using both these ways
			// either include that coin and count number of ways with which we can pay the remaining
			if (i >= coin_value[j])
				v[i][j] = v[i - coin_value[j]][j];
			
			// not include that coin and then pay
			v[i][j] += v[i][j - 1];
		}
	}

	// // exchanging the loops to see if induction step still works - works
	// for (i = 1 ; i < n + 1 ; i++)	{
	// 	for (j = 1 ; j < k ; j++)	{
	// 		// initialize v[i][j] to avoid garbage values
	// 		v[i][j] = 0;

	// 		// we can pay at current level using both these ways
	// 		// either include that coin and count number of ways with which we can pay the remaining
	// 		if (i >= coin_value[j])
	// 			v[i][j] = v[i - coin_value[j]][j];
			
	// 		// not include that coin and then pay
	// 		v[i][j] += v[i][j - 1];
	// 	}
	// }	

	// printing out the state table
	// printing coin values
	printf("%7c", ' ');
	for (j = 0 ; j < k ; j++)
		printf("%7d", coin_value[j]);
	printf("\n");

	// printing table values
	for (i = 0 ; i < n + 1 ; i++)	{
		printf("%7d", i);
		for (j = 0 ; j < k ; j++)
			printf("%7d", v[i][j]);
		printf("\n");
	}
	printf("\n");

	// // result - v[n][k - 1] - number of coins
	printf("Number of ways possible to pay for %d: %d\n\n", n, v[n][k - 1]);

	// space optimized version

	printf("\nUsing space optimized version\n\n");

	// state table
	int t[n + 1];

	// base case - j = 0
	for (i = 0 ; i < n + 1; i++)
		t[i] = i;

	// induction
	for (j = 1 ; j < k ; j++)	{
		for (i = 1 ; i < n + 1 ; i++)	{
			if (i >= coin_value[j] && (t[i - coin_value[j]] + 1) < t[i])
				t[i] = t[i - coin_value[j]] + 1;
		}
	}

	// // does exchanging the loops work - will not work
	// for (i = 1 ; i < n + 1 ; i++)	{
	// 	for (j = 1 ; j < k ; j++)	{
	// 		if (i >= coin_value[j] && (t[i - coin_value[j]] + 1) < t[i])
	// 			t[i] = t[i - coin_value[j]] + 1;
	// 	}
	// }	

	// // printing state table
	// // for(i = 0 ; i < n + 1 ; i++)	{
	// // 	printf("%5d%5d\n", i, t[i]);
	// // }

	// // printf("\n");

	// printf("Number of coins required to pay for %d: %d\n\n", n, t[n]);

	// // backtracking to get value of these coins
	// printf("Coins used: ");
	
	// i = n;
	// j = k - 1;
	// while (j > 0)	{
	// 	if (i >= coin_value[j] && t[i] == (1 + t[i - coin_value[j]]))	{
	// 		printf("%4d", coin_value[j]);
	// 		i = i - coin_value[j];
	// 	}
	// 	else	{
	// 		j = j - 1;
	// 	}
	// }

	// // is some value left unpaid?
	// if (i > 0)
	// 	while (i--)	{
	// 		printf("%4d", 1);
	// 	}	

	// printf("\n");

	return 0;
}