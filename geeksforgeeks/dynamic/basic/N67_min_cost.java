/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int n, w;
		int[] temp;
		long[][] dp;
		int not_negones;
		int[] cost;
		int[] weight;

		while (test_cases-- > 0)	{
			not_negones = 0;

			n = scan.nextInt();
			w = scan.nextInt();

			temp = new int[n + 1];
			for (int i = 1 ; i <= n ; i++)	{
				temp[i] = scan.nextInt();

				if (temp[i] != -1)
					not_negones += 1;
			}

			cost = new int[not_negones + 1];
			weight = new int[not_negones + 1];

			for (int i = 1, j = 1 ; i <= n ; i++)	{
				if (temp[i] != -1)	{
					cost[j] = temp[i];
					weight[j++] = i;
				}
			}
			
// 			for (int i = 1 ; i <= not_negones ; i++)    {
// 			    System.out.println(cost[i] + " " + weight[i]);
// 			}

			dp = new long[w + 1][not_negones + 1];

			for (int i = 0 ; i <= w ; i++)	{
				for (int j = 0 ; j <= not_negones ; j++)	{
					if (i == 0)
						dp[i][j] = 0;
					else if (j == 0)
						dp[i][j] = Integer.MAX_VALUE;
					else if (i < weight[j])
						dp[i][j] = dp[i][j - 1];
					else 	{
						dp[i][j] = Math.min(dp[i][j - 1], cost[j] + dp[i - weight[j]][j - 1]);
					}
				}
			}

			for (int i = 0 ; i <= w ; i++)	{
				for (int j = 0 ; j <= not_negones ; j++)	{
					System.out.printf("%10d", dp[i][j]);
				}
				System.out.println();
			}

            if (dp[w][not_negones] == Integer.MAX_VALUE)
			    System.out.println(-1);
			else
			    System.out.println(dp[w][not_negones]);
		}
	}
}