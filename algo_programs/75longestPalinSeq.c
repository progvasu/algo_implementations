#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	srand(time(0));

	// input
	// char *string = "GEEKS FOR GEEKS";
	// char *string = "GEEKSFORGEEKS";
	char *string = "ABCABBA";
	int len_str;

	// calculate length of string
	len_str = 0;
	while (string[len_str] != '\0')
		len_str++;

	// we define state table
	int T[len_str][len_str], i, j, l;

	// initializing state table to zero  - purely for debugging purposes
	for (i = 0 ; i < len_str ; i++)
		for (j = 0 ; j < len_str ; j++)
			T[i][j] = 0;

	// we fill the state table diagonally
	
	// initialization
	// first - strings of length 1
	for (i = 0 ; i < len_str ; i++)
		T[i][i] = 1;

	// second - strings of length 2
	for (i = 0 ; i < len_str - 1 ; i++)
		if (string[i] == string[i + 1])
			T[i][i + 1] = 2;
		else
			T[i][i + 1] = 1;

	// induction
	// l here denotes the length of the substring we are considering
	for (l = 2 ; l < len_str ; l++)	{
		// for every row
		for (i = 0 ; i < len_str - l ; i++)	{
			j = i + l;
			if (string[i] == string[j])
				T[i][j] = 2 + T[i + 1][j - 1];
			else	{
				if (T[i + 1][j] > T[i][j - 1])
					T[i][j] = T[i + 1][j];
				else
					T[i][j] = T[i][j - 1];
			}
		}
	}

	// printing state table

	// printing first string row
	printf("%3c", ' ');
	for (j = 0 ; j < len_str ; j++)
		printf("%3c", string[j]);
	printf("\n");

	for (i = 0 ; i < len_str ; i++)	{
		printf("%3c", string[i]);

		for (j = 0 ; j < len_str ; j++)
			printf("%3d", T[i][j]);

		printf("\n");
	}
	printf("\n");

	// instead of diagonal filling we could fill this table horizontally
	// we define separate table for checking if values match
	int H[len_str][len_str];

	// initializing state table to zero  - purely for debugging purposes
	for (i = 0 ; i < len_str ; i++)
		for (j = 0 ; j < len_str ; j++)
			H[i][j] = 0;

	// we do initialization diagonally
	// first - strings of length 1
	for (i = 0 ; i < len_str ; i++)
		H[i][i] = 1;

	// second - strings of length 2
	for (i = 0 ; i < len_str - 1 ; i++)
		if (string[i] == string[i + 1])
			H[i][i + 1] = 2;
		else
			H[i][i + 1] = 1;

	// induction
	for (l = 2 ; l < len_str ; l++)	{
		i = len_str - 1 - l;
		for (j = len_str - l; j < len_str ; j++)	{
			if (string[i] == string[j])
				H[i][j] = 2 + H[i + 1][j - 1];
			else	{
				if (H[i + 1][j] > H[i][j - 1])
					H[i][j] = H[i + 1][j];
				else
					H[i][j] = H[i][j - 1];
			}
		}
	}

	// printing state table

	// printing first string row
	printf("%3c", ' ');
	for (j = 0 ; j < len_str ; j++)
		printf("%3c", string[j]);
	printf("\n");

	for (i = 0 ; i < len_str ; i++)	{
		printf("%3c", string[i]);

		for (j = 0 ; j < len_str ; j++)
			printf("%3d", H[i][j]);

		printf("\n");
	}
	printf("\n");

	printf("Length of LPS - diagonal filling: %d\n", T[0][len_str - 1]);
	printf("Length of LPS - horizntl filling: %d\n", H[0][len_str - 1]);	
	
	// back tracking using any state table we created
	i = 0;
	j = len_str - 1;

	int res_len = T[0][len_str - 1];
	char result[res_len];

	// backtracking - simple - just reverse of filling the table
	while (i >=0 && j > 0 && T[i][j] != 0)	{
		if (string[i] == string[j])	{
			result[--res_len] = string[i];
			i++;
			j--;
		}
		else	{
			if (H[i + 1][j] > H[i][j - 1])
				i = i + 1;
			else
				j = j - 1;
		}
	}

	int temp;
	// we get just 1 part of the string - we now fill the remaining part
	// if res_len is odd
	if (T[0][len_str - 1] % 2 == 1)	{
		// skip the odd character
		temp = res_len + 1;
		while(res_len > 0)	{
			result[--res_len] = result[temp++];
		}
	}
	else	{
		// no odd character to skip
		temp = res_len + 1;
		while(res_len > 0)	{
			result[--res_len] = result[temp++];
		}	
	}

	printf("\nLPS: %s\n", result);

	return 0;
}