/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int n;
		int[][] input;
		int[][] dp;

		while(test_cases-- > 0)	{
			n = scan.nextInt();

			input = new int[n][n];
			for (int i = 0 ; i < n ; i++)	{
				for (int j = 0 ; j < n ; j++)	{
					input[i][j] = scan.nextInt();
				}
			}

			// dp table
			dp = new int[n][n];

			// first row is same
			for (int j = 0 ; j <)
		}
	}
}