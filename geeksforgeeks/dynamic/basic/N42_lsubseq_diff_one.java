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
		int[] dp;
		int max = Integer.MIN_VALUE;

		while (test_cases-- > 0)	{
			n = scan.nextInt();
            max = Integer.MIN_VALUE;
            input = new int[n];
			for (int i = 0 ; i < n ; i++)
				input[i] = scan.nextInt();

			// dp table
			dp = new int[n];

			// last is one 
			dp[n - 1] = 1;
		
			for (int i = n - 2 ; i >= 0 ; i--)	{
				dp[i] = 1;
				for (int j = i + 1 ; j < n ; j++)	{
					if (Math.abs(input[i] - input[j]) == 1 && dp[j] + 1 > dp[i])	{
						dp[i] = dp[j] + 1;
					}
				}
			}
		
			// find max
			for (int i = 0 ; i < n ; i++)	
				if (dp[i] > max)
					max = dp[i];

			System.out.println(max);
		}		
	}
}