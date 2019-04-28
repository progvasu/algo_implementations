/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int n, k;

		int[][] dp;

		while(test_cases-- > 0)	{
			n = scan.nextInt();
			k = scan.nextInt();

			dp = new int[k + 1][n + 1];

			// base case 0 and one egg
			for (int i = 0 ; i <= k ; i++)	{
				dp[i][0] = 0;
				dp[i][1] = i;
			}

			// base case 0th and first floor
			for (int j = 0 ; j <= n ; j++)	{
				dp[0][j] = 0;
				dp[1][j] = 1;
			}

			// induction
			int kt, temp;
			for (int i = 2 ; i <= k ; i++)	{
				for (int j = 2 ; j <= n ; j++)	{
					// intialize 
					dp[i][j] = 1;

					kt = 1;
					// intial value k = 1
					temp = Math.max(dp[kt - 1][j - 1], dp[i - kt][j]);
					for (kt = 2 ; kt <= i ; kt++)
						temp = Math.min(temp, Math.max(dp[kt - 1][j - 1], dp[i - kt][j]));

					dp[i][j] += temp;
				}
			}


			System.out.println(dp[k][n]);
		}
	}
}