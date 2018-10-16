// tester code for coinExchMinNo

// Coin exchange problem
// Find the minimum number fo coins required to pay for n

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	srand(time(0));

	int iter = 100000;

	while(iter--)	{
		// coin values
		int k = rand() % 10 + 3; // atleast three coins
		int coin_value[k];
		int z;

		coin_value[0] = 1;
		for (z = 1 ; z < k ; z++)
			coin_value[z] = coin_value[z - 1] + rand() % 3 + 1;

		// sum needed to pay - n
		int n = rand() % 100;

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

		// result - v[n][k - 1] - number of coins
		int result1 = v[n][k - 1];

		int coins1[result1];
		z = 0;

		// another way of writing - same backtracking algorithm
		i = n;
		j = k - 1; // adjusting for loop indices
		while (j > 0)	{
			if (i >= coin_value[j] && v[i][j] == 1 + v[i - coin_value[j]][j])	{
				// used the jth coin
				coins1[z++] = coin_value[j];
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
				coins1[z++] = 1;
			}	

		// space optimized version

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

		int result2 = t[n];

		int coins2[result2];
		z = 0;

		i = n;
		j = k - 1;
		while (j > 0)	{
			if (i >= coin_value[j] && t[i] == (1 + t[i - coin_value[j]]))	{
				coins2[z++] = coin_value[j];
				i = i - coin_value[j];
			}
			else	{
				j = j - 1;
			}
		}

		// is some value left unpaid?
		if (i > 0)
			while (i--)	{
				coins2[z++] = 1;
			}	

		// verification
		if (result1 == result2)	{
			for (i = 0 ; i < z ; i++)	{
				if (coins1[i] != coins2[i])	{
					printf("ERROR\n");

					printf("Coins Used: ");
					for (i = 0 ; i < k ; i++)
						printf("%3d", coin_value[i]);
					printf("\n");
					
					printf("Value of n = %d, result1 = %d, result2 = %d\n", n, result1, result2);
					
					printf("Coins1: ");
					for (i = 0 ; i < z ; i++)
						printf("%3d", coins1[i]);
					printf("\n");
					
					printf("Coins2: ");
					for (i = 0 ; i < z ; i++)
						printf("%3d", coins2[i]);
					printf("\n");
					
					return 0;
				}
			}
		}
		else	{
			printf("ERROR\n");

			printf("Coins Used: ");
			for (i = 0 ; i < k ; i++)
				printf("%3d", coin_value[i]);
			printf("\n");
					
			printf("Value of n = %d, result1 = %d, result2 = %d\n", n, result1, result2);
					
			printf("Coins1: ");
			for (i = 0 ; i < z ; i++)
				printf("%3d", coins1[i]);
			printf("\n");
					
			printf("Coins2: ");
			for (i = 0 ; i < z ; i++)
				printf("%3d", coins2[i]);
			printf("\n");

			break;
		}
	}
	return 0;
}