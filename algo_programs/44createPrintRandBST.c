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
	// find level order traversal
	int height = findHeight(root);
	int no_nodes = power(2, height + 1) - 1;
	int levelOrder[no_nodes];
	printf("%d\n", no_nodes);
	fillLevel(root, levelOrder, 0, no_nodes - 1);
	
	// print in grid form
	// printing in reverse order
	int mid = 2;
	int step = 2;
	int atHeight = height;
	int atNode = no_nodes - 1;
	int nodes_h;
	int i;
	while (atHeight >= 0)	{
		nodes_h = power(2, atHeight);
		// print strating space
		printf("%*s", (mid/2)*step, " ");
		for (i = 0 ; i < nodes_h ; i++)	{
			if (levelOrder[i]!=-1)
			printf("%*d", mid*step, levelOrder[i]);
			else
			printf("%*s", mid*step, "_");
		}
		printf("\n");
		mid *= 2;
		atHeight--;
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
	srand(0);

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
