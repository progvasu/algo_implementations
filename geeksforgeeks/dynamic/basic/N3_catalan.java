/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int test_cases = scan.nextInt();
		
		// state table
		BigInteger[] cat = new BigInteger[101];


		// series[i] = series[i-1].add(series[i-2])
		
		// intialize
		cat[0] = BigInteger.ONE;
		cat[1] = BigInteger.ONE;
		
		// filling the state table
		for (int i = 2 ; i < 101 ; i++) {
		    cat[i] = BigInteger.ZERO;
		    for (int j = 0 ; j < i ; j++)
		        cat[i] = cat[i].add(cat[j].multiply(cat[i - j - 1]));
		  //  System.out.println(cat[i]);
		}
		
		int n;
		while(test_cases-- > 0) {
		    n = scan.nextInt();
		    System.out.println(cat[n]);
		}
	}
}