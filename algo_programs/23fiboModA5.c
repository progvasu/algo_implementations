#include<stdio.h>

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

int main()	{
	int n[] = {1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0 , 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1};	
	int k = 82, i = 81;
	int a[2][2] = {{1, 1}, {1, 0}};
	int y[2][2] = {{1, 0}, {0, 1}};
	int mod = 100;

	while (i >= 0)	{
		if (n[i])
			matrix_mul(y, a, mod);

		matrix_mul(a, a, mod);
		i = i - 1;
	}

	printf("y = ");
	int j;
	for (i = 0 ; i < 2 ; i++)
		for (j = 0 ; j < 2 ; j++)
			printf("%d  ", y[i][j]);

	printf("\na = ");
	for (i = 0 ; i < 2 ; i++)
		for (j = 0 ; j < 2 ; j++)
			printf("%d  ", a[i][j]);

	printf("\n");	
	return 0;
}
