// delete a node from a Red Black tree

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// red black tree node
struct node	{
	int key;
	char color;
	struct node *lc;
	struct node *rc;
	struct node *pr;
};

// could take color variable as int but for ease of printing we take it as char

// insert node into Red Black Tree

// function declarations
void insertRBT(struct node **, int);
void leftRotate(struct node **, struct node *, struct node *);
void rightRotate(struct node **, struct node *, struct node *);
void fixRBInsert(struct node **, struct node *);

void insertRBT(struct node **root, int key)	{
	// creating the node to be inserted
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = key;
	temp->lc = NULL;
	temp->rc = NULL;
	temp->pr = NULL;
	temp->color = 'R'; // initially coloring red

	// tree is empty the new node becomes root
	if ((*root) == NULL)	{
		// color the node as black
		temp->color = 'B';
		(*root) = temp;
		return;
	}

	// find the correct position in the tree
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

	// setting parent of temp
	temp->pr = parent;

	// insert as child of parent
	if (key < parent->key)
		parent->lc = temp;
	else
		parent->rc = temp;

	// call fixRBInsert
	fixRBInsert(root, temp);
}

// fix the red black tree property
void fixRBInsert(struct node **root, struct node *node)	{
	// node is initially not root we took care of that
	struct node *uncle;

	// if the below condition is satisfied then the grand parent will exist
	while(node->pr != NULL && node->pr->color == 'R')	{
		// if red red condition occurs in left sub tree
		if (node->pr == node->pr->pr->lc)	{
			// find uncle
			uncle = node->pr->pr->rc;
			// if color of uncle is red - Case 1
			if (uncle != NULL && uncle->color == 'R')	{
				node->pr->color = 'B';
				uncle->color = 'B';
				node->pr->pr->color = 'R';
				// red red condition may occur at grand parent
				node = node->pr->pr;
			}
			// else if uncle is black or null i.e. assuming it to be black
			else	{
				// if node a right child - Case 2
				if (node == node->pr->rc)
					leftRotate(root, node->pr, node);
				else
					node = node->pr;
				node->color = 'B';
				node->pr->color = 'R';
				rightRotate(root, node->pr, node);
			}
		}
		// if red red condition occurs in right sub tree - right left pointers exchanged
		else	{
			// find uncle
			uncle = node->pr->pr->lc;
			// if color of uncle is red - Case 1
			if (uncle != NULL && uncle->color == 'R')	{
				node->pr->color = 'B';
				uncle->color = 'B';
				node->pr->pr->color = 'R';
				// red red condition may occur at grand parent
				node = node->pr->pr;
			}
			// else if uncle is black or null i.e. assuming it to be black
			else	{
				// if node a right child - Case 2
				if (node == node->pr->lc)
					rightRotate(root, node->pr, node);
				else
					node = node->pr;
				node->color = 'B';
				node->pr->color = 'R';
				leftRotate(root, node->pr, node);
			}
		}// end of else
	} // end of while

	// reached root?
	if (node->pr == NULL)
		node->color = 'B';
}

// left rotate on x
void leftRotate(struct node **root, struct node *x, struct node *y)	{
	// setting right child of x
	x->rc = y->lc;

	// if left child of y not null set its parent
	if (y->lc != NULL)
		y->lc->pr = x;

	// linking parent of x to y
	y->pr = x->pr;

	// if x was the root node set y as root
	if (x->pr == NULL)	{
		(*root) = y;
	}
	// else set the child of parent of x
	else if (x == x->pr->lc)	{
		x->pr->lc = y;
	}
	else
		x->pr->rc = y;

	// putting x on left of y
	y->lc = x;
	x->pr = y;
}

