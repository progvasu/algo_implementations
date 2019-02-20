// using the subset sub solution fails - (taking the modulo m)
// trying the geeks approach
// maybe this is because of repeated set values

// import java.util.*;
// import java.lang.*;
// import java.io.*;

// class GFG {
// 	public static void main (String[] args) {
// 		Scanner scan = new Scanner(System.in);

// 		int test_cases = scan.nextInt();
// 		int m, n;
// 		int[] input;

// 		while (test_cases-- > 0)	{
// 			n = scan.nextInt();
// 			m = scan.nextInt();
// 			input = new int[n];

// 			// read in the input array
// 			for (int i = 0 ; i < n ; i++)	{
// 				input[i] = scan.nextInt();
// 			}
			
// 			// number of elements in the array are greater than the sum m
// 			if (n > m)	{
// 				System.out.println("1");
// 				continue;
// 			}

// 			// take modulo m of each input element and the problem now reduces to finding
// 			// a subset whose sum is m
// 			for (int i = 0 ; i < n ; i++)	{
// 				input[i] %= m;
// 				// System.out.printf("%4d", input[i]);
// 			}

// 			// define dp table
// 			boolean[][] dp = new boolean[m + 1][n + 1];

// 			// if the sum is zero empty set is the answer
// 			for (int j = 0 ; j <= n ; j++)
// 				dp[0][j] = true;

// 			// if the set is empty ans is false
// 			for (int i = 0 ; i <= m ; i++)	
// 				dp[i][0] = false;

// 			// fill in the dp table
// 			for (int i = 1 ; i <= m ; i++)	{
// 				for (int j = 1 ; j <= n ; j++)	{
// 					dp[i][j] = dp[i][j - 1];
// 					if (i >= input[j - 1])
// 						dp[i][j] = dp[i][j] || dp[i - input[j - 1]][j - 1];
// 				}
// 			}

// 			// print the state table
// 			for (int i = 0 ; i <= m ; i++)	{
// 				for (int j = 0 ; j <= n ; j++)
// 					System.out.printf("%6b", dp[i][j]);
// 				System.out.println();
// 			}

// 			if (dp[m][n])
// 				System.out.println("1");
// 			else
// 				System.out.println("0");
// 		} // end of while
// 	}
// }



/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int m, n;
		int[] input;

		while (test_cases-- > 0)	{
			n = scan.nextInt();
			m = scan.nextInt();
			input = new int[n];

			// read in the input array
			for (int i = 0 ; i < n ; i++)	{
				input[i] = scan.nextInt();
			}
			
			// number of elements in the array are greater than the sum m
			if (n > m)	{
				System.out.println("1");
				continue;
			}

			// define the DP Table
			// this stores the modulo values we have seen so far
			boolean[] dp = new boolean[m];
			Arrays.fill(dp, false);

			for (int i = 0 ; i < n ; i++)	{
				// if modulo value hits zero this means we have find the sum divisible by m
				if (dp[0])	{
					break;
				}

				// define the temp dp table
				boolean[] temp = new boolean[m];
				Arrays.fill(temp, false);

				for (int j = 0 ; j < m ; j++)	{
					// if we have reached dp[j] before we can move forward now
					if (dp[j])
						// if it was false before make it true
						if (dp[(j + input[i]) % m] == false)
							temp[(j + input[i]) % m] =  true;
				}

				// update dp[j]
				for (int j = 0 ; j < m ; j++)
					if (temp[j])
						dp[j] = true;

				// single element can also exist
				dp[input[i] % m] = true;
			}

			if (dp[0])
				System.out.println("1");
			else
				System.out.println("0");
		} // end of while
	}
}