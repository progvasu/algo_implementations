/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int m, n, o;
		String first, second, third;
		int[][][] dp;

		while(test_cases-- > 0)	{
			m = scan.nextInt();
			n = scan.nextInt();
			o = scan.nextInt();

			first = scan.next();
			second = scan.next();
			third = scan.next();

			dp = new int[m + 1][n + 1][o + 1];

			for (int i = 0 ; i <= m ; i++)	{
				for (int j = 0 ; j <= n ; j++)	{
					for (int k = 0 ; k <= o ; k++)	{
						if (i == 0 || j == 0 || k == 0)
							dp[i][j][k] = 0;
						else if ((first.charAt(i - 1) == second.charAt(j - 1)) && (third.charAt(k - 1) == second.charAt(j - 1)) && (first.charAt(i - 1) == third.charAt(k - 1)))
							dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
						else
							dp[i][j][k] = Math.max(Math.max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
					}
				}
			}

			System.out.println(dp[m][n][o]);
		}
	}
}