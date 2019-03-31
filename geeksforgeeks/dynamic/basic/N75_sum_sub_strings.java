// using the method specified in the solution otherwise habe to do something similar 
// to LC SUBSTRING - whick takes n2 time
/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();

		String input;
		long[] dp;
		long result;

		while (test_cases-- > 0)	{
			input = scan.next();

			dp = new long[input.length()];
			dp[0] = input.charAt(0) - '0';
			result = dp[0];

			for (int i = 1 ; i < input.length() ; i++)	{
				dp[i] = (i + 1) * (input.charAt(i) - '0') + 10 * dp[i - 1];
			
			    result += dp[i];
			}

			System.out.println(result);
		}
	}
}