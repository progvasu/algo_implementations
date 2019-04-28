/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int[][] adj;
		int[][] dp;
		int v;
		int temp;

		while(test_cases-- > 0)	{
			v = scan.nextInt();

			adj = new int[v][v];
			dp = new int[v][v];

			// input reading
			for (int i = 0 ; i < v ; i++)	{
				for (int j = 0 ; j < v ; j++)	{
					temp = scan.nextInt();
					// if (temp.equals("INF"))
						adj[i][j] = temp;
					// else
					// 	adj[i][j] = Integer.parseInt(temp);
					dp[i][j] = adj[i][j];
				}
			}

			// dp table
			for (int k = 0 ; k < v ; k++)	{
				for (int i = 0 ; i < v ; i++)	{
					for (int j = 0 ; j < v ; j++)	{
						if (dp[i][k] != 10000000 && dp[k][j] != 10000000 && dp[i][k] + dp[k][j] < dp[i][j])
							dp[i][j] = dp[i][k] + dp[k][j];
					}
				}
			}

			// print output
			for (int i = 0 ; i < v ; i++)	{
				for (int j = 0 ; j < v ; j++)	{
					if (dp[i][j] != 10000000)
						System.out.print(dp[i][j] + " ");
					else
						System.out.print("INF ");
				}
				System.out.println();	
			}
		}
	}
}