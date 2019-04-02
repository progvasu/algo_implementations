/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int[] scores = new int[]{3, 5, 10};
		int n;
		int[][] dp;

		while(test_cases-- > 0)	{
			n = scan.nextInt();

			dp = new int[n + 1][4];

			// intialize
			// first row
			// sum = 0
			for (int j = 0 ; j < 4 ; j++)	{
				dp[0][j] = 1;
			}

			// first column - no coins - 0 ways possible
			for (int i = 1 ; i < n ; i++)	{
				dp[i][0] = 0;
			}

			// induction
			for (int i = 1 ; i <= n ; i++)	{
				for (int j = 1 ; j < 4 ; j++)	{
					// not using jth score
					dp[i][j] = dp[i][j - 1];

					if (i - scores[j - 1] >= 0)	{
						dp[i][j] += dp[i - scores[j - 1]][j];
					}
				}
			}

			System.out.println(dp[n][3]);
		}
	}
}


// easy method
// int table[] = new int[n + 1], i; 
      
//         // Initialize all table values as 0 
//         Arrays.fill(table, 0); 
      
//         // Base case (If given value is 0) 
//         table[0] = 1; 
      
//         // One by one consider given 3  
//         // moves and update the table[] 
//         // values after the index greater  
//         // than or equal to the value of  
//         // the picked move 
//         for (i = 3; i <= n; i++) 
//             table[i] += table[i - 3]; 
//         for (i = 5; i <= n; i++) 
//             table[i] += table[i - 5]; 
//         for (i = 10; i <= n; i++) 
//             table[i] += table[i - 10]; 
      
//         return table[n]; 