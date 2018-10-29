// find the longest common subsequence between two given substrings

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	char *str1 = "ABCABBA";
	char *str2 = "CBABACA";

	// char *str1 = "AGGTAB";
	// char *str2 = "GXTXAYB";

	// char *str1 = "ABCDGH";
	// char *str2 = "AEDFHR";

	// char *str1 = "ABC";
	// char *str2 = "AC";

	int len1 = 0, len2 = 0;

	while (str1[len1] != '\0') len1++;
	while (str2[len2] != '\0') len2++;

	// printing out input
	printf("input string 1 = %s, length = %d\n", str1, len1);
	printf("input string 2 = %s, length = %d\n\n", str2, len2);

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

	// printing out the state table
	// printing out the column string
	printf("%4c", ' ');
	for (j = 0 ; j < len2 ; j++)
		printf("%4c", str2[j]);
	printf("\n");

	// printing out the table
	for (i = 0 ; i < len1 ; i++)	{
		printf("%4c", str1[i]);
		for (j = 0 ; j < len2 ; j++)	{
			printf("%4d", l[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int length = l[len1 -1][len2 -1];
	printf("Length of the longest common substring = %d\n\n", length);

	// backtracking - to get the longest subsequence //
	
	i = len1 - 1;
	j = len2 - 1;

	char result[length];

	while(i > 0 && j > 0)	{
		if (str1[i] == str2[j])	{
			result[--length] = str1[i];
			i--;
			j--;
		}
		else	{
			if (l[i - 1][j] <= l[i][j - 1])
				j--;
			else
				i--;
		}
	}

	// we reached first row or column and if its value is 1 we have a match
	if (i == 0)	{
		// we reached first row
		if (l[0][j] == 1)
			// str1[0] was a match
			result[--length] = str1[0];
	}
	else if (j == 0)	{
		// we reached first column
		if (l[i][0] == 1)
			// str2[0] was a match
			result[--length] = str2[0];	
	}

	printf("Longest subseqeunce: %s", result);
	printf("\n\n");

	// space optimized version - works but just for finding the length of the LCS

	// state table using only two rows
	int so[2][len2];

	// to iterate between rows to be filled
	int row_1 = 0, row_2 = 1, temp;

	// printing out the state table
	// printing out the column string
	printf("%4c", ' ');
	for (j = 0 ; j < len2 ; j++)
		printf("%4c", str2[j]);
	printf("\n");

	// we print the entire state table side by side

	// intialization - first row
	printf("%4c", str1[0]);
	for (j = 0 ; j < len2 ; j++)	{
		if (str2[j] != str1[0])
			so[row_1][j] = 0;
		else	{
			// rest all will be ones
			break;
		}
		printf("%4d", so[row_1][j]);	
	}

	while (j < len2)	{
		so[row_1][j++] = 1;	
		printf("%4d", so[row_1][j - 1]);
	}
	printf("\n");

	// first column for row_1
	if (str1[0] == str2[0])
		so[row_1][0] = 1;
	else
		so[row_1][0] = 0;

	// induction step
	for (i = 1 ; i < len1 ; i++)	{
		printf("%4c", str1[i]);

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

		// printing first column
		printf("%4d", so[row_1][0]);
		
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
			printf("%4d", so[row_1][j]);
		}

		printf("\n");
	}
	printf("\n");

	int length2 = so[row_1][len2 -1];
	printf("Length of the longest common substring = %d\n\n", length2);

	return 0;
}