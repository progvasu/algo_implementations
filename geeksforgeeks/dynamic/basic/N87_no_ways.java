// just like coin exchange 
// using the condensed version of coin change problem

/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int n = 50;
		int[] dp = new int[n + 1];

		dp[0] = 1;
		dp[1] = 1;
		dp[2] = 2;

		for (int i = 3 ; i <= n ; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

		while(test_cases-- > 0)	{
			n = scan.nextInt();

			System.out.println(dp[n]);
		}
	}
}