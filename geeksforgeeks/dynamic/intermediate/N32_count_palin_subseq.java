import java.util.*;
class Palindromic_Strings
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();
		while(t>0)
		{
			String str = sc.nextLine();
			//System.out.println(str.length());
			GfG g  = new GfG();
			System.out.println(g.countPS(str));
		t--;
		}
	}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete below method */
class GfG
{
    long countPS(String str)
    {
    	// length of the input
    	int n = str.length();

        // define the dp table
        long[][] dp = new long[n][n];

        // base cases
        // single character
        for (int i = 0 ; i < n ; i++)	{
        	dp[i][i] = 1;
        }

        // two characters
        for (int i = 0 ; i < n - 1 ; i++)	{
        	if (str.charAt(i) == str.charAt(i + 1))	{
        		dp[i][i + 1] = 3;
        	}
        	else 	{
        		dp[i][i + 1] = 2;
        	}
        }

        int k;

        // recurse for l = 2 to n
        for (int l =  2 ; l < n ; l++)	{
        	for (int i = 0 ; i < n - l ; i++)	{
        		k = i + l;

        		if (str.charAt(i) == str.charAt(k))	{
        			dp[i][k] = dp[i + 1][k] + dp[i][k - 1] + 1;
        		}
        		else 	{
        			dp[i][k] = dp[i + 1][k] + dp[i][k - 1] - dp[i + 1][k - 1];
        		}
        	}
        }

        return dp[0][n - 1];
    }
}