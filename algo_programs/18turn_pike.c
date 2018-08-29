#include<stdio.h>

int dist[15] = {1, 2, 2, 2, 3, 3, 3, 4, 5, 5, 5, 6, 7, 8, 10};
int dist_len = 14, soln_len = 5;
int soln[6] = {0, 0, 0, 0, 0, 10};
int soln_left = 1, soln_right = 4, dist_right = 14;

int checkCorrectFit()	{
	int i, k, j, temp[dist_len + 1], diff, return_val;
	// create a copy of dist
	for (i = 0 ; i <= dist_len ; i++)
		temp[i] = dist[i];

	// check to see if soln fits
	// from left
	for (i = 0 ; i < soln_len ; i++)	{
		for (k = i + 1 ; k <= soln_len ; k++)	{
			// for handling negative values
			if (soln[k] == 0)	{
				continue;
			}
			// for handling zero in soln
			if (i != 0 && soln[i] == 0)	{
				return_val = 1;
				break;
			}

			diff = soln[k] - soln[i];
			// printf("%d - %d = %d\n", soln[k], soln[i], diff);
			// check in complete array
			return_val = 0;
			
			for (j = 0 ; j <= dist_len ; j++)	{
				if (diff == temp[j])	{
					temp[j] = -1;
					return_val = 1;
					break;
				}
			}
						
			if (return_val == 0) return 0;
		}
	}

	return 1;
}

int turn_pike()	{
	int right, left;

	// base case
	if (soln_left > soln_right)	{
		// soln is complete
		return checkCorrectFit();
	}

	// fix a right solution into soln
	soln[soln_right] = dist[dist_right];
	soln_right--;
	dist_right--;
	right = checkCorrectFit();

	// undo right
	dist_right++;
	soln_right++;
	soln[soln_right] = 0;

	// fix a left solution into soln array
	soln[soln_left] = dist[dist_len] - dist[dist_right];
	soln_left++;
	dist_right--;
	left = checkCorrectFit();

	// undo left
	dist_right++;
	soln_left--;
	soln[soln_left] = 0;

	// branching
	if (right == 1 && left == 0)	{
		// can fix only right
		soln[soln_right] = dist[dist_right];
		soln_right--;
		dist_right--;
		return turn_pike();
	}
	else if (right == 0 && left == 1)	{
		// can fix only left
		soln[soln_left] = dist[dist_len] - dist[dist_right];
		soln_left++;
		dist_right--;
		return turn_pike();	
	}	
	else if (right == 1 && left == 1)	{
		// try both
		// calling right first
		soln[soln_right] = dist[dist_right];
		soln_right--;
		dist_right--;
		right = turn_pike();
		if (right == 1) 
			return 1;
		else	{
			// undo right and try left
			// undo right
			dist_right++;
			soln_right++;
			soln[soln_right] = 0;

			// call for left fix solution
			soln[soln_left] = dist[dist_len] - dist[dist_right];
			soln_left++;
			dist_right--;
			left = turn_pike();
		}
		if (left == 0)	return 0;
		else return 1;
	}
	
}

int main()	{
	int result;

	result = turn_pike();

	if (result == 0)
		printf("Answer = Solution not possible\n");
	else	{
		printf("Answer = Solution Possible\n");
		for (result = 0 ; result <= soln_len ; result++)
			printf("%d  ", soln[result]);
		printf("\n");
	}

	return 0;
}
