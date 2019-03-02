/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int test_cases = scan.nextInt();
		int n, k;
		int mod = 1000000007;
		
		while(test_cases-- > 0) {
		    n = scan.nextInt();
		    k = scan.nextInt();
		    
		    // dp table
		    long[] diff = new long[n + 1];
		    
		    // base cases
		    diff[1] = k;
		    diff[2] = k * (k - 1);

		    for (int i = 3 ; i <= n ; i++)  {
		        diff[i] = (((diff[i - 1] + diff[i - 2]) % mod) * (k - 1)) % mod;
		    }
		    
		    System.out.println((diff[n] + diff[n - 1]) % mod);
		}
	}
}