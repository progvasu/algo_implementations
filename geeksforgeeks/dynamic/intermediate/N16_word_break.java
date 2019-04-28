// very interesting problem
// take the example
// "forsamsungro"
// dictionary
// {"for", "sam", "samsung", "ro"}

/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int n;
		List<String> store;
		String input;
		boolean[] dp;
		int result;

		while (test_cases-- > 0)	{
			result = 0;
			n = scan.nextInt();

			store = new ArrayList<>();
			for (int i = 0 ; i < n ; i++)	{
				store.add(scan.next());
			}

			input = scan.next();

			dp = new boolean[input.length()];

			for (int i = 0 ; i < input.length() ; i++)	{
				if (dp[i] == false && store.contains(input.substring(0, i + 1)))
					dp[i] = true;

				if (i == (input.length() - 1) && dp[i] == true)	{
					result = 1;
					break;
				}

				if (dp[i] == true)
					for (int j = i + 1 ; j < input.length() ; j++)	{
						if (dp[j] == false && store.contains(input.substring(i + 1, j + 1)))
							dp[j] = true;

						if (j == (input.length() - 1) && dp[j] == true)	{
							result = 1;
							break;
						}
					}

				if (result == 1)
					break;
			}

			System.out.println(result);
		}
	}
}