#include<stdio.h>

int main()	{
	int n[] = {9, 8, 7, 6, 5, 4, 3, 5, 6, 8, 3, 2, 4, 5, 6, 8, 9, 0, 1, 2, 3, 4, 5, 6, 4}; // number stored as LSD digit first
	int n_len = 25; // 0 = 24
	int mod = 100;
	
	// Step1. Find Period - The sequence will repeat in 6 * mod
	int period_max = (6 * mod) + 2, i, period;
	int periodArray[period_max];
	periodArray[0] = 0;
	periodArray[1] = 1;

	for(i = 2 ; i < period_max ; i++)	{
		periodArray[i] = (periodArray[i - 1] + periodArray[i - 2]) % 100;
		if (periodArray[i - 1] == 0 && periodArray[i] == 1)	{
			period = i - 1;
			break;
		}
	}

	printf("Period = %d\n", period);

	// Step2. Find the mod of n
	int mod_result = 0;
	for (i = n_len - 1 ; i >=0 ; i--)	{
		mod_result = 10 * mod_result + n[i];
		mod_result %= period;
	}

	printf("Result = %d\n", periodArray[mod_result]);

	return 0;
}
        
