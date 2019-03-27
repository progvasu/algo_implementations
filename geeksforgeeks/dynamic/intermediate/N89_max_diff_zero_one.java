/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int n;
		int[] input;
		int max_sum;

		// dp table
		int[] dp;

		while(test_cases-- > 0)	{
			n = scan.nextInt();

			input = new int[n];
			for (int i = 0 ; i < n ; i++)	{
				input[i] = scan.nextInt();

				if (input[i] == 0)
					input[i] = 1;
				else
					input[i] = -1;
			}


			dp = new int[n];
			dp[0] = input[0];
			max_sum = dp[0];

			for (int i = 1 ; i < n ; i++)	{
				dp[i] = dp[i - 1] + input[i];

				if (dp[i] > max_sum)
					max_sum = dp[i];										
			}

			System.out.println(max_sum);
		}
	}
}