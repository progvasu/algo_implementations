/*package whatever //do not write package name here */
// correct 

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int h = 1001;
		long[] dp = new long[h];
		long mod = 1000000007;

		// base cases
		dp[0] = 1;
		dp[1] = 1;

		// easy solution
		for (int i = 2 ; i < h ; i++)	{
			dp[i] = (dp[i - 1] * (((2 * dp[i - 2]) % mod + dp[i - 1])) % mod) % (mod);
		}

		while (test_cases-- > 0)	{
			h = scan.nextInt();

			System.out.println(dp[h]); 
		}
	}
}