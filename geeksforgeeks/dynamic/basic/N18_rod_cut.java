/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int test_cases = scan.nextInt();
		int n;
		int[] price;
		int temp;
		
		while(test_cases-- > 0) {
		    // read in the input
		    n = scan.nextInt();
		    price = new int[n];
		    for(int i = 0 ; i < n ; i++)
		        price[i] = scan.nextInt();
		        
		    
		    // simple dynamic table
		    // optimal price of rod length k
		    int[] dp = new int[n + 1];

		    // price of rod of length 0 is zero
		    // price of rod of length 1 is price[0]
		    dp[0] = 0;
		    dp[1] = price[0];
		    int max;

		    for (int i = 2 ; i <= n ; i++)	{
		    	max = Integer.MIN_VALUE;
		    	for (int j = 0 ; j < i ; j++)	{
		    		max = Math.max(max, price[j] + dp[i - j - 1]);
		    	}
		    	dp[i] = max;
		    }

		    System.out.println(dp[n]);
		}
	}
}