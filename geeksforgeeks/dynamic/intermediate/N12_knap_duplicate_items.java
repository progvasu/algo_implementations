/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int n, w;
		int[][] dp;
		int[] value;
		int[] weight;

		while(test_cases-- > 0)	{
			n = scan.nextInt();
			w = scan.nextInt();

			dp = new int[n][w + 1];

			value = new int[n];
			weight = new int[n];

			for (int i = 0 ; i < n ; i++)	{
				value[i] = scan.nextInt();
			}
			for (int i = 0 ; i < n ; i++)	{
				weight[i] = scan.nextInt();
			}

			// initialize dp - first row
			for (int j = 0 ; j <= w ; j++)	{
				if (weight[0] == j)
					dp[0][j] = value[0];
				else if (weight[0] < j)
					dp[0][j] = value[0] + dp[0][j - weight[0]];
				else
					dp[0][j] = 0;
			}

			// induction
			for (int i = 1 ; i < n ; i++)	{
				for (int j = 0 ; j <= w ; j++)	{
					// intial - not including the ith item
					dp[i][j] = dp[i - 1][j];

					// can include it? then override
					if (weight[i] <= j)	{
						if (dp[i][j] < value[i] + dp[i][j - weight[i]])
							dp[i][j] = value[i] + dp[i][j - weight[i]];
					}
				}
			}

			System.out.println(dp[n - 1][w]);
		}
	}
}