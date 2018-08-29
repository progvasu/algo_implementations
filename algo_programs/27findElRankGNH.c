// Find an element whose rank is greater than n / 2 where n is the
// numer of elements in the input array - using monte carlo

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()	{
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int b[] = {7, 6, 0, 9, 1, 4, 8, 3, 2, 5, 10};
	int a_len = 11, b_len = 11, i, rank, min = 100, temp;

	// rank will be n / 2
	rank = b_len / 2;

	srand(time(0));

	// findinf the element
	// for(i = 0 ; i < 3 ; i++)	{
	//	temp = b[rand() % 10];
	//	if (min > temp)
	//		min = temp;
	// }

	// printf("Element could be %d\n", min);
	

	// calculating the probability with which this monte carlo
	// simulation gives the current answer
	int test_case = 1000000, j, count_correct = 0;
	for (i = 0 ; i < test_case ; i++)	{
		min = 100;
		for (j = 0 ; j < 3 ; j++)	{
			temp = b[rand() % 10];
			if (min > temp)
				min = temp;
		}
		// if minimum lies on the LHS then great
		if (min <= 5)
			count_correct++;
	}

	printf("Probability of monte carlo simulation is %f\n", count_correct / (float)test_case);

	return 0;
}
