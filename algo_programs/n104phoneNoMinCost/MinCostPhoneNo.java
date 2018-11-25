package n104phoneNoMinCost;

import com.sun.org.apache.xalan.internal.xsltc.compiler.util.Type;
import java.util.ArrayList;
import java.util.EnumSet;
import java.util.List;

/**
 *
 * @author vasu
 */

public class MinCostPhoneNo {
    public static void main(String[] args)    {
        // input - 1
        // digits cost
        int[] cost = new int[]{3, 2, 2, 3, 2, 1, 1, 2, 3, 3};
        // phone number
        String phone_no = "171";
        
        // input - 2
        // digits cost
//        int[] cost = new int[]{3, 2, 3, 1, 1, 1, 1, 3, 1, 2};
//        // phone number
//        String phone_no = "16";
        
        // input 3
//        // digits cost
//        int[] cost = new int[]{3, 3, 3, 1, 3, 1, 1, 2, 3, 2};
//        // phone number
//        String phone_no = "43";
        
        // print input
        for(int i = 0 ; i < cost.length ; i++)
            System.out.printf("%3d", i);
        System.out.println("  Digit");
        for(int i : cost)
            System.out.printf("%3d", i);
        System.out.println("  Org Cost");
        
        // getting the numbers print
        List<String> backT = new ArrayList<>();
        // initializing to there Digits only
        for (int i = 0 ; i < cost.length ; i++)  {
            backT.add(i, String.valueOf(i));
        }
        
        // since we have mode 10 in our answer we have to produce single digit
        // of the number at a time - for this we optimize the cost of producing a
        // number
        // we find the min cost of producing a single digit
        boolean ok = true;
        while (ok)   {
            ok = false;
            for(int i = 0 ; i < cost.length ; i++)  {
                for (int j = 0 ; j < cost.length ; j++) {
                    if (cost[(i + j) % 10] > cost[i] + cost[j]) {
                        cost[(i + j) % 10] = cost[i] + cost[j];
                        ok = true;
                        // update how to string is formed
                        backT.set((i + j) % 10, backT.get(i) + " + " + backT.get(j));
                    }
                }
            }
        }
        
        // Modified Cost
        for(int i : cost)
            System.out.printf("%3d", i);
        System.out.println("  Modified Cost\n");
        
        int no_cost = 0;
        // cost of printing the phone number
        for (char no : phone_no.toCharArray())    {
            no_cost += cost[no - '0'];
        }
        
        // print how digits are formed
        for (int i = 0 ; i < cost.length ; i++)    {
            System.out.println("Digit " + i + ": " + backT.get(i));
        }
        
        // print result
        System.out.println("\nMinimum Cost of printing the number: " + no_cost);
    }
}
