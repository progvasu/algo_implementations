// print a Binary Tree (key, lc, rc)

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
void fillLevel(struct node *root, int *levelOrder, int pos, int max_pos)	{
	// subtree doesn't exist - fill values for all sub levels as -1
	if (root == NULL)	{
		if (pos <= max_pos)	{
			levelOrder[pos] = -1;
			// fill values for both sub children
			fillLevel(NULL, levelOrder, pos*2 + 1, max_pos);
			fillLevel(NULL, levelOrder, pos*2 + 2, max_pos);
		}
		else
			// reached the end node of the tree
			return;
	}
	// subtree exist's
	else	{
		// filling in the level of root node
		levelOrder[pos] = root->key;
		// fill in the level of children
		fillLevel(root->lc, levelOrder, pos*2 + 1, max_pos);
		fillLevel(root->rc, levelOrder, pos*2 + 2, max_pos);
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
	fillLevel(root, levelOrder, 0, no_nodes - 1);
	
	// printing in reverse order from leaves to root
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
} // end of function
