import java.util.*;
import java.io.*;
import java.lang.*;

class N19_dominos	{
	public static void main(String[] args) {
		// read comments to check out the solution on stackoverflow
		// till then not done
		
		int n;

		Scanner scan = new Scanner(System.in);

		n = scan.nextInt();

		// dp table
		int[] dpA = new int[n + 1];
		int[] dpB = new int[n + 1];

		// base cases
		dpA[0] = 1;
		dpA[1] = 0;
		dpB[0] = 0;
		dpB[1] = 1;

		// iterate
		for (int i = 2 ; i <= n ; i++)	{
			dpA[i] = dpA[i - 2] + 2 * dpB[i - 1];
			dpB[i] = dpA[i - 1] + dpB[i - 2]
		}

		System.out.println(dp[n]);
	}
}