/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();

		// initialize the state table
		long[][] dp = new long[1001][801];

		// first column C(n, 0) = 1
		for (int i = 0 ; i < 1001 ; i++)
			dp[i][0] = 1;

		// filling in the state table
		for (int i = 0 ; i < 1001 ; i++)	{
			for (int j = 1 ; j <= Math.min(i, 800) ; j++)	{
				if (i == j)
					dp[i][j] = 1;
				else 	{
					dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 1000000007;
				}

			}
		}

		int n, k;
		while (test_cases-- > 0)	{
			n = scan.nextInt();
			k = scan.nextInt();
			System.out.println(dp[n][k]);
		}
	}
}