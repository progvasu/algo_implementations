// Algorithm 2 - Calculating using memoization

#include<stdio.h>

int fiboMod(int n, int mod)	{
	int fiboArray[n + 1], i;
	
	fiboArray[0] = 0;
	fiboArray[1] = 1;

	for (i = 2 ; i <= n ; i++)
		fiboArray[i] = (fiboArray[i - 1] + fiboArray[i - 2]) % mod;

	return fiboArray[n];
}

int main()	{
	int n, mod = 100;

	printf("Enter the value of n: ");
	scanf("%d", &n);

	printf("Result = %d\n", fiboMod(n, mod));

	return 0;
}
