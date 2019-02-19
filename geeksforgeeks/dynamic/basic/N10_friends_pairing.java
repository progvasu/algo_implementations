/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();

		// dp table
		// calculating till 100
		long[] dp = new long[101];

		// intialize
		// for optimal solution to hold 0 is case 1
		dp[0] = 1;
		dp[1] = 1;

		// fill in the state table
		for (int i = 2 ; i <= 100 ; i++)
			dp[i] = (dp[i - 1] + (i - 1) * dp[i - 2]) % 1000000007;

		int n;
		while(test_cases-- > 0)	{
			n = scan.nextInt();

			System.out.println(dp[n]);
		}
	}
}