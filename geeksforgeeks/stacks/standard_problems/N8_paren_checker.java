/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class N8_paren_checker {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
        String input;
        Stack<String> stack;
        int result = 1;
        
		while (test_cases-- > 0)	{
			input = scan.next();
            // System.out.println(input);
			stack = new Stack<>();

			for (char ch : input.toCharArray())	{
				if (ch == '(' || ch == '{' || ch == '[')
					stack.push(ch + "");
				else if (ch == ')' || ch == '}' || ch == ']')	{
					if (stack.isEmpty())	{
						result = 0;
						break;
					}
					else if (ch == ')' && stack.peek().charAt(0) == '(')	{
						stack.pop();	
					}
					else if (ch == '}' && stack.peek().charAt(0) == '{')	{
						stack.pop();	
					}
					else if (ch == ']' && stack.peek().charAt(0) == '[')	{
						stack.pop();	
					}
					else 	{
						result = 0;
						break;	
					}
				}
			} // end of for

			if (result == 0 || !stack.isEmpty())	{
				System.out.println("not balanced");
			}
			else
			    System.out.println("balanced");
			    
			stack = null;
			input = null;
			result = 1;
		} // end of while	
	}
}