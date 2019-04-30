// problem requires a little different DP table

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		String input;
		int n, start, length;

		// we need the longest substring so the dp table looks a little different here
		boolean[][] dp;

		while(test_cases-- > 0)	{
			input = scan.next();

			n = input.length();
			dp = new boolean[n][n];

			// base cases
			// for unit length strings
			for (int i = 0 ; i < n ; i++)	{
				dp[i][i] = true;
			}

			start = 0;
			length = 1;

			// for strings of length 2
			for (int i = 0 ; i < n - 1 ; i++)	{
				if (input.charAt(i) == input.charAt(i + 1))	{
					dp[i][i + 1] = true;

					if (length != 2)	{
						start = i;
						length = 2;
					}
				}
			}

			int k;
			// recursion
			for (int l = 2 ; l < n ; l++)	{
				for (int i = 0 ; i < n - l ; i++)	{
					k = i + l;

					if (input.charAt(i) == input.charAt(k) && dp[i + 1][k - 1])	{
						dp[i][k] = true;

						if (length < (l + 1))	{
							start = i;
							length = l + 1;
						}
					}
				}
			}

			System.out.println(input.substring(start, start + length));
		}
	}
}