// testing header file for AVL module

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

#include "53modAVL.h"

int isAVL(struct node *root)	{
	if (root == NULL)
		return 1;

	int leftH = findHeight(root->lc);
	int rightH = findHeight(root->rc);
	int diff = rightH - leftH;

	// inorder to check the implementation we are not using the height variable defined in nodes
	if (diff < 0)
		diff = -diff;

	if (diff > 1)
		return 0;

	return (isAVL(root->lc) && isAVL(root->rc));
}

int main()	{
	// how to test AVL?
	// create a tree randomly and then randomly delete all nodes
	// at each point of insertion and deletion need to check if AVL property is maintained or not

	srand(time(0));

	// int n = 15;
	// int a[n], i, rand_index, temp;

	// // create index array
	// for (i = 0 ; i < n ; i++)
	// 	a[i] = i;
	// // permute it
	// for (i = 0 ; i < n ; i++)	{
	// 	rand_index = rand() % n;
	// 	temp = a[rand_index];
	// 	a[rand_index] = a[i];
	// 	a[i] = temp;
	// }

	// struct node *root = NULL;

	// // insert into AVL and check
	// for (i = 0 ; i < n ; i++)	{
	// 	insertAVL(&root, a[i]);

	// 	// check to see if AVL property satisfied
	// 	if (!isAVL(root))	{
	// 		printf("AVL property violated\n");
	// 		break;
	// 	}
	// }

	// printBinaryTree(root);

	// // permute the numbers
	// for (i = 0 ; i < n ; i++)	{
	// 	rand_index = rand() % n;
	// 	temp = a[rand_index];
	// 	a[rand_index] = a[i];
	// 	a[i] = temp;
	// }

	// // delete from AVL and check
	// for (i = 0 ; i < n ; i++)	{
	// 	deleteAVL(&root, a[i]);

	// 	// check to see if AVL property satisfied
	// 	if (!isAVL(root))	{
	// 		printf("AVL property violated\n");
	// 		printBinaryTree(root);
	// 		break;
	// 	}
	// }

	// testing for a few thousand iterations

	int iter = 100000;
	int n = 20;
	// separate and b to make debugging easier
	int a[n], b[n], i, rand_index, temp;
	struct node *root;

	// create index array
	for (i = 0 ; i < n ; i++)	{
		a[i] = i;
		b[i] = i;
	}

	while (iter--)	{
		// permute array - a
		for (i = 0 ; i < n ; i++)	{
			rand_index = rand() % n;
			temp = a[rand_index];
			a[rand_index] = a[i];
			a[i] = temp;
		}		

		root = NULL;

		// insert into AVL and check
		for (i = 0 ; i < n ; i++)	{
			insertAVL(&root, a[i]);

			// check to see if AVL property satisfied
			if (!isAVL(root))	{
				printf("AVL property violated\n");
				printBinaryTree(root);
				// print input array
				for (i = 0 ; i < n ; i++)
					printf("%d  ", a[i]);
				exit(0);
			}
		}

		// permute array - b
		for (i = 0 ; i < n ; i++)	{
			rand_index = rand() % n;
			temp = b[rand_index];
			b[rand_index] = b[i];
			b[i] = temp;
		}

		// delete from AVL and check
		for (i = 0 ; i < n ; i++)	{
			deleteAVL(&root, b[i]);

			// check to see if AVL property satisfied
			if (!isAVL(root))	{
				printf("AVL property violated\n");
				printBinaryTree(root);
				
				// print array a and b
				for (i = 0 ; i < n ; i++)
					printf("%d  ", a[i]);
				printf("\n");
				for (i = 0 ; i < n ; i++)
					printf("%d  ", b[i]);
				printf("\n");

				exit(0);
			}
		}
	}

	// checking for specific inputs

	// int n = 10;
	// int a[] = {8  ,1,  9,  3 , 5  ,6  ,2  ,7  ,0  ,4}, b[] = {8  ,9,  5,  3 , 2 , 1 , 7 , 0 , 6 , 4};
	// int i, rand_index, temp;
	// struct node *root = NULL;

	// // insert into AVL and check
	// for (i = 0 ; i < n ; i++)	{
	// 	insertAVL(&root, a[i]);

	// 	// check to see if AVL property satisfied
	// 	if (!isAVL(root))	{
	// 		printf("AVL property violated\n");
	// 		break;
	// 	}
	// }

	// printBinaryTree(root);

	// // delete from AVL and check
	// for (i = 0 ; i < n ; i++)	{
	// 	deleteAVL(&root, b[i]);

	// 	printf("Delete - %d\n", b[i]);
	// 	printBinaryTree(root);
	// 	if (getchar() == -1)
	// 		break;

	// 	// check to see if AVL property satisfied
	// 	if (!isAVL(root))	{
	// 		printf("AVL property violated - %d\n", b[i]);
	// 		break;
	// 	}
	// }

	return 0;
}