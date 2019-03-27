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
		int[] tb;

		while (test_cases-- > 0)	{
			m = scan.nextInt();
			input = new int[m];

			// read in the input
			for (int i = 0 ; i < m ; i++)	{
				input[i] = scan.nextInt();
			}

			// for LIS upto that index dp table
			dp = new int[m];

			// for first element
			dp[0] = input[0];

			for (int i = 1 ; i < m ; i++)	{
				// include the element itself
				dp[i] = input[i];

				for (int j = i - 1 ; j >= 0 ; j--)	{
					if ((input[j] < input[i]) && (dp[j] + input[i] > dp[i]))
						dp[i] = dp[j] + input[i];
				}
			}

			// now for lds
			tb = new int[m];

			// for the last element
			tb[m - 1] = input[m - 1];

			// for rest
			for (int i = m - 2 ; i >= 0 ; i--)	{
				// include the element itself
				tb[i] = input[i];

				for (int j = i + 1 ; j < m ; j++)	{
					if ((input[j] < input[i]) && (tb[j] + input[i] > tb[i]))
						tb[i] = tb[j] + input[i];
				}
			}

			// find max
			int max = Integer.MIN_VALUE;
			for (int i = 0 ; i < m ; i++)	{
				if (dp[i] + tb[i] - input[i] > max)
					max = dp[i] + tb[i] - input[i];
			}

			System.out.println(max);
		}
	}
}