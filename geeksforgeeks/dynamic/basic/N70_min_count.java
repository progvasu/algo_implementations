/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases =  scan.nextInt();
		int n = 10000;
		int[] dp = new int[n + 1];

		// base cases
		dp[0] = 0;
		dp[1] = 0;

		for (int i = 2 ; i <= n ; i++)	{
			dp[i] = dp[i - 1];

			if (i % 2 == 0)
				dp[i] = Math.min(dp[i / 2], dp[i]);
		
			if (i % 3 == 0)
				dp[i] = Math.min(dp[i / 3], dp[i]);

			dp[i] += 1;
		}

		while (test_cases-- > 0)	{
			System.out.println(dp[scan.nextInt()]);
		}
	}
}