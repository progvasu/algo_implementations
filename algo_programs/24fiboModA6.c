#include<stdio.h>
#include<string.h>

void matrix_mul(int fir[2][2], int sec[2][2], int mod)	{
	int i, j, k, l;
	i = fir[0][0] * sec[0][0] + fir[0][1] * sec[1][0];
	j = fir[0][0] * sec[0][1] + fir[0][1] * sec[1][1];
	k = fir[1][0] * sec[0][0] + fir[1][1] * sec[1][0];
	l = fir[1][0] * sec[0][1] + fir[1][1] * sec[1][1];

	fir[0][0] = i % mod;
	fir[0][1] = j % mod;
	fir[1][0] = k % mod;
	fir[1][1] = l % mod;
}

void matrix_pow(int mat[2][2], int pow, int mod)	{
	int y[2][2] = {{1, 0}, {0, 1}};

	while(pow > 0)	{
		if (pow % 2 == 1)
			matrix_mul(y, mat, mod);

		matrix_mul(mat, mat, mod);
		pow /= 2;
	}

	mat[0][0] = y[0][0];
	mat[0][1] = y[0][1];
	mat[1][0] = y[1][0];
	mat[1][1] = y[1][1];
}

void stringToArray(char *num_array, int number)	{
	int key, i = 0;

	while(number > 0)	{
		key = number % 10;
		num_array[i++] = key;
		number /= 10;
	}

	if (i != 10)
		num_array[i] = -1;
}

int main()	{
	// int n[] = {4, 6, 5, 4, 3, 2, 1, 0 ,9, 8, 6, 5, 4, 2, 3, 8, 6, 5, 3, 4, 5, 6, 7, 8, 9};
	// int d = 25, i = 24;
	// int n[] = {1, 2, 3, 8, 7, 5, 3};
	// int d = 7, i = 6;

	FILE *ptr;
	int i = 0;
	char str[1000000];
	ptr = fopen("./data/test.txt", "r");

	fscanf (ptr, "%s", &str);
	
	printf("%s\n", str);
	return 0;

    fclose (ptr);	

	// int a[2][2] = {{1, 1}, {1, 0}};
	// int y[2][2] = {{1, 0}, {0, 1}};
	// int temp[2][2];
	// int mod= 100;
		
	// while(i >= 0)	{
	// 	if (n[i])	{
	// 		temp[0][0] = a[0][0];
	// 		temp[0][1] = a[0][1];
	// 		temp[1][0] = a[1][0];
	// 		temp[1][1] = a[1][1];
	// 		matrix_pow(temp, n[i], mod);
	// 		matrix_mul(y, temp, mod);
	// 	}

	// 	matrix_pow(a, 10, mod);

	// 	i = i - 1;
	// }

	// printf("y = ");
	// int j;
	// for (i = 0 ; i < 2 ; i++)
	// 	for (j = 0 ; j < 2 ; j++)
	// 		printf("%d  ", y[i][j]);

	// printf("\na = ");
	// for (i = 0 ; i < 2 ; i++)
	// 	for (j = 0 ; j < 2 ; j++)
	// 		printf("%d  ", a[i][j]);

	// printf("\n");	
	
	// return 0;
}
