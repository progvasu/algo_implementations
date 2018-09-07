// creating a file with random numbers - 10^6 - any bigger file size becomes too big

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	srand(time(0));

	FILE *outfile = fopen("./data/random_numbers_10_6.txt", "w");

	int n = 1000000;

	while (n-- > 0)	{
		fprintf(outfile, "%d\n", rand() % 100000);
	}

	fclose(outfile);

	return 0;
}