// right rotate on y - dual of leftRotate
void rightRotate(struct node **root, struct node *y, struct node *x)	{
	// setting left child of y
	y->lc = x->rc;

	// if right child of x is not null set its parent
	if (x->rc != NULL)
		x->rc->pr = y;

	// linking parent of y to x
	x->pr = y->pr;

	// if y was the root node set x as root
	if (y->pr == NULL)	{
		(*root) = x;
	}
	// else set the child of parent of y
	else if (y == y->pr->rc)	{
		y->pr->rc = x;
	}
	else
		y->pr->lc = x;

	// putting y on right of x
	x->rc = y;
	y->pr = x;
}

// delete a node from RB Tree

// function declarations
void deleteRBT(struct node **, int);
void deleteNode(struct node **, struct node *);
void fixRBDelete(struct node **, struct node *, struct node *);
void transplant(struct node **, struct node *, struct node *);
// void leftRotate(struct node **, struct node *, struct node *);
// void rightRotate(struct node **, struct node *, struct node *);

void deleteRBT(struct node **root, int key)	{
	struct node *node = (*root);
	// find the key in the tree
	while ((node)->key != key)	{
		if (key < (node)->key)
			node = (node)->lc;
		else
			node = (node)->rc;

		if ((node) == NULL)	{
			printf("NODE NOT FOUND!\n");
			return;
		}
	}

	struct node *temp = node;
	deleteNode(root, node);
	free(temp);
}

// this procedure deletes the node from the tree
void deleteNode(struct node **root, struct node *node)	{
	struct node *x;
	struct node *org_pr = y->pr;
	struct node *y = node;
	char y_org_col = y->color;

	if (node->lc == NULL)	{
		x = node->rc;
		transplant(root, node, node->rc)
	}
	else if (node->rc == NULL)	{
		x = node->lc;
		transplant(root, node, node->lc);
	}
	else	{
		// find inorder successor
		y = node->rc;
		while (y->lc != NULL)	{
			y = y->lc;
		}

		// store it's original color - because we are going to move y from it's original position
		y_org_col = y->color;

		// replace y with it's right
		x = y->rc;

		if (y->pr == node)
			x->pr = node;
		else	{
			transplant(root, y, y->rc);
			y->rc = z->rc;
			y->rc->pr = y;
		}

		// set parent of y in z places
		transplant(root, node, y);

		// set the left child of y
		// we know left child exists!
		y->lc = node->lc;
		y->lc->pr = y;
		y->color = node->color;
	}

	// if the node we deleted was black - problem bro!
	if (y_org_col == 'B')
		fixRBDelete(root, x, org_pr);
}

// this procedure will fix the Red Black Tree property
void fixRBDelete(struct node **root, struct node *x, struct node *org_pr)	{
	while (x != root)
}

// this procedure replaces node1 with node2 - just the parents
void transplant(struct node **root, struct node *node1, struct node *node2)	{
	if (node1->pr == NULL)
		(*root) = node2;
	else if (node1 == node1->pr->lc)
		node1->pr->lc = node2;
	else
		node1->pr->rc = node2;
	
	if (node2 != NULL)
		node2->pr = node1->pr;
}

#include"50printRBTree.h"

int main()	{
	srand(time(0));

	// root node
	struct node *root = NULL;

	// create a random RB Tree
	int n = 15;
	int arr[n], i, rand_index, temp;

	// create an aray of indexes
	for(i = 0 ; i < n ; i++)
		arr[i] = i;

	// randomize this array
	for(i = 0 ; i < n ; i++)	{
		rand_index = (rand() % n);
		temp = arr[rand_index];
		arr[rand_index] = arr[i];
		arr[i] = temp;
	}

	// insert these numbers into RB Tree
	for (i = 0 ; i < n ; i++)
		insertRBT(&root, arr[i]);

	// print this tree
	printRBTree(root);

	int key;

	while(1)	{
		printf("Enter the key to be deleted(-1 to exit): ");
		scanf("%d", &key);

		if (key == -1)
			break;

		// insert into RB tree
		// insertRBT(&root, key);
		
		// insert into RB tree
		printRBTree(root);
	}

	return 0;
}