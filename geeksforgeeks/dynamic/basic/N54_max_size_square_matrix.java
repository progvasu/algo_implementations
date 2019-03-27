import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int m, n;
		int[][] input;
		int[][] dp;
		int max_val = 0;

		while (test_cases-- > 0)	{
			max_val = 0;

			m = scan.nextInt();
			n = scan.nextInt();

			input = new int[m][n];
			for (int i = 0 ; i < m ; i++)	{
				for (int j = 0 ; j < n ; j++)	{
					input[i][j] = scan.nextInt();
				}
			}

			// define the dp table
			// one method is to define two dp tables
			// one that counts number of consecutive ones in rows
			// one that counts number of consecutive ones in columns
			// we find the max where the individual values of this matrix matches

			// other way is to combine the above two steps
			// like this
			dp = new int[m][n];

			// copy first row
			for (int j = 0 ; j < n ; j++)   {
				dp[0][j] = input[0][j];
			    if (dp[0][j] == 1)
			        max_val = 1;
			}

			// copy first column
			for (int i = 0 ; i < m ; i++)   {
				dp[i][0] = input[i][0];
			    if (dp[i][0] == 1)
			        max_val = 1;
			}

			// rest of the matrix
			for (int i = 1; i < m ; i++)	{
				for (int j = 1 ; j < n ; j++)	{
					if (input[i][j] == 1)	{
						dp[i][j] = Math.min(Math.min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
					}
					else
						dp[i][j] = 0;

					if (dp[i][j] > max_val)
						max_val = dp[i][j];
				}
			}

			System.out.println(max_val);
		}
	}
}