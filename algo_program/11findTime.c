#include<stdio.h>
#include<time.h>

int main()	{
	int n = 10000;
	long int s = 5;
	int i, j, k;
	clock_t start, end;
	double cpu_time_used;

	start = clock();
	for (i = 1 ; i < n ; i++)
		for (j = 1 ; j < n ; j++)
			for (k = 1 ; k < n / 10 ; k++)
				s = 2*s + 1;
	end = clock();

	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken = %f\n", cpu_time_used);
	printf("s = %ld", s);

	return 0;
}
