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
		String inputS;
		int max_sum;
		char temp;

		// dp table
		int[] dp;

		while(test_cases-- > 0)	{
			inputS = scan.next();

			n = inputS.length();

			input = new int[n];
			for (int i = 0 ; i < n ; i++)	{
				temp = inputS.charAt(i);

				if (temp == '0')
					input[i] = 1;
				else
					input[i] = -1;
			}


			dp = new int[n];
			dp[0] = input[0];
			max_sum = dp[0];

			for (int i = 1 ; i < n ; i++)	{
				if (dp[i - 1] < 0)
					dp[i - 1] = 0;

				dp[i] = dp[i - 1] + input[i];

				if (dp[i] > max_sum)
					max_sum = dp[i];

				// if (dp[i] < 0)
				// 	dp[i] = 0;										
			}

			System.out.println(max_sum);
		}
	}
}