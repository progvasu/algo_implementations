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
		int temp, max;

		while (test_cases-- > 0)	{
			n = scan.nextInt();

			input = new int[n];
			for (int i = 0 ; i < n ; i++)	{
				input[i] = scan.nextInt();
			}

			temp = input[0];
			max = temp;

			for (int i = 1 ; i < n ; i++)	{
				if (temp < 0)	{
					temp = 0;
				}
				temp += input[i];

				if (temp > max)
					max = temp;
			}

			System.out.println(max);
		}
	}
}