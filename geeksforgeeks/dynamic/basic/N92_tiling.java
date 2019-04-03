// repeated
/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int n = 80;
		long[] dp = new long[n + 1];
		dp[0] = 0;
		dp[1] = 1;

		for (int i = 2 ; i <= n ; i++)	{
			if (i < 4)
				dp[i] = 1;
			else if (i == 4)
				dp[i] = 2;
			else
				dp[i] = dp[i - 1] + dp[i - 4];
		}

		while (test_cases-- > 0)	{
			n = scan.nextInt();

			System.out.println(dp[n]);
		}
	}
}