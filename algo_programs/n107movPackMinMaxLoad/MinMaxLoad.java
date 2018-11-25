package n107movPackMinMaxLoad;

/**
 *
 * @author vasu
 */

public class MinMaxLoad {
    public static void main(String[] args) {
        // input - 1
//        int[] pack = new int[]{5, 10, 21, 20};
//        int no_movers = 2;
        
        // input - 2
//        int[] pack = new int[]{1, 1, 1, 2, 1};
//        int no_movers = 5;
        
        // input - 3
        int[] pack = new int[]{200, 25, 974, 564, 429};
        int no_movers = 2;
                
        // cumulative sum
        int[] cs = new int[pack.length];
        cs[0] = pack[0];
        for (int i = 1 ; i < cs.length ; i++)   {
            cs[i] = cs[i - 1] + pack[i];
        }
         
        // state table
        int[][] dp = new int[no_movers][pack.length];
        
        // initialization first row
        for (int j = 0 ; j < pack.length ; j++)
            dp[0][j] = cs[j];
        
        // induction
        for (int i = 1 ; i < no_movers ; i++)   {
            for (int j = 0 ; j < pack.length ; j++)   {
                int temp = 9999;
                for (int k = j - 1 ; k >= 0 ; k--)  {
                    // max weight a mover carries
                    int temp2 = Math.max(dp[i - 1][k], cs[j] - cs[k]);
                    // minimum over all max weights possibilities
                    temp = Math.min(temp, temp2);
                }
                if (temp != 9999)
                    dp[i][j] = temp;
                else
                    dp[i][j] = 0;
            }
        }
        
        // print state table
        // printing packages
        System.out.println("State Table: ");
	System.out.printf("%6c", ' ');
	for (int j = 0 ; j < pack.length ; j++)
            System.out.printf("%6d", pack[j]);
	System.out.printf("\n");

	for (int i = 0 ; i < no_movers ; i++)	{
            System.out.printf("%6d", i + 1);

            for (int j = 0 ; j < pack.length ; j++)
                System.out.printf("%6d", dp[i][j]);

            System.out.printf("\n");
	}
	System.out.println("");
        
        System.out.println("Maximum Weight to be carried: " + dp[no_movers - 1][pack.length - 1]);
    }
}
