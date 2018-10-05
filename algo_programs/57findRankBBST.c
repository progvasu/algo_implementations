// find the rank of an element stored in BBST

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// we need to keep track of number of nodes in the subtree including that node
// and also rotations will change the number of nodes in the subtree - so need to modify insertAVL
// also modifying printBinaryTree to print number of nodes in the subtree - for clarity
// skipping for delete

// node structure
struct node	{
	int key;
	int height;
	int num;	
	struct node *lc;
	struct node *rc;
	struct node *pr;
};

/*** INSERT - START ***/

// function declarations for AVL insert
void insertAVL(struct node **, int);
void fixAVL(struct node **, struct node *);
int setHeight(struct node *);
void leftRotate(struct node **, struct node *, struct node *);
void rightRotate(struct node **, struct node *, struct node *);
void setNum(struct node *);

void insertAVL(struct node **root, int key)	{
	// creating node to be inserted
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = key;
	temp->lc = NULL;
	temp->rc = NULL;
	// for node itself
	temp->num = 1;

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
		
		// add 1 to every node down the path
		parent->num += 1;

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

	// keeping the 'num' variable sane
	setNum(t);
	setNum(d);	
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

	// keeping the 'num' variable sane
	setNum(t);
	setNum(d);
}

void setNum(struct node *node)	{
	int l_num = 0, r_num = 0;
	
	if (node->lc != NULL)
		l_num = node->lc->num;
	if (node->rc != NULL)
		r_num = node->rc->num;
	
	node->num = l_num + r_num + 1;
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
void fillLevel(struct node *, int *, int *, int, int);
int findHeight(struct node *);
void printRankTree(struct node *);

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
void fillLevel(struct node *root, int *levelOrder, int *numOrder, int pos, int max_pos)	{
	// subtree doesn't exist - fill values for all sub levels as -1
	if (root == NULL)	{
		if (pos <= max_pos)	{
			levelOrder[pos] = -1;
			numOrder[pos] = 0;
			// fill values for both sub children
			fillLevel(NULL, levelOrder, numOrder, pos*2 + 1, max_pos);
			fillLevel(NULL, levelOrder, numOrder, pos*2 + 2, max_pos);
		}
		else
			// reached the end node of the tree
			return;
	}
	// subtree exist's
	else	{
		// filling in the level of root node
		levelOrder[pos] = root->key;
		numOrder[pos] = root->num;
		// fill in the level of children
		fillLevel(root->lc, levelOrder, numOrder, pos*2 + 1, max_pos);
		fillLevel(root->rc, levelOrder, numOrder, pos*2 + 2, max_pos);
	}
}

// find height of the given tree
int findHeight(struct node *root)	{
	if (root == NULL)	return -1;
	int left = findHeight(root->lc), right = findHeight(root->rc);
	return (1 + MAX(left, right));
}

// main function for printing the tree
void printRankTree(struct node *root)	{
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
	int numOrder[no_nodes];
	fillLevel(root, levelOrder, numOrder, 0, no_nodes - 1);
	
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
	
	// storing old value of cn
	int temp;

	// while at and above leaf level
	while (ch >= 0)	{

		// storing old value of cn
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

		// restoring value of cn
		cn = temp;

		// printing num of nodes at current height
		// moving down one level
		printf("\n");
		for (i = 0 ; i < n_ch ; i++)	{
			// if node is not null
			if (numOrder[cn] != 0)	{
				if (i == 0) 
					// for first color node at this height
					printf("%*d", mid/2, numOrder[cn++]);
				else
					// for all the remaining nodes
					printf("%*d", mid, numOrder[cn++]);
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

/*** Find Rank of an element ***/

int findRank(struct node *root, int ele)	{
	// we initialize rank as one so no need to add 1 for the ele node
	int rank = 1;
	struct node *node = root;

	while (node != NULL)	{
		if (node->key == ele)	{
			if (node->rc != NULL)
				rank += node->rc->num;
			return rank;
		}
		else if (ele < node->key)	{
			if (node->rc != NULL)
				rank += node->rc->num;
			rank += 1;
			node = node->lc;
		}
		else if (ele > node->key)	{
			node = node->rc;
		}
	}

	return -1;
}

int main()	{
	srand(time(0));

	int n = 20;
	int a[n], i, rand_index, temp;

	// create index array
	for (i = 0 ; i < n ; i++)
		a[i] = i;
		// a[i] = rand() % 1000;

	// permute it
	for (i = 0 ; i < n ; i++)	{
		rand_index = rand() % n;
		temp = a[rand_index];
		a[rand_index] = a[i];
		a[i] = temp;
	}

	struct node *root = NULL;

	// insert into AVL and check
	for (i = 0 ; i < n ; i++)	{
		insertAVL(&root, a[i]);
	}

	// print out the tree
	printRankTree(root);

	int ele, rank, correct_rank;
	
	while(1)	{
		printf("Enter the element whose rank is needed (-1 to exit): ");
		scanf("%d", &ele);

		if (ele == -1)
			break;

		rank = findRank(root, ele);
		correct_rank = n - ele;

		printf("Rank: %d, Correct Rank: %d\n\n", rank, correct_rank);
	}

	return 0;
}