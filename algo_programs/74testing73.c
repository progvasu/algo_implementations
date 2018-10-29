// testing - finding the LENGTH of longest common subsequence between two given substrings

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	srand(time(0));

	int iter = 10000;

	while(iter--)	{
		// randomly generating strings
		int len1 = 3 + rand() % 20;
		int len2 = 3 + rand() % 20;

		char str1[len1 + 1], str2[len2 + 1];

		int k;

		// first string
		for (k = 0 ; k < len1 ; k++)	{
			str1[k] = 65 + (rand() % 26);
		}
		str1[k] = '\0';
		// second string
		for (k = 0 ; k < len2 ; k++)
			str2[k] = 65 + (rand() % 26);
		str2[k] = '\0';

		// state table
		int l[len1][len2], i, j;

		// intialization - first column
		for (i = 0 ; i < len1 ; i++)	{
			if (str1[i] != str2[0])
				l[i][0] = 0;
			else
				// rest all will be ones
				break;
		}

		while (i < len1)
			l[i++][0] = 1;

		// intialization - first row
		for (j = 0 ; j < len2 ; j++)	{
			if (str2[j] != str1[0])
				l[0][j] = 0;
			else
				// rest all will be ones
				break;
		}

		while (j < len2)
			l[0][j++] = 1;	

		// induction step
		for (i = 1 ; i < len1 ; i++)	{
			for (j = 1 ; j < len2 ; j++)	{
				if (str1[i] == str2[j])	{
					l[i][j] = 1 + l[i - 1][j -1];
				}
				else	{
					if (l[i - 1][j] <= l[i][j - 1])
						l[i][j] = l[i][j - 1];
					else
						l[i][j] = l[i - 1][j];
				}
			}
		}

		int length1 = l[len1 -1][len2 -1];
		
		// space optimized version - works but just for finding the length of the LCS - can't backtrack

		// state table using only two rows
		int so[2][len2];

		// to iterate between rows to be filled
		int row_1 = 0, row_2 = 1, temp;

		// we print the entire state table side by side

		// intialization - first row
		for (j = 0 ; j < len2 ; j++)	{
			if (str2[j] != str1[0])
				so[row_1][j] = 0;
			else	{
				// rest all will be ones
				break;
			}
		}

		while (j < len2)	{
			so[row_1][j++] = 1;	
		}

		// first column for row_1
		if (str1[0] == str2[0])
			so[row_1][0] = 1;
		else
			so[row_1][0] = 0;

		// induction step
		for (i = 1 ; i < len1 ; i++)	{
			// switch rows
			temp = row_1;
			row_1 = row_2;
			row_2 = temp;

			// populating first column for every iteration
			// it is equal to one if previous column value was one or the current character matches
			if (so[row_2][0] == 1 || str1[i] == str2[0])
				so[row_1][0] = 1;
			else
				so[row_1][0] = 0;
		
			for (j = 1 ; j < len2 ; j++)	{
				if (str1[i] == str2[j])	{
					so[row_1][j] = 1 + so[row_2][j -1];
				}
				else	{
					if (so[row_2][j] <= so[row_1][j - 1])
						so[row_1][j] = so[row_1][j - 1];
					else
						so[row_1][j] = so[row_2][j];
				}
			}
		}
	
		int length2 = so[row_1][len2 -1];
		
		// check if the answers match
		if (length1 != length2)	{
			printf("ERROR\n");

			// printing out input
			printf("input string 1 = %s, length = %d\n", str1, len1);
			printf("input string 2 = %s, length = %d\n\n", str2, len2);

			printf("Length of the longest common substring = %d\n\n", length1);
			printf("Length of the longest common substring = %d\n\n", length2);

			break;
		}
	}

	return 0;
}


