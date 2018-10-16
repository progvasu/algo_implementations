// min heap

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function declarations
void buildHeap(int *, int, int);
void topDownHeapify(int *, int, int);
int deleteMin(int *, int);
int changeKey(int *, int, int, int);

// function declarations for displaying heap
int findHeight(int);
int power(int, int);
void displayHeap(int *, int );

int changeKey(int *arr, int index, int key, int f_nodes)	{
	// incorrect index values
	if (index < 0 || index >= f_nodes)
		return -2;
	if (key > 99)
		return 2;

	// no change
	if (arr[index] == key)
		return 0;

	// increase or decrease key
	i
}

int deleteMin(int *arr, int f_nodes)	{
	int ret = arr[0];
	
	// just one node left
	if (f_nodes == 1)
		return ret;

	// copy last element to root
	arr[0] = arr[f_nodes - 1];

	// removing last node
	arr[f_nodes - 1] = -1;

	// moving new root node to it its proper place
	topDownHeapify(arr, 0, f_nodes - 1);

	return ret;
}

void buildHeap(int *arr, int tn, int fn)	{
	int temp = fn/2;

	while (temp >= 0)
		topDownHeapify(arr, temp--, fn);
}

void topDownHeapify(int *arr, int curr_node, int f_nodes)	{
	int lc, rc, low, temp;

	lc = 2 * curr_node + 1;
	rc = 2 * curr_node + 2;

	while (rc < f_nodes)	{
		if (arr[lc] < arr[rc])
			low = lc;
		else
			low = rc;

		if (arr[curr_node] <= arr[low])
			return;
		else	{
			temp = arr[curr_node];
			arr[curr_node] = arr[low];
			arr[low] = temp;

			curr_node = low;
			lc = 2 * curr_node + 1;
			rc = 2 * curr_node + 2;			
		}
	} // end of while

	// for lone left child
	if (lc < f_nodes)	{
		if (arr[curr_node] > arr[lc])	{
			temp = arr[curr_node];
			arr[curr_node] = arr[lc];
			arr[lc] = temp;			
		}
	}
} // end of top down heapify

int findHeight(int n)	{
	int h = -1, temp = 1;

	while (temp < n)	{
		h++;
		temp *= 2;
	}

	return h;
}

// calculate power of a number
int power(int x, int n)	{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return power(x * x, n / 2);
	else
		return x * power(x * x, n / 2);
}

void displayHeap(int *arr, int n)	{
	// calculate height of the tree
	int height = findHeight(n);

	// if height > 5 tree will not fit on the screen
	if (height > 5)	{
		printf("Tree size to big to fit on screen\n");
		return;
	}
	// tree empty!
	else if (height == -1)	{
		printf("Tree Empty\n");
		return;
	}

	// calculate the number of nodes in the tree
	int no_nodes = n;

	// find level order traversal
	int *levelOrder = arr;
	
	// printing from root to leaf

	// mid - spacing between nodes for the current height
	// cn - current node to be printed
	// n_ch - number of nodes at current height
	// ch - current height
	// ne - number of edges at current height
	int mid, cn, n_ch, ch, ne, i;
	
	// initial value for spacing
	mid = 4 * power(2, height);

	// current node to be printed root node
	cn = 0; 

	// number of nodes at root level = 1
	n_ch = 1;

	// current height = height of root = max height
	ch = height;
	
	// while at and above leaf level
	while (ch >= 0)	{

		// printing all nodes at current level
		for (i = 0 ; i < n_ch ; i++)	{
			// if node is not null
			if (levelOrder[cn] != -1)	{
				if (i == 0) 
					// for first node at this height
					printf("%*d", mid/2, levelOrder[cn++]);
				else
					// for all the remaining nodes
					printf("%*d", mid, levelOrder[cn++]);
			}
			// if node is null - print blank
			else	{
				cn++;
				if (i == 0)
					// for first node at this height
					printf("%*s", mid/2, "-");
				else
					// for rest of the nodes
					printf("%*s", mid, "-");
			}
		}

		// printing edges
		// es - distance of side edges /es\
		// en - distance between two neighbours /\ en /\
		
		int es, en;
		es = 2;
		en = mid - 2;

		// for each row in height between two levels
		for(i = 0 ; i < power(2, ch - 1) ; i++)	{
			// move one level down
			printf("\n");

			// calculate number of edges at this height
			ne = 2 * n_ch;

			// first edge distance from left
			printf("%*c", mid/2 - i*2 - 1, '-');
			
			// remaining edges
			ne--;

			// while edges are remaining at this height
			while (ne > 0)	{
				// print second edge
				printf("%*c", es, '-');
				ne--;

				// print first edge of neighbour
				if (ne > 0)
					printf("%*c", en, '-');	
				ne--; 
			}

			// increment edge side and edge neighbour distance
			es += 4;
			en -= 4;
		}

		// move down one level
		printf("\n");

		// distance from left reduces by half
		mid /= 2;
		// number of nodes at next height doubles
		n_ch *= 2;
		// decrement height
		ch--;
	} // end of while
} // end of function - displayHeap

int main()	{
	srand(time(0));

	// n should represent a complete tree
	int n = 16 - 1;
	int a[n];

	// m actual number of nodes present in the tree < n
	int m = 12;
	
	// loop variables
	int i;

	// random heap - no duplicates
	a[0] = rand() % 5;
	for (i = 1 ; i < m ; i++)
		a[i] = a[i - 1] + rand() % 5 + 1;

	// randomizing them
	int temp, rand_index;
	for (i = 0 ; i < m ; i++)	{
		rand_index = rand() % m;
		temp = a[rand_index];
		a[rand_index] = a[i];
		a[i] = temp;
	}

	// -1 shows an empty node
	while (i < n)
		a[i++] = -1;

	// build heap
	buildHeap(a, n, m);

	// display heap
	displayHeap(a, n);

	int option, index, key, result;

	while(m != 0)	{
		printf("\n 1. Delete Min\n");
		printf(" 2. Change Key\n");
		printf("-1. Exit\n");
		printf("Enter option: ");
		scanf("%d", &option);

		switch(option)	{
			case 1:
	
				printf("Min deleted - %d\n", deleteMin(a, m--));
				
				printf("\n");
				displayHeap(a, n);
	
				break;
	
			case 2:
	
				printf("Enter index and new key: ");
				scanf("%d%d", &index, &key);
	
				result = changeKey(a, index, key, m);
				
				// interpreting values returned from the changeKey function
				if (result == 1)
					printf("Key at index %d incremented to %d\n", index, key);
				else if (result == -1)
					printf("Key at index %d decremented to %d\n", index, key);
				else if (result == 0)
					printf("No change in key value\n");
				else if (result < -1)
					printf("Incorrect index supplied\n");
				else if (result > 1)
					printf("Key value too large\n");

				printf("\n");
				displayHeap(a, n);

				break;
	
			case -1:
	
				printf("EXITING\n");
				return 0;
	
			default:
	
				printf("Select correct option\n");
		}

		if (m == 0)	{
			printf("\nHeap Empty\n");
			break;
		}
	}

	return 0;
}