/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		int test_cases = scan.nextInt();
		String input;
		Stack<Integer> stack;
		int val1, val2;
		
		while (test_cases-- > 0)    {
		    input = scan.next();
		    stack = new Stack<>();
		    
		    for (char ch : input.toCharArray()) {
		        if (ch >= '0' && ch <= '9')
		            stack.push(ch-'0');
		        else    {
		            val1 = stack.pop();
		            val2 = stack.pop();
		            
		            switch (ch) {
		                case '+':
		                    stack.push(val1 + val2);
		                    break;
		                case '-':
		                    stack.push(val2 - val1);
		                    break;
		                case '*':
		                    stack.push(val1 * val2);
		                    break;
		                case '/':
		                    stack.push(val2 / val1);
		                    break;
		            }
		        }
		    }
		    
		    System.out.println(stack.pop());
		}
	}
}