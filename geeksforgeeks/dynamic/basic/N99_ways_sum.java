// just like coin exchange 
// using the condensed version of coin change problem
// DIFFERENT APPROACH TO THAT SINCE INITIALIZATION NOT POSSIBLE - since number of coins is not fixed

/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int m, n;
		int[] coins;
		int[] dp;

		while(test_cases-- > 0)	{
			m = scan.nextInt();
			n = scan.nextInt();

			coins = new int[m];
			for (int i = 0 ; i < m ; i++)	{
				coins[i] = scan.nextInt();			
			}

			dp = new int[n + 1];
			dp[0] = 1;

			for (int i = 1 ; i < n + 1 ; i++)	{
				for (int j = 0 ; j < m ; j++)	{
					if (i - coins[j] >= 0)	{
						dp[i] = (dp[i] + dp[i - coins[j]]) % 1000000007;
					}
				}
			}


			System.out.println(dp[n]);
		}
	}
}