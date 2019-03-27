import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);

		int test_cases = scan.nextInt();
		int n, k;
		int[] input;
		int max_sum = 0;

		while (test_cases-- > 0)	{
			n = scan.nextInt();

			input = new int[n];
			for (int i = 0 ; i < n ; i++)	{
				input[i] = scan.nextInt();
			}

			k = scan.nextInt();

			max_sum = 0;

			Arrays.sort(input);

			// traverse from right
			for (int i = n - 1 ; i >= 1 ; i--)	{
				// try pairing i with i - 1
				if ((input[i] - input[i - 1]) < k)	{
					max_sum += input[i] + input[i - 1];
					i = i - 1;
				}
			}
		
			System.out.println(max_sum);
		}
	}
}