// testing - finding the LENGTH of longest common subsequence between two given substrings

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	srand(time(0));

	// randomly generating strings
	int len1 = 3 + rand() % 20;
	int len2 = 3 + rand() % 20;

	char str1[len1 + 1], str2[len2 + 1];

	int k;

	// first string
	for (k = 0 ; k < len1 ; k++)	{
		str1[k] = 65 + (rand() % 26);
		printf("%d ", str1[k]);
	}
	str1[k] = '\0';
	// second string
	for (k = 0 ; k < len2 ; k++)
		str2[k] = 65 + (rand() % 26);
	str2[k] = '\0';

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

	// space optimized version - works but just for finding the length of the LCS

	// state table using only two rows
	int so[2][len2];

	// intialization - first column
	for (i = 0 ; i < 2 ; i++)	{
		if (str1[i] != str2[0])
			so[i][0] = 0;
		else
			// rest all will be ones
			break;
	}

	while (i < 2)
		so[i++][0] = 1;

	// to iterate between rows to be filled
	int row_1 = 0, row_2 = 1;

	// intialization - first row
	for (j = 0 ; j < len2 ; j++)	{
		if (str2[j] != str1[0])
			so[row_1][j] = 0;
		else
			// rest all will be ones
			break;
	}

	while (j < len2)
		so[0][j++] = 1;	

	// induction step
	for (i = 1 ; i < len1 ; i++)	{
		for (j = 1 ; j < len2 ; j++)	{
			if (str1[i] == str2[j])	{
				so[row_2][j] = 1 + so[row_1][j -1];
			}
			else	{
				if (so[row_1][j] <= so[row_2][j - 1])
					so[row_2][j] = so[row_2][j - 1];
				else
					so[row_2][j] = so[row_1][j];
			}
		}

		// switch rows
		if (row_1 == 0)	{
			row_1 = 1;
			row_2 = 0;
		}
		else	{
			row_1 = 0;
			row_2 = 1;	
		}
	}

	// printing out the state table
	// printing out the column string
	for (j = 0 ; j < len2 ; j++)
		printf("%4c", str2[j]);
	printf("\n");

	// printing out the table
	for (i = 0 ; i < 2 ; i++)	{
		for (j = 0 ; j < len2 ; j++)	{
			printf("%4d", so[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	int length2 = so[row_1][len2 -1];
	printf("Length of the longest common substring = %d\n\n", length2);


	// check if the answers match
	if (length != length2)	{
		printf("ERROR\n");



		// break;
	}

	return 0;
}


