/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int n, in, r, c;
		int[] dp;

		while (test_cases-- > 0)	{
			n = scan.nextInt();
			in = scan.nextInt();
			r = scan.nextInt();
			c = scan.nextInt();

			dp = new int[n + 1];

			dp[0] = 0;
			dp[1] = in;

			for (int i = 2 ; i <= n ; i++)	{
				if (i % 2 == 0)
					dp[i] = Math.min(dp[i - 1] + in, dp[i / 2] + c);
				else
					dp[i] = Math.min(dp[i - 1] + in, dp[i / 2 + 1] + c + r);
			}

			System.out.println(dp[n]);
		}
	}
}