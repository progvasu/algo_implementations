/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int m;
		int[] coins;
		int n;

		while (test_cases-- > 0)	{
			// read in the input
			m = scan.nextInt();
			coins = new int[m];
			for (int i = 0 ; i < m ; i++)	
				coins[i] = scan.nextInt();
			Arrays.sort(coins);
			n = scan.nextInt();

			// define the state table
			int[][] dp = new int[n + 1][m];

			// initialize the state table
			// first column
			for (int i = 1 ; i <= n ; i++)	{
				if (i % coins[0] == 0)
					// one way to give coin values
					dp[i][0] = 1;
				else
					// no way to fulfill using the first coin
					dp[i][0] = 0;
			}
			// first row to zero
			for (int j = 0 ; j < m ; j++)
				dp[0][j] = 1;

			// dp table fill
			for (int i = 1 ; i <= n ; i++)	{
				for (int j = 1 ; j < m ; j++)	{
					// either we can fullfill using this coin or not
					// use the jth coin
					if (i >= coins[j])
						dp[i][j] = dp[i - coins[j]][j];
					// if we dont use this coin
					dp[i][j] += dp[i][j - 1];
				}
			}

			// print state table
			// print dp table
			for (int i = 0 ; i <= n ; i++)	{
				for (int j = 0 ; j < m ; j++)	{
					System.out.printf("%5d", dp[i][j]);
				}
				System.out.println();
			}

			// print result
			System.out.println(dp[n][m - 1]);
		}
	}
}