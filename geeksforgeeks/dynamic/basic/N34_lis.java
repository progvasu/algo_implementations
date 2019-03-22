/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int m;
		int[] input;
		int[] dp;

		while (test_cases-- > 0)	{
			m = scan.nextInt();
			input = new int[m];

			// read in the input
			for (int i = 0 ; i < m ; i++)	{
				input[i] = scan.nextInt();
			}

			// dp table
			dp = new int[m];

			// for the last element
			dp[m - 1] = 1;

			// for rest
			for (int i = m - 2 ; i >= 0 ; i--)	{
				// include the element itself
				dp[i] = 1;

				for (int j = i + 1 ; j < m ; j++)	{
					if ((input[j] > input[i]) && (dp[j] + 1 > dp[i]))
						dp[i] = dp[j] + 1;
				}
			}

			// find max
			int max = Integer.MIN_VALUE;
			for (int i = 0 ; i < m ; i++)	{
				if (dp[i] > max)
					max = dp[i];
			}

			System.out.println(max);
		}
	}
}