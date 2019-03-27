/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int n;
		int[][] grid;
		int max;

		// dp table
		int[][] dp;

		while (test_cases-- > 0)	{
			n = scan.nextInt();

			grid = new int[2][n];
			for (int i = 0 ; i < 2 ; i++)	{
				for (int j = 0 ; j < n ; j++)	{
					grid[i][j] = scan.nextInt();
				}
			}

			// dp table
			dp = new int[2][n];

			// intial
			dp[0][0] = grid[0][0];
			dp[1][0] = grid[1][0];
			dp[0][1] = grid[0][1];
			dp[1][1] = grid[1][1];

			// loop
			for(int j = 2 ; j < n ; j++)	{
				for (int i = 0 ; i < 2 ; i++)	{
					dp[i][j] = grid[i][j] + Math.max(dp[0][j - 2], dp[1][j - 2]);

					if (j - 3 >= 0)	{
						dp[i][j] = Math.max(dp[i][j], grid[i][j] + Math.max(dp[0][j - 3], dp[1][j - 3]));
					}
				}
			}

			// find max
			max = Math.max(dp[0][n - 1], Math.max(dp[1][n - 1], Math.max(dp[0][n - 2], dp[1][n - 2])));

			System.out.println(max);
		}
	}
}