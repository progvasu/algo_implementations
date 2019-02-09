import java.util.*;
import java.io.*;

class N3_prefix_postfix	{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String input = scan.next();
		int input_length = input.length();
		char ch;
		Stack<String> stack = new Stack<>();
			
		// writing code directly in main
		for (int i = input_length - 1 ; i >= 0 ; i--)	{
			ch = input.charAt(i);

			if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')	{
				// pop two operands from stack
				String op1 = stack.pop();
				String op2 = stack.pop();
				stack.push(op1 + op2 + ch);
			}
			else 
				stack.push(ch + "");
		}

		System.out.println(stack.pop());
	}
}