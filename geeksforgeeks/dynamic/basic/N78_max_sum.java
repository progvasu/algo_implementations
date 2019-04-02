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

		while (test_cases-- > 0)	{
			n = scan.nextInt();

			input = new int[n];
			for (int i = 0 ; i < n ; i++)
				input[i] = scan.nextInt();

            dp = new int[n];
            
            if (n == 1) {
                System.out.println(input[0]);
                continue;
            }
            
			dp[0] = input[0];
			dp[1] = Math.max(input[0], input[1]);

			for (int i = 2 ; i < n ; i++)	{
				dp[i] = Math.max(dp[i - 1], input[i] + dp[i - 2]);
			}

			System.out.println(dp[n - 1]);
		}
	}
}