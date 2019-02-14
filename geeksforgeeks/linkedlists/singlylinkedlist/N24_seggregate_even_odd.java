/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int test_cases = scan.nextInt();
		int num_eles;
		LinkedList<Integer> even;
		LinkedList<Integer> odd;
		int temp;
		
		while (test_cases-- > 0)    {
		    even = new LinkedList<>();
		    odd = new LinkedList<>();
		    
		    num_eles = scan.nextInt();
		    while (num_eles-- > 0)  {
		        temp = scan.nextInt();
		        if (temp % 2 == 0)  {
		            even.add(temp);
		        }
		        else
		            odd.add(temp);
		    }
		    
		    // print out odd and even lists
		    even.addAll(odd);
		    Iterator it = even.iterator();
		    while (it.hasNext())
		        System.out.print(it.next() + " ");
		    System.out.println();  
		}
	}
}