// super easy just like coin exchange

/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main (String[] args) {
        Scanner scan = new Scanner(System.in);

        int test_cases = scan.nextInt();
        int n;
        int[] input;
        boolean[][] dp;
        int sum;

        while (test_cases-- > 0)    {
            n = scan.nextInt();
            sum = 0;
            input = new int[n];

            for (int i = 0 ; i < n ; i++)   {
                input[i] = scan.nextInt();
                sum += input[i];
            }

            if (sum % 2 != 0)   {
                System.out.println("NO");
                continue;
            }

            sum = sum / 2;

            dp = new boolean[sum + 1][n + 1];

            // first row
            for (int j = 0 ; j <= n ; j++)  {
                dp[0][j] = true;
            }

            // first column
            for (int i = 1 ; i <= sum ; i++)    {
                dp[i][0] = false;
            }

            // induction
            for (int i = 1 ; i <= sum ; i++)    {
                for (int j = 1 ; j <= n ; j++)  {
                    dp[i][j] = dp[i][j - 1];

                    if (i >= input[j - 1])  {
                        dp[i][j] = dp[i][j] || dp[i - input[j - 1]][j - 1];
                    }
                }
            }

            if (dp[sum][n])
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}