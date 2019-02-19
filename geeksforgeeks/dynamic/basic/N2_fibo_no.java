/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		int test_cases = scan.nextInt();
		
		// since N <= 1000
		// we juts use the simplest method available to us
		// state table
	    long[] dp = new long[1000];
		
		// base cases
		dp[0] = 0;
		dp[1] = 1;
		
		for (int i = 2 ; i < 1000 ; i++)
		    dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
		    
		int n;
		while (test_cases-- > 0)    {
		    n = scan.nextInt();
		    System.out.println(dp[n]);
		}
	}
}