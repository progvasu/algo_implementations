/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int m, n;
		String str1, str2;
		int[][] dp;

		while (test_cases-- > 0)	{
			m = scan.nextInt();
			n = scan.nextInt();

			str1 = scan.next();
			str2 = scan.next();

			dp = new int[m + 1][n + 1];

			for (int i = 0 ; i <= m ; i++)	{
				for (int j = 0 ; j <= n ; j++)	{
					if (i == 0)
						dp[i][j] = j;
					else if (j == 0)
						dp[i][j] = i;
					else if (str1.charAt(i - 1) == str2.charAt(j - 1))
						dp[i][j] = dp[i - 1][j - 1];
					else
						dp[i][j] = 1 + Math.min(dp[i][j - 1], Math.min(dp[i - 1][j], dp[i - 1][j - 1]));
						// add, remove, replace
				}
			}

			System.out.println(dp[m][n]);
		}
	}
}