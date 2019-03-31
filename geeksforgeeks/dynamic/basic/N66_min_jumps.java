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
		int min;

		while (test_cases-- > 0)	{
			n = scan.nextInt();

            input = new int[n];
			for (int i = 0 ; i < n ; i++)	{
				input[i] = scan.nextInt();
			}

			dp = new int[n];

			// no jump required
			dp[n - 1] = 0;

			for (int i = n - 2 ; i >= 0 ; i--)	{
				if (input[i] == 0)
					dp[i] = Integer.MAX_VALUE;
				else if (input[i] >= n - i - 1)
					dp[i] = 1;
				else 	{
					// find the min value
					min = Integer.MAX_VALUE;
					
					for (int j = i + 1 ; j < n && j <= input[i] + i ; j++)	{
						if (dp[j] < min)
							min = dp[j];
					}

                    if (min == Integer.MAX_VALUE)
                        dp[i] = Integer.MAX_VALUE;
                    else
                        dp[i] = min + 1;
				}
			}

            if (dp[0] == Integer.MAX_VALUE)
			    System.out.println(-1);
			else
			    System.out.println(dp[0]);
		}
	}
}