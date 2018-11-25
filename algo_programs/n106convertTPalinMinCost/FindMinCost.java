package n106convertTPalinMinCost;

/**
 *
 * @author vasu
 */

public class FindMinCost {
    public static void main(String[] args) {
        // input
        String input = "ABCABBA";
        int len_str = input.length();
        
        // different costs
        int add_cost = 2;
        int rep_cost = 10;
        int rem_cost = 10;
        
        // state table
        int[][] st = new int[input.length()][input.length()];
        
        // initializing state table to zero  - purely for debugging purposes
	for (int i = 0 ; i < len_str ; i++)
            for (int j = 0 ; j < len_str ; j++)
                st[i][j] = -1;
        
        // we fill the state table diagonally
	
	// initialization
	// first - strings of length 1
	for (int i = 0 ; i < len_str ; i++)
            st[i][i] = 0;

	// second - strings of length 2
	for (int i = 0 ; i < len_str - 1 ; i++)
            if (input.charAt(i) == input.charAt(i + 1))
                st[i][i + 1] = 0;
            else
                st[i][i + 1] = Math.min(add_cost, Math.min(rep_cost, rem_cost));

	// induction
	// l here denotes the length of the substring we are considering
	int j;
        for (int l = 2 ; l < len_str ; l++)	{
            // for every row
            for (int i = 0 ; i < len_str - l ; i++)	{
                j = i + l;
                if (input.charAt(i) == input.charAt(j))
                    st[i][j] = st[i + 1][j - 1];
                else	{
                    st[i][j] = Math.min(Math.min(Math.min(st[i][j - 1] + add_cost, st[i + 1][j] + add_cost),st[i + 1][j - 1] + rep_cost)    
                                        , Math.min(st[i][j - 1] + rem_cost, st[i + 1][j] + rem_cost));
                }
            }
	}

	// printing state table

	// printing first string row
	System.out.printf("%3c", ' ');
	for (j = 0 ; j < len_str ; j++)
            System.out.printf("%3c", input.charAt(j));
	System.out.printf("\n");

	for (int i = 0 ; i < len_str ; i++)	{
            System.out.printf("%3c", input.charAt(i));

            for (j = 0 ; j < len_str ; j++)
                System.out.printf("%3d", st[i][j]);

            System.out.printf("\n");
	}
	System.out.printf("\n");
    }
}
