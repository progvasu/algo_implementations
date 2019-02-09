import java.util.*;
import java.io.*;

class N4_postfix_prefix	{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		String input = scan.next();
		int input_length = input.length();
		char ch;
		Stack<String> stack = new Stack<>();
			
		// writing code directly in main
		for (int i = 0; i < input_length ; i++)	{
			ch = input.charAt(i);

			if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')	{
				// pop two operands from stack
				String op1 = stack.pop();
				String op2 = stack.pop();
				stack.push(ch + op2 + op1);
			}
			else 
				stack.push(ch + "");
		}

		System.out.println(stack.pop());
	}
}
