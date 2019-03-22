/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int m;
		String first;
		int[][] dp;

		while(test_cases-- > 0)	{
			m = scan.nextInt();
			
			first = scan.next();
			
			dp = new int[m + 1][m + 1];

			for (int i = 0 ; i <= m ; i++)	{
				for (int j = 0 ; j <= m ; j++)	{
					if (i == 0 || j == 0)
						dp[i][j] = 0;
					else if (first.charAt(i - 1) == first.charAt(j - 1) && (i != j))
						dp[i][j] = dp[i - 1][j - 1] + 1;
					else
						dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
				}
			}

			System.out.println(dp[m][m]);
		}
	}
}