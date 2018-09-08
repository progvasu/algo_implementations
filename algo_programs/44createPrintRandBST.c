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
	testPrint(root);

	return 0;
}
