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

// function declarations for deletion
void deleteBST(struct node **, int key);
void deleteNode(struct node **, struct node *);
void transplant(struct node **, struct node *, struct node *);

// this delete procedure replaces the entire node and not just the values
void deleteBST(struct node **root, int key)	{
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

void deleteNode(struct node **root, struct node *node)	{
	if (node->lc == NULL)
		transplant(root, node, node->rc);
	else if (node->rc == NULL)
		transplant(root, node, node->lc);
	else	{
		// find inorder successor
		struct node *suc = node->rc;
		while (suc->lc != NULL)	{
			suc = suc->lc;
		}
		if (suc->pr != node)	{
			transplant(root, suc, suc->rc);
			// because there is no left child
			suc->rc = node->rc;
			suc->rc->pr = suc;
		}
		transplant(root, node, suc);
		suc->lc = node->lc;
		suc->lc->pr = suc;
	}
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

#include "45printBinaryTree.h" 

int main()	{
	srand(5);
	
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
	printBinaryTree(root);
	
	// delete node
	int del_node;

	while (1)	{
		printf("Enter number to be deleted (-1 to exit): ");
		scanf("%d", &del_node);
		if (del_node == -1)
			break;
		
		deleteBST(&root, del_node);

		if (root == NULL)
			break;

		printBinaryTree(root);
	}

	return 0;
}
