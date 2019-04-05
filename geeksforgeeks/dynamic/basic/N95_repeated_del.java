// wrong predictor on the accuracy page
// below program is correct

/*package whatever //do not write package name here */

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner scan = new Scanner(System.in);
		int test_cases = scan.nextInt();
		int n;
		List<Integer> input;
		List<Integer> index_remove;
		int[] dp;
		int[] index;
		int len_lis;
		int max_index;

		while (test_cases-- > 0)	{
			n = scan.nextInt();

			// input read
			input = new ArrayList<>();
			for (int i = 0 ; i < n ; i++)	{
				input.add(scan.nextInt());
			}			
			
			do 	{
				len_lis = 1;
				
				dp = new int[input.size()];
				index = new int[input.size()];
				index_remove = new ArrayList<>();

				dp[0] = 1;
				index[0] = -1;
                max_index = 0;

				// for rest
				for (int i = 1 ; i < input.size() ; i++)	{
					// include the element itself
					dp[i] = 1;
					index[i] = -1;

					for (int j = 0 ; j < i ; j++)	{
						if ((input.get(j) < input.get(i)) && (dp[j] + 1 > dp[i]))	{
							dp[i] = dp[j] + 1;
							index[i] = j;
						}
					}
				}

				// find the length of longest LIS
				for (int i = 0 ; i < input.size() ; i++)	{
					if (dp[i] > len_lis)	{
						len_lis = dp[i];
						max_index = i;
					}
				}

				for (Integer i : input)	{
					System.out.printf("%4d", i);
				}
				System.out.println();
				System.out.println(len_lis);
				System.out.println(max_index);

				if (len_lis > 1)	{
					// get the indexes to remove in reverse order
					while (index[max_index] != -1)	{
						System.out.println("----" + max_index);
						input.remove(max_index);
						// index_remove.add(0, max_index);
						max_index = index[max_index];
					}
					input.remove(max_index);
					// index_remove.add(0, max_index);

					// for (Integer i : index_remove)	{
					// 	System.out.printf("%4d", i);
					// }
					// System.out.println();

					// remove those indexes
					// for (int i = 0 ; i < index_remove.size() ; i++)
					// 	input.remove((int)index_remove.get(i));
				}

				// for (Integer i : input)	{
				// 	System.out.printf("%4d", i);
				// }
				// System.out.println();

			} while (len_lis != 1 && input.size() != 0);

			if (input.size() != 0)	{
				for (Integer i : input)	{
					System.out.print(i + " ");
				}
				System.out.println();
			}
			else
				System.out.println(-1);
		}
	}
}