/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan =  new Scanner(System.in);

		int test_cases = scan.nextInt();
		int n = 100001;
		int[] dp = new int[n];

		dp[0] = 0;
		dp[1] = 1;

		for (int i = 2 ; i < n ; i++)	{
			dp[i] = Math.max(dp[i/2] + dp[i/3] + dp[i/4], i);
		}

		while (test_cases-- > 0)	{
			n = scan.nextInt();

			System.out.println(dp[n + 1]);
		}
	}
}