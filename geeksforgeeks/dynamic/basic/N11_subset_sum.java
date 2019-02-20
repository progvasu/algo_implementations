/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int[] input;
		int n, sum, temp;

		while (test_cases-- > 0)	{
			n = scan.nextInt();
			input = new int[n];
			sum = 0;
			for (int i = 0 ; i < n ; i++)	{
				temp = scan.nextInt();
				sum += temp;
				input[i] = temp;
			}

			if (sum % 2 != 0)	{
				// cannot partition an odd number
				System.out.println("NO");
				continue;
			}

			// else
			// we try find a subset whose sum is sum/2
			sum /= 2;

			// define dp table
			boolean[][] dp = new boolean[sum + 1][n + 1];

			// if the sum is zero empty set is the answer
			for (int j = 0 ; j <= n ; j++)
				dp[0][j] = true;

			// if the set is empty ans is false
			for (int i = 0 ; i <= sum ; i++)	
				dp[i][0] = false;

			// fill in the dp table
			for (int i = 1 ; i <= sum ; i++)	{
				for (int j = 1 ; j <= n ; j++)	{
					dp[i][j] = dp[i][j - 1];
					if (i >= input[j - 1])
						dp[i][j] = dp[i][j] || dp[i - input[j - 1]][j - 1];
				}
			}

			if (dp[sum][n])
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}
}