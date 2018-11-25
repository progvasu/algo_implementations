package n103flipLUMaxOnes;

/**
 *
 * @author vasu
 */

public class FlipLU {
    public static void main(String[] args)  {
        // input
        int[] input = new int[]{1, 0, 1, 0, 0, 1, 0, 1};
        
        // print input
        for(int i = 0 ; i < input.length ; i++)
            System.out.printf("%4d", i);
        System.out.println("  Index");
        for(int i : input)  {
            System.out.printf("%4d", i);
        }
        System.out.println("  Input");
        
        // we convert zeros to one and one to -1 and the problem now reduces to finding
        // max sum sub array
        // could do it another way also keep two pointers l and u and adjust them so that
        // #0 - #1 between l and u are maximum - this is kind of similar to above approach
        // and the former is a little elegant too
        
        for (int i = 0 ; i < input.length ; i++)    {
            if (input[i] == 1)
                input[i] = -1;
            else
                input[i] = 1;
        }
        
        // modified input
        for(int i : input)  {
            System.out.printf("%4d", i);
        }
        System.out.println("  Minput");
        
        // running max sum subarray
        int sum = 0, max = 0;
	int left = -1, right = -1;
	int temp = 0;
	for (int j = 0 ; j < input.length ; j++)	{
            sum = sum + input[j];
            if (sum > max)	{
                max = sum;
                right = j;
                left = temp;			
            }

            if (sum <= 0)	{
                sum = 0;
                temp = j + 1;
            }
	}

	System.out.printf("\nLeft  = %d, Right = %d\n", left, right);
    }
}
