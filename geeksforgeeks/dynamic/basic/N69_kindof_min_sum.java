// variation of min sum java
/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class GFG {
    
    static void length(int[] arr,int k){
        Arrays.sort(arr);
        int max=0;
        int i=0,j=0;
        while(j<arr.length){
            if(arr[j]-arr[i]<=k){
                max=Math.max(j-i+1,max);
                j++;
            }else{
                i++;
            }
        }
        System.out.println(arr.length-max);
    }
    
	public static void main (String[] args) {
	    int[] arr={1, 3, 4, 9, 10, 11, 12, 17, 20};
	    int k=4;
		length(arr,k);
	}
}