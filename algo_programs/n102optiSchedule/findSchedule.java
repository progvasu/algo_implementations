package n102optiSchedule;
        
/**
 *
 * @author vasu
 */

public class findSchedule {
    public static void main(String[] args)  {
        // schedule for 10 days
        int no_days = 10;
        
        // cost of switching stores
        int c = 10;
        
        // cost of staying at store A or B on day i
        int[] pA = new int[]{12, 6, 21, 8, 15, 9, 10, 13, 2, 5};
        int[] pB = new int[]{7, 13, 10, 5, 22, 8, 9, 19, 13, 2};
        
        // state table's
        // tX[i] give's max profit for days i..n
        int[] tA = new int[no_days];
        int[] tB = new int[no_days];
        
        // backtracking table
        char[] backT = new char[no_days];
        
        // initialization
        // using defn of tX we know max profit for nth day (a single day) will be profit for
        // just the nth day
        tA[no_days - 1] = pA[no_days - 1];
        tB[no_days - 1] = pB[no_days - 1];
        
        // doesn't work?
//        if (tA[no_days - 1] > tB[no_days - 1])
//            backT[no_days - 1] = 'A';
//        else
//            backT[no_days - 1] = 'B';
//        
        // induction - we fill the state tables in reverse
        for(int i = no_days - 2 ; i >= 0 ; i--) {
            // sum of profits for staying at store A on ith day and 
            // max of profits for staying on the 'i + 1'th day on A or moving to B
            tA[i] = pA[i] + Math.max(tA[i + 1], tB[i + 1] - c);
            
            // similarly for tB
            tB[i] = pB[i] + Math.max(tB[i + 1], tA[i + 1] - c);
            
            // backtracking table - doesn't work?
//            if (tA[i] > tB[i])  {
//                if (tA[i + 1] > (tB[i + 1] - c))
//                    backT[i + 1] = 'A';
//                else
//                    backT[i + 1] = 'B';
//            }
//            else    {
//                if (tB[i + 1] > (tA[i + 1] - c))
//                    backT[i + 1] = 'B';
//                else
//                    backT[i + 1] = 'A';
//            }
        }
        
        if (tA[0] > tB[0])
            backT[0] = 'A';
        else
            backT[0] = 'B';
        
        // bactracking table
        for (int i = 1 ; i < no_days ; i++) {
            // need to find where the value at (i - 1)th day comes from
            if (backT[i - 1] == 'A')   {
                if (tA[i] > tB[i] - c)
                    backT[i] = 'A';
                else
                    backT[i] = 'B';
            }
            else    {
                if (tB[i] > tA[i] - c)
                    backT[i] = 'B';
                else
                    backT[i] = 'A';
            }
        }
        
        // print state tables
        for (int i = 0 ; i < no_days ; i++)
            System.out.printf("%4d", i + 1);
        System.out.println("  Days");
        for (int i = 0 ; i < no_days ; i++)
            System.out.printf("%4d", pA[i]);
        System.out.println("  pA");
        for (int i = 0 ; i < no_days ; i++)
            System.out.printf("%4d", pB[i]);
        System.out.println("  pB");
        for (int i = 0 ; i < no_days ; i++)
            System.out.printf("%4d", tA[i]);
        System.out.println("  tA");
        for (int i = 0 ; i < no_days ; i++)
            System.out.printf("%4d", tB[i]);
        System.out.print("  tB\n");
        for (int i = 0 ; i < no_days - 1; i++)
            System.out.printf("%4c", backT[i]);
        System.out.printf("%4c", backT[no_days - 1]);
        System.out.print("  Schd\n");
        
        // answer
        System.out.println("\nMax Profit which can be made: " + Math.max(tA[0], tB[0]));
    }
}
