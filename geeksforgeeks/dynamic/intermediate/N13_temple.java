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
		int[] ldsl;
		int[] ldsr;
		int sum = 0;

		while(test_cases-- > 0)	{
			sum = 0;
			n = scan.nextInt();

			// read in the input
			input = new int[n];
			for (int i = 0 ; i < n ; i++)	{
				input[i] = scan.nextInt();
			}

			// define lds on the left
			ldsl = new int[n];

			ldsl[0] = 1;
			// for (int i = 1 ; i < n ; i++)	{
			// 	ldsl[i] = 1;
			// 	for (int j = i - 1 ; j >= 0 ; j--)	{
			// 		if (input[j] < input[i] && ldsl[j] + 1 > ldsl[i])
			// 			ldsl[i] = ldsl[j] + 1;
			// 	}
			// }

			// instead just need the increasing subarray not subseqeunce
			for (int i = 1 ; i < n ; i++)	{
				if (input[i - 1] < input[i])
					ldsl[i] = ldsl[i - 1] + 1;
				else
					ldsl[i] = 1;
			}

			// simmilarly for lds on the right
			ldsr = new int[n];

			ldsr[n - 1] = 1;
			// for (int i = n - 2 ; i >= 0 ; i--)	{
			// 	ldsr[i] = 1;
			// 	for (int j = i + 1 ; j < n ; j++)	{
			// 		if (input[j] < input[i] && ldsr[j] + 1 > ldsr[i])
			// 			ldsr[i] = ldsr[j] + 1;
			// 	}
			// }

			for (int i = n - 2 ; i >= 0 ; i--)	{
				if (input[i + 1] < input[i])
					ldsr[i] = ldsr[i + 1] + 1;
				else
					ldsr[i] = 1;
			}

			for (int i = 0 ; i < n ; i++)	{
				sum += Math.max(ldsl[i], ldsr[i]);
			}

			System.out.println(sum);
		}
	}
}