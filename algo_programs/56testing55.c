// testing header file for Red Black module

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "55modRB.h"

// black depth must be same for every leaf node so using a global variable to keep track
int black_height = -1;

int checkRBT(struct node *root, struct node *parent, struct node *node)	{
	// check for red - both children then must be black
	if (node != NULL && node->color == 'R')	{
		if ((node->lc == NULL || node->lc->color == 'B') && (node->rc == NULL || node->rc->color == 'B'))	{
			// code handles all these situations as well
			// children could be NULL - but still need to check for black height!
			// if both children not null
			// if (node->lc != NULL && node->rc != NULL)	{
				return checkRBT(root, node, node->lc) && checkRBT(root, node, node->rc);
			// }
			// // both are NULL
			// else if (node->lc == NULL && node->rc == NULL)	{
			// 	// just check black height for node
			// 	return checkRBT(root, node, NULL);
			// }
			// // left child is not NULL but right child is
			// else if (node->lc != NULL)	{
			// 	// call for left child and check black height of node
			// 	return checkRBT(root, node, node->lc) && checkRBT(root, node, NULL);
			// }
			// else	{
			// 	// call for right child and check black height of node
			// 	return checkRBT(root, node, NULL) && checkRBT(root, node, node->rc);
			// }
		}
		else
			return 0;
	}
	// node is NULL - check black height
	else	{
		// calculate black height
		int bh = 0;
		node = parent;
		while (node != NULL)	{
			if (node->color == 'B')
				bh++;
			node = node->pr;
		}
		
		// initialize black height and return with true value
		if (black_height == -1)	{
			black_height = bh;
			return 1;
		}

		// otherwise check if equal
		if (bh == black_height)
			return 1;
		else
			return 0;
	}
}

int isRBT(struct node *root)	{
	if (root == NULL)
		return 1;

	// root must be black
	if (root->color != 'B')
		return 0;

	return checkRBT(root, root, root->lc) && checkRBT(root, root, root->rc);
}

int main()	{
	// how to test a red black tree?
	// 1. check if root is black
	// 2. if a node is red both children are either black or NULL
	// 3. black height of every path from root to leaf is equal - could do it opposite black depth for every leaf should be equal

	// for a random tree

	srand(time(0));
	//srand(0);

	int n = 15;
	int a[n], i, rand_index, temp;

	// create index array
	for (i = 0 ; i < n ; i++)
		a[i] = i;
	// permute it
	for (i = 0 ; i < n ; i++)	{
		rand_index = rand() % n;
		temp = a[rand_index];
		a[rand_index] = a[i];
		a[i] = temp;
	}

	struct node *root = NULL;

	// insert into RB and check
	for (i = 0 ; i < n ; i++)	{
		insertRBT(&root, a[i]);
		
		// check to see if Red Black tree property is satisfied
		if (!isRBT(root))	{
			printf("RBT property violated\n");
			break;
		}
	}

	printRBTree(root);

	// permute the numbers
	for (i = 0 ; i < n ; i++)	{
		rand_index = rand() % n;
		temp = a[rand_index];
		a[rand_index] = a[i];
		a[i] = temp;
	}

	// delete from AVL and check
	for (i = 0 ; i < n ; i++)	{
		deleteRBT(&root, a[i]);

		printRBTree(root);
		getchar();

		// check to see if AVL property satisfied
		if (!isRBT(root))	{
			printf("RBT property violated\n");
			printRBTree(root);
			break;
		}
	}
	
	return 0;
}