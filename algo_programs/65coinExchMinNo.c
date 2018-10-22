// Coin exchange problem
// Find the minimum number fo coins required to pay for n

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	srand(time(0));

	// coin values
	int k = 3;
	int coin_value[k];
	coin_value[0] = 1;
	coin_value[1] = 7;
	coin_value[2] = 10;

	// sum needed to pay - n
	int n;
	n = rand() % 100;

	// we write a dynamic programming solution for this
	// state table
	int v[n + 1][k];

	int i, j;
	
	// intialization
	// first column - amount required to pay for 'i' using coin of value 1 = i
	for (i = 0 ; i < n + 1 ; i++)
		v[i][0] = i;

	// first row
	// if the value to be paid is zero coins required are also zero
	for (j = 0 ; j < k ; j++)
		v[0][j] = 0;

	// induction
	for (j = 1 ; j < k ; j++)	{
		for (i = 1 ; i < n + 1 ; i++)	{
			if (i >= coin_value[j] && (v[i][j - 1] > (1 + v[i - coin_value[j]][j])))
				v[i][j] = 1 + v[i - coin_value[j]][j];
			else
				v[i][j] = v[i][j - 1];
		}
	}

	// exchanging the loops to see if induction step still works - works
	// for (i = 1 ; i < n + 1 ; i++)	{
	// 	for (j = 1 ; j < k ; j++)	{
	// 		if (i >= coin_value[j] && (v[i][j - 1] > (1 + v[i - coin_value[j]][j])))
	// 			v[i][j] = 1 + v[i - coin_value[j]][j];
	// 		else
	// 			v[i][j] = v[i][j - 1];
	// 	}
	// }	

	// printing out the state table
	// for (i = 0 ; i < n + 1 ; i++)	{
	// 	for (j = 0 ; j < k ; j++)
	// 		printf("%7d", v[i][j]);
	// 	printf("\n");
	// }
	// printf("\n");

	// result - v[n][k - 1] - number of coins
	printf("Number of coins required to pay for %d: %d\n\n", n, v[n][k - 1]);

	// backtracking to get values of these coins
	// printf("Coins used: ");
	// i = n;
	// j = k - 1; // adjusting for loop indices
	// while (j > 0)	{
	// 	if (v[i][j] == v[i][j - 1])	{
	// 		// not used the jth coin
	// 		j = j - 1;
	// 	}
	// 	else	{
	// 		// used the jth coin
	// 		printf("%4d", coin_value[j]);
	// 		i = i - coin_value[j];
	// 	}
	// }

	// // is some value left unpaid?
	// if (i > 0)
	// 	while (i--)	{
	// 		printf("%4d", 1);
	// 	}

	// another way of writing - same backtracking algorithm
	printf("Coins used: ");
	i = n;
	j = k - 1; // adjusting for loop indices
	while (j > 0)	{
		if (i >= coin_value[j] && v[i][j] == 1 + v[i - coin_value[j]][j])	{
			// used the jth coin
			printf("%4d", coin_value[j]);
			i = i - coin_value[j];
		}
		else	{
			// not used the jth coin
			j = j - 1;
		}
	}

	// is some value left unpaid?
	if (i > 0)
		while (i--)	{
			printf("%4d", 1);
		}	

	printf("\n");

	// space optimized version

	printf("\nUsing space optimized version\n\n");

	// state table
	int t[n + 1];

	// base case - j = 0
	for (i = 0 ; i < n + 1; i++)
		t[i] = i;

	// induction
	// for (j = 1 ; j < k ; j++)	{
	// 	for (i = 1 ; i < n + 1 ; i++)	{
	// 		if (i >= coin_value[j] && (t[i - coin_value[j]] + 1) < t[i])
	// 			t[i] = t[i - coin_value[j]] + 1;
	// 	}
	// }

	// does exchanging the loops work - yes works
	for (i = 1 ; i < n + 1 ; i++)	{
		for (j = 1 ; j < k ; j++)	{
			if (i >= coin_value[j] && (t[i - coin_value[j]] + 1) < t[i])
				t[i] = t[i - coin_value[j]] + 1;
		}
	}	

	// printing state table
	// for(i = 0 ; i < n + 1 ; i++)	{
	// 	printf("%5d%5d\n", i, t[i]);
	// }

	// printf("\n");

	printf("Number of coins required to pay for %d: %d\n\n", n, t[n]);

	// backtracking to get value of these coins
	printf("Coins used: ");
	
	i = n;
	j = k - 1;
	while (j > 0)	{
		if (i >= coin_value[j] && t[i] == (1 + t[i - coin_value[j]]))	{
			printf("%4d", coin_value[j]);
			i = i - coin_value[j];
		}
		else	{
			j = j - 1;
		}
	}

	// is some value left unpaid?
	if (i > 0)
		while (i--)	{
			printf("%4d", 1);
		}	

	printf("\n");

	return 0;
}