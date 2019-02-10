/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class N7_stock_span {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int array_len;
		int[] input;

		while (test_cases-- > 0)	{
			array_len = scan.nextInt();
			input = new int[array_len];
			for (int i = 0 ; i < array_len ; i++)
				input[i] = scan.nextInt();

			// creating stack
			Stack<Integer> stack = new Stack<>();

			// will directly print the span values
			// always one for first element
			System.out.print("1 ");
			stack.push(0);

			for (int i = 1 ; i < array_len ; i++)	{
				while (!stack.isEmpty() && input[stack.peek()] <= input[i])
					stack.pop();

				if (stack.isEmpty())
					System.out.print(i + 1);
				else
					System.out.print(i - stack.peek());

				stack.push(i);
				System.out.print(" ");
			}

			System.out.println();
		}
	}
}