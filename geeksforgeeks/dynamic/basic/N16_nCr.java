/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int test_cases = scan.nextInt();
		int n, r;
		
		while(test_cases-- > 0) {
		    n = scan.nextInt();
		    r = scan.nextInt();
		    
		    // define the dp table
		    int[][] dp = new int[n + 1][r + 1];
		    
		    for (int i = 0 ; i <= n ; i++)  {
		        for (int j = 0 ; j <= Math.min(i, r) ; j++) {
		            if (j == 0 || i == j)
		                dp[i][j] = 1;
                    else
                        dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 1000000007;
		        }
		    }
		    
		    System.out.println(dp[n][r]);
		}
	}
}