// insert a node into the AVL tree

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node	{
	int key;
	int height;	
	struct node *lc;
	struct node *rc;
	struct node *pr;
};

#include "45printBinaryTree.h"

// function decalarations for AVL insert
void insertAVL(struct node **, int);
void fixAVL(struct node **, struct node *);
int setHeight(struct node *);
void leftRotate(struct node **, struct node *, struct node *);
void rightRotate(struct node **, struct node *, struct node *);

void insertAVL(struct node **root, int key)	{
	// creating node to be inserted
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = key;
	temp->lc = NULL;
	temp->rc = NULL;

	// height of newly inserted node is zero
	temp->height = 0;

	// if tree is empty
	if ((*root) == NULL)	{
		// set parent
		temp->pr = NULL;
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

	// setting parent pointer
	temp->pr = parent;

	// fix heights
	// fix AVL property
	fixAVL(root, temp);
}

void fixAVL(struct node **root, struct node *z)	{
	int res;

	struct node *x, *y;
	// since z is the new node inserted
	y = z;
	z = z->pr;
	x = NULL;

	// fix heights till root and find violation of AVL if any
	while (z != NULL)	{
		res = setHeight(z);
		if (res == 0)
			return;
		else if (res == -1)	{
			x = y;
			y = z;
			z = z->pr;
		}
		else	{
			// find if zig zig or zig zag
			// zig zig
			// dont have to check for if x is null since we will never enter this loop
			// fixing height of z
			z->height -= 2;
			if (x->key < y->key && y->key < z->key)
				rightRotate(root, y, z);
			else if (x->key > y->key && y->key > z->key)
				leftRotate(root, z, y);
			else	{
				// fixing height of x and y
				x->height += 1;
				y->height -= 1;
				if (x->key < y->key)	{
					rightRotate(root, x, y);
					// it is implied that y->key > z->key otherwise we get above cases
					leftRotate(root, z, x);
				}
				else	{
					// x->key > y->key
					leftRotate(root, y, x);
					// implied that y->key <- z->key
					rightRotate(root, x, z);
				}
			}

			return;
		}
	}
}

void leftRotate(struct node **root, struct node *t, struct node *d)	{
	// setting right child of t
	t->rc = d->lc;
	if (t->rc != NULL)
		t->rc->pr = t;
	
	// setting parent of d
	d->pr = t->pr;
	if (d->pr == NULL)
		(*root) = d;
	else	{
		if (d->key < d->pr->key)
			d->pr->lc = d;
		else
			d->pr->rc = d;
	}

	// setting left child of d and parent of t
	d->lc = t;
	t->pr = d;
}

void rightRotate(struct node **root, struct node *d, struct node *t)	{
	// setting left child of t
	t->lc = d->rc;
	if (t->lc != NULL)
		t->lc->pr = t;

	// setting parent of d
	d->pr = t->pr;
	if (d->pr == NULL)
		(*root) = d;
	else	{
		if (d->key < d->pr->key)
			d->pr->lc = d;
		else
			d->pr->rc = d;
	}

	// setting right child of d and parent of t;
	d->rc = t;
	t->pr = d;
}

// return 0 if no height change, returns -1 if height change but balanced and return 1 if unbalanced
int setHeight(struct node *node)	{
	// assuming children dont exist
	int leftH = -1, rightH = -1;
	if (node->lc != NULL)
		leftH = node->lc->height;
	if (node->rc != NULL)
		rightH = node->rc->height;

	int prH; // parent height
	if (rightH >= leftH)
		prH = rightH + 1;
	else
		prH = leftH + 1;

	// no height change
	if (prH == node->height)
		return 0;
	else	{
		node->height = prH;
		int heightDiff = (rightH - leftH) > 0 ? (rightH - leftH) : (leftH - rightH);
		
		if (heightDiff > 1)
			return 1; // unbalanced tree
		else
			return -1; // balanced tree
	}
}

int main()	{
	srand(time(0));
	
	int key;
	struct node *root = NULL;
	
	while(1)	{
		printf("Enter the node to be inserted (-1 to exit): ");
		scanf("%d", &key);

		if (key == -1)
			break;

		insertAVL(&root, key);

		printBinaryTree(root);
	}

	return 0;
}
