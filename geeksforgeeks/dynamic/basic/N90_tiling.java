// own solution image

/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int n, m;
		int[] dp;

		while(test_cases-- > 0)	{
			n = scan.nextInt();
			m = scan.nextInt();

			dp = new int[n + 1];

			dp[0] = 0;
			dp[1] = 1;

			for (int i = 2 ; i <= n ; i++)	{
				if (i < m)
					dp[i] = 1;
				else if (i == m)
					dp[i] = 2;
				else
					dp[i] = (dp[i - 1] + dp[i - m]) % 1000000007;
			}

			System.out.println(dp[n]);
		}
	}
}