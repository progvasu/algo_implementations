// print a BST

#define MAX(X, Y) ((X > Y ? X : Y))

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

	// printing from root to leaf

	// mid - spacing between nodes for the current height
	// cn - current node to be printed
	// n_ch - number of nodes at current height
	// ch - current height
	// ne - number of edges at current height
	int mid, cn, n_ch, ch, i, ne;
	
	mid = 4 * power(2, height);
	cn = 0; 
	n_ch = 1;
	ch = height;
	
	while (ch >= 0)	{
		for (i = 0 ; i < n_ch ; i++)	{
			if (levelOrder[cn] != -1)	{
				if (i == 0) // for first node at this height
					printf("%*d", mid/2, levelOrder[cn++]);
				else
					printf("%*d", mid, levelOrder[cn++]);
			}
			else	{
				cn++;
				if (i == 0)
					printf("%*s", mid/2, "-");
				else
					printf("%*s", mid, "-");
			}
		}

		// adding appropriate height for edges and edges
		int es, en;
		es = 2;
		en = mid - 2;
		for(i = 0 ; i < power(2, ch - 1) ; i++)	{
			printf("\n");
			ne = 2 * n_ch;
			// first edge
			printf("%*c", mid/2 - i*2 - 1, '-');
			// remaining
			ne--;
			while (ne > 0)	{
				printf("%*c", es, '-');
				ne--;
				if (ne > 0)
					printf("%*c", en, '-');	
				ne--; 
			}
			es += 4;
			en -= 4;
		}
		printf("\n");

		mid /= 2;
		n_ch *= 2;
		ch--;
	}
}
