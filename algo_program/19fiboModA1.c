// Algorithm 1 - Implemented as Recursion

#include<stdio.h>

int fiboMod(int n, int mod)	{
	if (n == 0 || n == 1)
		return n;

	return (fiboMod(n - 1, mod) + fiboMod(n - 2, mod)) % mod;
}

int main()	{
	int n;

	printf("Enter the value of n: ");
	scanf("%d", &n);
	int mod = 100;
	
	printf("Result = %d\n", fiboMod(n, mod));
}
