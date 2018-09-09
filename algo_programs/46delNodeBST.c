// delete node from a BST

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node	{
	int key;
	struct node *pr;
	struct node *lc;
	struct node *rc;
};

void insertBST(struct node **root, int key)	{
	// if first node
	if (*root == NULL)	{
		struct node *temp = (struct node *)malloc(sizeof(struct node));
		temp->key = key;
		temp->lc = NULL;
		temp->rc = NULL;
		temp->pr = NULL;
		(*root) = temp;
	}
	else	{
		if (key < (*root)->key)	{
			if ((*root)->lc == NULL)	{
				struct node *temp = (struct node *)malloc(sizeof(struct node));
				temp->key = key;
				temp->lc = NULL;
				temp->rc = NULL;
				temp->pr = (*root);
				(*root)->lc = temp;
			}
			else	{
				insertBST(&((*root)->lc), key);
			}
		}
		else	{
			if ((*root)->rc == NULL)	{
				struct node *temp = (struct node *)malloc(sizeof(struct node));
				temp->key = key;
				temp->lc = NULL;
				temp->rc = NULL;
				temp->pr = (*root);
				(*root)->rc = temp;
			}
			else	{
				insertBST(&((*root)->rc), key);
			}
		}
	}
}

void deleteBST(struct node **node, int key)	{
	// find the key in the tree
	while ((*node)->key != key)	{
		if (key < (*node)->key)
			node = &(*node)->lc;
		else
			node = &(*node)->rc;

		if ((*node) == NULL)	{
			printf("NODE NOT FOUND!\n");
			return;
		}
	}

	struct node *temp = (*node);
	// if no children
	if ((*node)->lc == NULL || (*node)->rc == NULL)	{
		if ((*node)->lc == NULL)	{
			if ((*node)->key < (*node)->pr:)
		}
			
	}
	free(temp);
}

#include "45printBST.h" 

int main()	{
	srand(time(0));
	int n = 15;
	int a[n], i, temp, rand_index;
	
	// creating sequence array
	for (i = 0 ; i < n ; i++)
		a[i] = i;
	
	// permuting it
	for (i = 0 ; i < n ; i++)	{
		rand_index = rand() % n;
		temp = a[rand_index];
		a[rand_index] = a[i];
		a[i] = temp;
	}

	// inserting into BST
	struct node *root = NULL;
	for(i = 0 ; i < n ; i++)
		insertBST(&root, a[i]);

	// print BST
	treePrint(root);
	
	// delete node
	int del_node;
	printf("ENTRE: ");
	scanf("%d", &del_node);
	deleteBST(&root, del_node);
	treePrint(root);

	return 0;
}
