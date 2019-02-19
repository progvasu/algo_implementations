/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int m, n;

		while (test_cases-- > 0)	{
			// getting the input
			// getting the dimensions
			m = scan.nextInt();
			n = scan.nextInt();

			// define the input table
			int[][] input = new int[m][n];
			// define the dp table
			int[][] dp = new int[m][n];
			
			// fill in the input
			for (int i = 0 ; i < m ; i++)	{
				for (int j = 0 ; j < n ; j++)	{
					input[i][j] = scan.nextInt();

					// just need the first column
					if (j == 0)
						dp[i][j] = input[i][j];
					else
						dp[i][j] = 0;

					System.out.printf("%5d", input[i][j]);
				}
				System.out.println();
			}

			int left_up, left, left_down;
			// fill in the state table
			// need to move column wise - till second last column
			for (int j = 1 ; j < n ; j++)	{
				for (int i = 0 ; i < m ; i++)	{
					// this cell could have come from left, left up and left down
					left_up = 0;
					left = 0;
					left_down = 0;

					if (i != 0)
						left_up = dp[i - 1][j - 1];
					left = dp[i][j - 1];
					if (i != m - 1)
						left_down = dp[i + 1][j - 1];

					int max = Math.max(left_up, Math.max(left, left_down));

					dp[i][j] = input[i][j] + max;
				}
			}

			// print dp table
			for (int i = 0 ; i < m ; i++)	{
				for (int j = 0 ; j < n ; j++)	{
					System.out.printf("%5d", dp[i][j]);
				}
				System.out.println();
			}

			// find the max in the right most column and print
			int result = dp[0][n - 1];
			for (int i = 1 ; i < m ; i++)	{
				if (result < dp[i][n - 1])
					result = dp[i][n - 1];
				// System.out.println(dp[i][n - 1]);
			}

			System.out.println(result);
		} // end of while
	}
}