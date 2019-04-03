/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);	

		int test_cases = scan.nextInt();
		int n, m;
		int[][] dp = new int[100 + 1][100 + 1];

		for (int i = 1 ; i <= 100 ; i++)	{
			for (int j = 1 ; j <= 100 ; j++)	{
				if (i == 1 || j == 1)
					dp[i][j] = 1;
				else
					dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
			}
		}

		while(test_cases-- > 0)	{
			n = scan.nextInt();
			m = scan.nextInt();

			System.out.println(dp[n][m]);
		}
	}
}