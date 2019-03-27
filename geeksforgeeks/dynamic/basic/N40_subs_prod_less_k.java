import java.util.*;
import java.lang.*;

public class N40_subs_prod_less_k	{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int n = scan.nextInt();
		int[] input = new int[n];

		for (int i = 0 ; i < n ; i++)	{
			input[i] = scan.nextInt();
		}	

		int k = scan.nextInt();

		// dp table
		int[][] dp = new int[k + 1][n];

		// initial first row
		for (int j = 0 ; j < n ; j++)	{
			dp[0][j] = 0;
		}

		// first column
		for (int i = 0 ; i <= k ; i++)	{
			if (input[0] <= i)
				dp[i][0] = 1;
			else
				dp[i][0] = 0;
		}

		// induction
		for (int i = 1 ; i <= k ; i++)	{
			for (int j = 1 ; j < n ; j++)	{
				// without using the jth term
				dp[i][j] = dp[i][j - 1];

				// is using the jth term possible
				if (input[j] <= i)	{
					dp[i][j] += dp[i / input[j]][j - 1] + 1;
				}
			}
		}

		// print the state table
		for (int i = 0 ; i <= k ; i++)	{

		}

		System.out.println("Result: " + dp[k][n - 1]);
	}
}