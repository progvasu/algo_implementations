// AVL node
// define a node like this

struct node	{
	int key;
	int height;	
	struct node *lc;
	struct node *rc;
	struct node *pr;
};

#include "45printBinaryTree.h"

// ***** INSERTING INTO AVL ***** //

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
			else if (x->key >= y->key && y->key >= z->key)
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
			
			// only one interation is required to fix the tree
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
	if (prH == node->height)	{
		// but is unbalanced? - due to deletion
		int heightDiff = (rightH - leftH) > 0 ? (rightH - leftH) : (leftH - rightH);
		
		if (heightDiff > 1)
			return 1; // unbalanced tree
		else
			return 0; // balanced tree
	}
	else	{
		node->height = prH;
		int heightDiff = (rightH - leftH) > 0 ? (rightH - leftH) : (leftH - rightH);
		
		if (heightDiff > 1)
			return 1; // unbalanced tree
		else
			return -1; // balanced tree
	}
}

// ***** DELETING A NODE ***** //

// function declaration for deleting a node from AVL
void deleteAVL(struct node **, int);
void deleteNode(struct node **, struct node *);
void transplant(struct node **, struct node *, struct node *);
// setHeight, leftRotate and rightRotate defined above
void fixDelAVL(struct node **, struct node *);

// this delete procedure replaces the entire node and not just the values
void deleteAVL(struct node **root, int key)	{
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
	if (node->lc == NULL)	{
		transplant(root, node, node->rc);
		fixDelAVL(root, node->pr);
	}
	else if (node->rc == NULL)	{
		transplant(root, node, node->lc);
		fixDelAVL(root, node->pr);
	}
	else	{
		// find inorder successor
		struct node *suc = node->rc;
		while (suc->lc != NULL)	{
			suc = suc->lc;
		}
		
		// height could change of suc node parent
		struct node *temp;
		
		if (suc->pr == node)
			temp = suc;
		else
			temp = suc->pr;

		if (suc->pr != node)	{
			transplant(root, suc, suc->rc); // because there is no left child - transplant handles the case if right child is NULL
			suc->rc = node->rc;
			suc->rc->pr = suc;
		}
		
		transplant(root, node, suc);
		// left child will definitely be there
		suc->lc = node->lc;
		suc->lc->pr = suc;
		
		// fixing height of suc old pos
		fixDelAVL(root, temp);
	}
}

void fixDelAVL(struct node **root, struct node *z)	{
	int res;

	struct node *x, *y;

	// fix heights till root and find violation of AVL if any
	while (z != NULL)	{
		res = setHeight(z);
		//printf("Current:%d Height:%d Res:%d\n", z->key, z->height, res);
		if (res == 0)
			// no height change so we return
			z = z->pr;
			// return;
		else if (res == -1)	{
			// height changed but still balanced - no issue
			// we move z one level above
			z = z->pr;
		}
		else	{
			// AVL violated
			// we have our z we need to find x and y
			if (z->lc != NULL && z->lc->height + 1 == z->height)	{
				y = z->lc;
				if (y->lc != NULL && y->lc->height + 1 == y->height)
					x = y->lc;
				else
					x = y->rc;
			}
			else	{
				y = z->rc;
				if (y->rc != NULL && y->rc->height + 1 == y->height)
					x = y->rc;
				else
					x = y->lc;
			}

			// find if zig zig or zig zag
			// zig zig
			if (x->key < y->key && y->key < z->key)	{
				rightRotate(root, y, z);
				// fix heights of z - height of x remains same
				setHeight(z);
				// change z to y - y's height will be fixed in next iteration
				z = y;
			}
			else if (x->key >= y->key && y->key >= z->key)	{
				leftRotate(root, z, y);
				// fix heights of z - height of x remains same
				setHeight(z);
				// change z to y - y's height will be fixed in next iteration
				z = y;
			}
			// zig zag
			else	{
				if (x->key < y->key)	{
					rightRotate(root, x, y);
					// it is implied that y->key > z->key otherwise we get above cases
					leftRotate(root, z, x);
					// fixing heights
					setHeight(z);
					setHeight(y);
					// not changing height of x recursion will take care of that
					z = x;
				}
				else	{
					// x->key > y->key
					leftRotate(root, y, x);
					// implied that y->key <- z->key
					rightRotate(root, x, z);
					// fixing heights
					setHeight(z);
					setHeight(y);
					// not changing height of x recursion will take care of that
					z = x;
				}// end of else
			}// end of outer else
			
		}// end of else (res == -2)
	}// end of while
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