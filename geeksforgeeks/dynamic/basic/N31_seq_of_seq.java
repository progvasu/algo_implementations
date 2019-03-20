/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int test_cases = scan.nextInt();
		int m = 1000;
		int n = 1000;

		// dp table
		int[][] dp = new int[m + 1][n + 1];

		// base cases
		// if either m = 0 or n = 0 then solution = 0
		// i.e. first row and column is zero
		// if n > m then solution is zero because max value cannot be less than the length of the sequence
		// if (n == 1) then solution is m

		for (int i = 0 ; i <= m ; i++)	{
			for (int j = 0 ; j <= n ; j++)	{
				if (i == 0 || j == 0)
					dp[i][j] = 0;
				else if (i < j)
					dp[i][j] = 0;
				else if (j == 1)
					dp[i][j] = i;
				else 
					dp[i][j] = dp[i/2][j - 1] + dp[i - 1][j];
			}
		}

		while (test_cases-- > 0)	{
			m = scan.nextInt();
			n = scan.nextInt();
			System.out.println(dp[m][n]);			
		}
	}
}