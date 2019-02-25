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
			for (int i = 0 ; i < n ; i++)	{
				temp = scan.nextInt();
				input[i] = temp;
			}
			sum = scan.nextInt();

			// define dp table
			int[][] v = new int[sum + 1][n];

			// if the sum is zero empty set is the answer
			for (int j = 0 ; j < n ; j++)
				v[0][j] = 1;

			// if the denomination is mutiple of sum we can pay using that
			for (int i = 1 ; i <= sum ; i++)	{
				if (i == input[0])
					v[i][0] = 1;
				else
					v[i][0] = 0;
			}

			// induction
			for (int j = 1 ; j < n ; j++)	{
				for (int i = 1 ; i <= sum ; i++)	{
					// initialize v[i][j] to avoid garbage values
					v[i][j] = 0;

					// we can pay at current level using both these ways
					// either include that coin and count number of ways with which we can pay the remaining
					if (i >= input[j])
						v[i][j] = v[i - input[j]][j - 1];
					
					// not include that coin and then pay
					v[i][j] += v[i][j - 1];
				}
			}

			// print out the state table
			for (int i = 0 ; i <= sum ; i++)	{
				System.out.printf("%4d", i);
				for (int j = 0 ; j < n ; j++)	{
					System.out.printf("%4d", v[i][j]);
				}
				System.out.println();
			}

			// count the sum
			System.out.println(v[sum][n - 1]);
		}
	}
}