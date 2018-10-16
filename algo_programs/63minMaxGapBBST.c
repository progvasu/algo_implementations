// find the min and max gap in a BBST
// not implementing mingap for now - easy - need to treat leaves differently

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node	{
	int key;
	int min;
	int max;
	int mingap;
	int height;	
	struct node *lc;
	struct node *rc;
	struct node *pr;
};

// ***** INSERTING INTO AVL ***** //

// function declarations for AVL insert
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
	temp->min = key;
	temp->max = key;

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
			// updating max 
			if (pos->max < key)
				pos->max = key;
			// updating min
			if (pos->min > key)
				pos->min = key;

			pos = pos->lc;
		}
		else	{
			// updating max 
			if (pos->max < key)
				pos->max = key;
			// updating min
			if (pos->min > key)
				pos->min = key;

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

	// fixing t->max
	// figure out max - because max could have been from d subtree - which has now changed
	t->max = t->key;
	if (t->lc != NULL && t->lc->max > t->max)
		t->max = t->lc->max;
	if (t->rc != NULL && t->rc->max > t->max)
		t->max = t->rc->max;

	// fixing d->max
	// figure out max - because max could have been from d left subtree - which has now changed
	d->max = d->key;
	if (d->lc != NULL && d->lc->max > d->max)
		d->max = d->lc->max;
	if (d->rc != NULL && d->rc->max > d->max)
		d->max = d->rc->max;

	// fixing t->min
	// figure out min - because min could have been from d subtree - which has now changed
	t->min = t->key;
	if (t->lc != NULL && t->lc->min < t->min)
		t->min = t->lc->min;
	if (t->rc != NULL && t->rc->min < t->min)
		t->min = t->rc->min;

	// fixing d->min
	// figure out min - because min could have been from d left subtree - which has now changed
	d->min = d->key;
	if (d->lc != NULL && d->lc->min < d->min)
		d->min = d->lc->min;
	if (d->rc != NULL && d->rc->min < d->min)
		d->min = d->rc->min;
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

		// fixing t->max
	// figure out max - because max could have been from d subtree - which has now changed
	t->max = t->key;
	if (t->lc != NULL && t->lc->max > t->max)
		t->max = t->lc->max;
	if (t->rc != NULL && t->rc->max > t->max)
		t->max = t->rc->max;

	// fixing d->max
	// figure out max - because max could have been from d left subtree - which has now changed
	d->max = d->key;
	if (d->lc != NULL && d->lc->max > d->max)
		d->max = d->lc->max;
	if (d->rc != NULL && d->rc->max > d->max)
		d->max = d->rc->max;

	// fixing t->min
	// figure out min - because min could have been from d subtree - which has now changed
	t->min = t->key;
	if (t->lc != NULL && t->lc->min < t->min)
		t->min = t->lc->min;
	if (t->rc != NULL && t->rc->min < t->min)
		t->min = t->rc->min;

	// fixing d->min
	// figure out min - because min could have been from d left subtree - which has now changed
	d->min = d->key;
	if (d->lc != NULL && d->lc->min < d->min)
		d->min = d->lc->min;
	if (d->rc != NULL && d->rc->min < d->min)
		d->min = d->rc->min;
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

/*** print tree - START ***/

// function declarations
int power(int, int);
void fillLevel(struct node *, int *, int *, int *, int, int);
int findHeight(struct node *);
void printIntervalTree(struct node *);

// max function macro
#define MAX(X, Y) ((X > Y ? X : Y))

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

// calculate the level order traversal of tree
void fillLevel(struct node *root, int *levelOrder, int *minOrder, int *maxOrder, int pos, int max_pos)	{
	// subtree doesn't exist - fill values for all sub levels as -1
	if (root == NULL)	{
		if (pos <= max_pos)	{
			levelOrder[pos] = -1;
			minOrder[pos] = -1;
			maxOrder[pos] = -1;
			// fill values for both sub children
			fillLevel(NULL, levelOrder, minOrder, maxOrder, pos*2 + 1, max_pos);
			fillLevel(NULL, levelOrder, minOrder, maxOrder, pos*2 + 2, max_pos);
		}
		else
			// reached the end node of the tree
			return;
	}
	// subtree exist's
	else	{
		// filling in the level of root node
		levelOrder[pos] = root->key;
		minOrder[pos] = root->min;
		maxOrder[pos] = root->max;
		// fill in the level of children
		fillLevel(root->lc, levelOrder, minOrder, maxOrder, pos*2 + 1, max_pos);
		fillLevel(root->rc, levelOrder, minOrder, maxOrder, pos*2 + 2, max_pos);
	}
}

// find height of the given tree
int findHeight(struct node *root)	{
	if (root == NULL)	return -1;
	int left = findHeight(root->lc), right = findHeight(root->rc);
	return (1 + MAX(left, right));
}

// main function for printing the tree
void printBinaryTree(struct node *root)	{
	// calculate height of the tree
	int height = findHeight(root);

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
	int no_nodes = power(2, height + 1) - 1;

	// find level order traversal
	int levelOrder[no_nodes];
	int minOrder[no_nodes];
	int maxOrder[no_nodes];
	fillLevel(root, levelOrder, minOrder, maxOrder, 0, no_nodes - 1);

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

	// for storing old value of cn;
	int temp;
	
	// while at and above leaf level
	while (ch >= 0)	{

		temp = cn;

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

		printf("\n");

		cn = temp;

		// printing all min of every node
		for (i = 0 ; i < n_ch ; i++)	{
			// if node is not null
			if (minOrder[cn] != -1)	{
				if (i == 0) 
					// for first node at this height
					printf("%*d", mid/2, minOrder[cn++]);
				else
					// for all the remaining nodes
					printf("%*d", mid, minOrder[cn++]);
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

		printf("\n");

		cn = temp;

		// printing max of every node
		for (i = 0 ; i < n_ch ; i++)	{
			// if node is not null
			if (maxOrder[cn] != -1)	{
				if (i == 0) 
					// for first node at this height
					printf("%*d", mid/2, maxOrder[cn++]);
				else
					// for all the remaining nodes
					printf("%*d", mid, maxOrder[cn++]);
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
} // end of function


int main()	{
	srand(time(0));
	
	int n = 15;
	int a[n], i;

	// initializing with random unique nodes
	a[0] = rand() % 5 + 1;

	for (i = 1 ; i < n ; i++)	
		a[i] = a[i - 1] + (rand() % 10) + 1;

	struct node *root = NULL;
	
	// insert into AVL tree
	for (i = 0 ; i < n ; i++)
		insertAVL(&root, a[i]);

	// printing out the AVL tree
	printBinaryTree(root);

	return 0;
}