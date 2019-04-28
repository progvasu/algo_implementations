// Initial Template for Java
import java.util.*;
import java.lang.*;
import java.io.*;
class gfg
{
    public static void main (String[] args) {
    Scanner sc = new Scanner(System.in);
    int t = sc.nextInt();
    
    //sc.next();
    while(t-- > 0)
    {
        int n = sc.nextInt();
        
        int A[]  =new int[1000];
        int B[] = new int[1000];
        int C[] = new int[1000];
        
        for(int i = 0; i < n; i++)
        {
            int a =sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            
            A[i] = a;
            B[i] = b;
            C[i] = c;
        }
        
        Geeks ob = new Geeks();
        System.out.println(ob.maxHeight(A,B,C,n));
    }
   }
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for Java
class Geeks {
    static class Box implements Comparable<Box>   {
        int height;
        int width;
        int length;
        int area;

        Box(int height, int width, int length)  {
            this.height = height;
            this.width = width;
            this.length = length;
            this.area = width * length;
        }  

        @Override
        public int compareTo(Box o) {
            return o.area - this.area;
        }
    }

    //
    //
    // IMPORTANT: Math.max and Math.min play an important role
    // we kind of orient the box so that longer sides match
    //
    //

    public static int maxHeight(int height[], int width[], int length[], int n) {
        // need to sort boxes in the decresaing order of their area
        List<Box> box_list = new ArrayList<>();

        for (int i = 0 ; i < n ; i++)  {
            // original box
            box_list.add(new Box(height[i], Math.max(width[i], length[i]), Math.min(width[i], length[i])));

            // first rotation
            box_list.add(new Box(width[i], Math.max(height[i], length[i]), Math.min(height[i], length[i])));

            // second rotation
            box_list.add(new Box(length[i], Math.max(width[i], height[i]), Math.min(width[i], height[i])));
        }

        // sorting
        Collections.sort(box_list);

        // dp table
        int[] dp = new int[box_list.size()];

        dp[box_list.size() - 1] = box_list.get(box_list.size() - 1).height;

        for (int i = box_list.size() - 2 ; i >= 0 ; i--)    {
            System.out.println(box_list.get(i).height + " " + box_list.get(i).width + " " + box_list.get(i).length);

            dp[i] = box_list.get(i).height;

            for (int j = i + 1 ; j < box_list.size() ; j++) {
                if (box_list.get(j).width < box_list.get(i).width && box_list.get(j).length < box_list.get(i).length && (dp[i] < (dp[j] + box_list.get(i).height)))
                    dp[i] = dp[j] + box_list.get(i).height;
            }
        }

        int max = Integer.MIN_VALUE;
        for(int i = 0 ; i < box_list.size() ; i++)  {
            if (max < dp[i])
                max = dp[i];
        }

        return max;
    }
}