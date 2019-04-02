/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int n = 25, m = 25;
		int[][] dp = new int[n + 1][m + 1];

		for (int i = 0 ; i <= n ; i++)	{
			for (int j = 0; j <= m ; j++)	{
				if (i == 0 || j == 0)	{
					dp[i][j] = 1;
				}
				else
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}	
		}

		while (test_cases-- > 0)	{
			n = scan.nextInt();
			m = scan.nextInt();

			System.out.println(dp[n][m]);
		}
	}
}