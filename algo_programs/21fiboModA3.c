#include<stdio.h>

int main()	{
	int n, mod = 100;
	int a, b, c;
	
	printf("Enter the value of n: ");
	scanf("%d", &n);

	a = 0;
 	b = 1;

	for( ; n >= 2 ; n--)	{
		c = (a + b) % mod;
		a = b;
		b = c;	
	}

	printf("Result = %d\n", c);

	return 0;
}
