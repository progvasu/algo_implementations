/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class N1_ugly_nos {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int test_cases = scan.nextInt();
		int n;
		
		// could do
		// compute till 10^4
		// dynamic table
		long[] nos = new long[10000];
		
		// base cases
		nos[0] = 1;
		nos[1] = 2;
		
		// variables for dynamic
		int index_at2 = 0;
		int index_at3 = 0;
		int index_at5 = 0;
		long min;
		long curr2 = 2;
		long curr3 = 3;
		long curr5 = 5;

		// loop
		for (int i = 2 ; i < nos.length ; i++)  {
		    min = Long.MAX_VALUE;

		    // calulate the minimum
		    // for 2
		    curr2 = 2 * nos[index_at2];
		    // update it
		    while (curr2 <= nos[i - 1] && index_at2 < 9999)	{
		    	index_at2++;
		    	curr2 = 2 * nos[index_at2];
		    }
		    if (curr2 < min)
		    	min = curr2;

			// for 3
		    curr3 = 3 * nos[index_at3];
		    // update it
		    while (curr3 <= nos[i - 1] && index_at3 < 9999)	{
		    	index_at3++;
		    	curr3 = 3 * nos[index_at3];
		    }
		    if (curr3 < min)
		    	min = curr3;

		    // for 5
		    curr5 = 5 * nos[index_at5];
		    // update it
		    while (curr5 <= nos[i - 1] && index_at5 < 9999)	{
		    	index_at5++;
		    	curr5 = 5 * nos[index_at5];
		    }
		    if (curr5 < min)
		    	min = curr5;

		    nos[i] = min;		    
		}
		
		
		// then replying to queries
		while(test_cases-- > 0) {
		    n = scan.nextInt();
		    
		    System.out.println(nos[n - 1]);
		}
	}
}