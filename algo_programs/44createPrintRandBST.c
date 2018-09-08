// create a random binary search tree and print it out on the console in tree shape

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node	{
	int key;
	struct node *lc;
	struct node *rc;
};

void insertBST(struct node **root, int key)	{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = key;
	temp->lc = NULL;
	temp->rc = NULL;

	// tree is empty
	if ((*root) == NULL)	{
		(*root) = temp;
		return;
	}

	// find the correct position
	struct node *pos, *parent;
	pos = (*root);
	parent = NULL;
	while (pos != NULL)	{
		parent = pos;
		if (key < pos->key)	{
			pos = pos->lc;
		}
		else	{
			pos = pos->rc;
		}
	}

	// insert as child of parent
	if (key < parent->key)
		parent->lc = temp;
	else
		parent->rc = temp;
}

#define MAX(X, Y) ((X > Y ? X : Y))

int power(int x, int n)	{
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return power(x * x, n / 2);
	else
		return x * power(x * x, n / 2);
}

void fillLevel(struct node *root, int *levelOrder, int pos, int max_pos)	{
	// filling value at position 'pos' in levelOrder
	if (root == NULL)	{
		if (pos <= max_pos)	{
			levelOrder[pos] = -1;
			fillLevel(NULL, levelOrder, pos*2 + 1, max_pos);
			fillLevel(NULL, levelOrder, pos*2 + 2, max_pos);
		}
		else
			return;
	}
	else	{
	levelOrder[pos] = root->key;
	fillLevel(root->lc, levelOrder, pos*2 + 1, max_pos);
	fillLevel(root->rc, levelOrder, pos*2 + 2, max_pos);
	}
}

int findHeight(struct node *root)	{
	if (root == NULL)	return -1;
	int left = findHeight(root->lc), right = findHeight(root->rc);
	return (1 + MAX(left, right));
}

void treePrint(struct node *root)	{
	int height = findHeight(root);
	if (height > 5)	{
		printf("Tree size to big to fit on screen\n");
		return;
	}

	int no_nodes = power(2, height + 1) - 1;

	// find level order traversal
	int levelOrder[no_nodes];
	fillLevel(root, levelOrder, 0, no_nodes - 1);
	
	// print in grid form
	// printing in reverse order
	//int mid = 4, ch = 0, n_ch, cn = no_nodes - 1, i;
	//while (ch <= height)	{
	//	// number of nodes at current height
	//	n_ch = power(2, height - ch);
	//	// printing starting space
	//	printf("%*s", mid/2, "");
	//	// printing nodes
	//	for (i = 0 ; i < n_ch ; i++)	{
	//		if (levelOrder[cn] != -1)	{
	//			if (i == 0) // for first element
	//				printf("%d", levelOrder[cn--]);
	//			else
	//				printf("%*d", mid, levelOrder[cn--]);
	//		}
	//		else	{
	//			cn--;
	//			if (i == 0)
	//				printf("%s", "-");
	//			else
	//				printf("%*s", mid, "-");
	//		}
	//	}
	//	printf("\n");
	//	mid *= 2;
	//	ch += 1;
	//}

	int mid, cn, n_ch, ch, i;
	// printing from root to leaf
	mid = 4 * power(2, height);
	cn = 0;
	n_ch = 1;
	ch = height;
	while (ch >= 0)	{
		// printing starting space
		printf("%*s", mid/2, "");
		for (i = 0 ; i < n_ch ; i++)	{
			if (levelOrder[cn] != -1)	{
				if (i == 0) // for first node at this height
					printf("%d", levelOrder[cn++]);
				else
					printf("%*d", mid, levelOrder[cn++]);
			}
			else	{
				cn++;
				if (i == 0)
					printf("%s", "-");
				else
					printf("%*s", mid, "-");
			}
		}
		printf("\n");
		mid /= 2;
		n_ch *= 2;
		ch--;
	}
}

void testPrint(struct node *root)	{
	if (root == NULL)	return;
	printf("%6dr", root->key);
	if (root->lc != NULL)
		printf("%6dl", root->lc->key);
	if (root->rc != NULL)
		printf("%6dr", root->rc->key);
	printf("\n");
	testPrint(root->lc);
	testPrint(root->rc);
}

int main()	{
	srand(time(0));
	// set to 5 for height 3

	struct node *root = NULL;

	// generating an ordered array and permuting it to create a random array with unique values
	int n = 10;
	int a[n], i, temp, rand_index;
	// creating ordered array
	for (i = 0 ; i < n ; i++)
		a[i] = i;
	// permuting the array
	for (i = 0 ; i < n ; i++)	{
		rand_index = rand() % n;
		// swapping a[i] with random index
		temp = a[rand_index];
		a[rand_index] = a[i];
		a[i] = temp;
	}
	
	// inserting values into BST
	for (i = 0 ; i < n ; i++)	{
		insertBST(&root, a[i]);
	}

	// test print
	//testPrint(root);

	// print tree form
	treePrint(root);

	return 0;
}
