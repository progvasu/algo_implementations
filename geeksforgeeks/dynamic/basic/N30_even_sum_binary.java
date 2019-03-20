/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;


submission error not submitted


class GFG {
	public static void main (String[] args) {
		// no need of dp use combinations! simple

		Scanner scan = new Scanner(System.in);
		int test_cases = scan.nextInt();
		int n;
		int mod = 1000000007;
		int ncr = 1, res = 1;

		while (test_cases-- > 0)	{
			n = scan.nextInt();

			ncr = 1;
			res = 1;

			for (int r = 1 ; r <= n ; r++)	{
				ncr = (ncr * (n + 1 - r) / r) % mod;

				res += (ncr * ncr) % mod;
			}

			System.out.println(res);
		}
	}
}