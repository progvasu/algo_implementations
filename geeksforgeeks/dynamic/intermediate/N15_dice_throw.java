/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int m, n, x;
		long[][] dp;

		while(test_cases-- > 0)	{
			m = scan.nextInt();
			n = scan.nextInt();
			x = scan.nextInt();

			dp = new long[n + 1][x + 1];

			// first column 
			// zero default

			// first row
			// means first dice se kya kya numbers generate kar sakte hain
			for (int j = 1 ; j <= x && j <= m ; j++)
				dp[1][j] = 1;

			// induction
			for (int i = 2 ; i <= n ; i++)	{
				for (int j = 1 ; j <= x ; j++)	{
					// k should not be greater than the sum we want and obviously should be less than the total number of faces available
					for (int k = 1 ; k <= m && k <= j; k++)	{
						dp[i][j] += dp[i - 1][j - k];
					}
				}
			}

			System.out.println(dp[n][x]);
		}
	}
}