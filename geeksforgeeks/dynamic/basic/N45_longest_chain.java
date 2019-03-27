import java.util.*;
import java.lang.*;
class Pair
{
    int x;
    int y;
    
    public Pair(int a, int b)
    {
        x = a;
        y = b;
    }
}
class Chainlength
{
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t-- > 0)
        {
            int n = sc.nextInt();
            Pair pr[] = new Pair[n];
            int arr[] = new int[2*n];
            for(int i = 0; i < 2*n; i++)
            {
               arr[i] = sc.nextInt();
            }
            for(int i = 0, j = 0; i < 2*n-1 && j < n; i = i+2, j++)
            {
                pr[j] = new Pair(arr[i], arr[i+1]);
            }
            GfG g = new GfG();
            System.out.println(g.maxChainLength(pr, n));
        }
    }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/


class CompareByFirst implements Comparator<Pair>
{
   public int compare(Pair a, Pair b)
    {
        return a.x - b.x;
    }
}

class GfG
{
    int maxChainLength(Pair arr[], int n)
    {
        // sorting the chain
        Arrays.sort(arr, new CompareByFirst());

        // define dp table
        int[] dp = new int[n];

        // last is one
        dp[n - 1] = 1;

        for (int i = n - 2 ; i >= 0 ; i--)  {
            dp[i] = 1;
            for (int j = i + 1 ; j < n ; j++)   {
                if (arr[i].y < arr[j].x && dp[j] + 1 > dp[i])    {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    
        int max = dp[0];
        // find max
        for (int i = 1 ; i < n ; i++)   
            if (dp[i] > max)
                max = dp[i];

        return max;

    }
}