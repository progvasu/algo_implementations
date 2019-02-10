/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class N9_next_greater {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int array_length;
		long[] input;
		long[] output;
		Stack<Integer> stack;

		while (test_cases-- > 0)	{
			array_length = scan.nextInt();
			input = new long[array_length];
			output = new long[array_length];
			stack = new Stack<>();
			for (int i = 0 ; i < array_length ; i++)	{
				input[i] = scan.nextLong();
			}

			// push first element
			stack.push(0);

			for (int i = 1 ; i < array_length ; i++)	{
				while (!stack.isEmpty() && input[stack.peek()] < input[i])	{
					output[stack.pop()] = input[i];
				}

				stack.push(i);
			}

			// for all the remaining elements on the stack rmin = -1
			while (!stack.isEmpty())
				output[stack.pop()] = -1;

			// printing the result
			for (long i : output)
				System.out.print(i + " ");
			System.out.println();
		}
	}
}