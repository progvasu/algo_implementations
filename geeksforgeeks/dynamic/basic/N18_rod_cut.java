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
		        
		    
		    // define the dp table
		    int[][] dp = new int[n + 1][n + 1];
		    
		    // initialize diagonal
		    for (int i = 1 ; i <= n ; i++)
		        dp[i][i] = 0;
		    // for rod of length 1
		    for (int i = 1 ; i < n ; i++)
		        dp[i][i+1] = price[0];
		        
		    for (int l = 2 ; l <= n ; l++)  {
		        for (int i = 1 ; i <= n - l; i++)  {
		            int j = i + l;

		            // initial value price of this full length rod
		            dp[i][j] = price[j - i - 1];

		            for (int k = i + 1 ; k < j ; k++)	{
		            	temp = dp[i][k] + dp[k][j];
		            	if (temp > dp[i][j])	{
		            		dp[i][j] = temp;
		            	}
		            }
		        }
		    }

		    // print the state table
			for (int i = 1 ; i <= n ; i++)	{
				System.out.printf("%4d", i);
				for (int j = 1 ; j <= n ; j++)	{
					System.out.printf("%4d", dp[i][j]);
				}
				System.out.println();
			}


		    System.out.println(dp[1][n]);
		}
	}
}