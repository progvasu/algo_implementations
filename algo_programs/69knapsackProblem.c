// knapsack problem
// sometimes taking the runtime sizes causes the stack to overflow

#include<stdio.h>

int main()	{
	// loop invariantes	
	int i, j;

	// knapsack problem statement	
	int items = 4, knap_size = 5;
	// int items = 3, knap_size = 50;

	int weight_vec[items];
	// int weight_vec[100];
	weight_vec[0] = 2;
	weight_vec[1] = 1;
	weight_vec[2] = 3;
	weight_vec[3] = 2;
	// weight_vec[0] = 10;
	// weight_vec[1] = 20;
	// weight_vec[2] = 30;
	

	int total_weight = 0;
	for (j = 0 ; j < items ; j++)
		total_weight += weight_vec[j];
	// testing
	// printf("Total weight: %d\n\n", total_weight);

	int value_vec[items];
	// int value_vec[100];
	value_vec[0] = 12;
	value_vec[1] = 10;
	value_vec[2] = 21;
	value_vec[3] = 15;
	// value_vec[0] = 60;
	// value_vec[1] = 100;
	// value_vec[2] = 120;	

	// state table - v[i][j] = maximum profit we can make by using first 'i' items and a knapsack of size 'j'
	int V[items][total_weight + 1];
	// int V[100][1000];

	// initialization
	// first row
	for (j = 1 ; j <= total_weight ; j++)	{
		if (weight_vec[0] > j)
			V[0][j] = 0;
		else
			V[0][j] = value_vec[0];
	}

	// first column - zero value for knapsack of size 0
	for (i = 0 ; i < items ; i++)
		V[i][0] = 0;

	// induction
	for (i = 1 ; i < items ; i++)	{
		for (j = 1 ; j <= total_weight ; j++)	{
			if (j >= weight_vec[i] && ((value_vec[i] + V[i - 1][j - weight_vec[i]]) > V[i - 1][j]))
				V[i][j] = value_vec[i] + V[i - 1][j - weight_vec[i]];
			else
				V[i][j] = V[i - 1][j];
		}
	}

	// print state table
	// print weight values
	printf("%4c", ' ');
	for (j = 1 ; j <= total_weight ; j++)
		printf("%4d", j);
	printf("\n");

	for (i = 0 ; i < items ; i++)	{
		printf("%4d", i + 1);

		for (j = 1 ; j <= total_weight ; j++)	{
			printf("%4d", V[i][j]);
		}
		printf("\n");
	}

	// testing
	// printing out the last row
	// printf("\n");
	// for (j = 1 ; j <= total_weight ; j++)
	// 	printf("%4d", V[items - 1][j]);

	// max profit
	int result = V[items - 1][knap_size];
	printf("\nMax profit which can be made with knapsack of size %d is %d\n", knap_size, result);

	// back tracking to get items which give the max profit
	// not dynamically assigning - we run out of stack space - segmentation fault
	int result_items[items];
	// int result_items[1000];

	// intialize to zero
	for (i = 0 ; i < items ; i++)
		result_items[i] = 0;

	i = items - 1;
	j = knap_size;

	while (j > 0)	{
		if (j >= weight_vec[i] && ((value_vec[i] + V[i - 1][j - weight_vec[i]]) > V[i - 1][j]))	{
			result_items[i] = 1;
			j = j - weight_vec[i];
			i = i - 1; // can use an item exactly once
		}
		else	{
			i = i - 1;
		}
	}

	printf("\nItems used: ");
	for (i = 0 ; i < items ; i++)	{
		if (result_items[i] == 1)
			printf("%3d", i + 1);
	}
	printf("\n");

	// space optimized version
	printf("\n--Space Optimized Version--\n\n");

	// state table - need two rows - we will always fill row1
	int so[2][total_weight], row1 = 0, row2 = 1, temp;
	// int so[2][1000], row1 = 0, row2 = 1, temp;

	// first getting max profit - printing complete state table along with space optimized state table

	// state print - columns
	// print weight values
	printf("%4c", ' ');
	for (j = 1 ; j <= total_weight ; j++)
		printf("%4d", j);
	printf("\n");
	
	// intialization
	// first row
	printf("%4d", 1);
	for (j = 1 ; j <= total_weight ; j++)	{
		if (weight_vec[0] > j)
			V[row1][j] = 0;
		else
			V[row1][j] = value_vec[0];
		printf("%4d", V[row1][j]);
	}
	printf("\n");

	// induction & printing state
	for (i = 1 ; i < items ; i++)	{
		printf("%4d", i + 1);

		temp = row1;
		row1 = row2;
		row2 = temp;

		for (j = 1 ; j <= total_weight ; j++)	{
			if (j >= weight_vec[i] && ((value_vec[i] + V[row2][j - weight_vec[i]]) > V[row2][j]))
				V[row1][j] = value_vec[i] + V[row2][j - weight_vec[i]];
			else
				V[row1][j] = V[row2][j];
			printf("%4d", V[row1][j]);
		}

		printf("\n");
	}

	// max profit
	int result2 = V[row1][knap_size];
	printf("\nMax profit which can be made with knapsack of size %d is %d\n", knap_size, result2);	

	return 0;
}





















