#include<stdio.h>
#include<stdlib.h>

struct node {
    char *key;
    int leaf;
    struct node *parent;
    struct node *children[10];
};

// returns length of the input string
int getLength(char *key) {
    int len = 0;
    while(key[len++] != '\0')   {}
    return len;
}

// adding number to compressed trie
void addNumber(struct node **cnode, char *key)  {
	// loop variables
	int i;

	// if the child node at 0 position is empty just insert
	if ((*cnode)->children[key[0]] == NULL)	{
		// insert a new node at key[0]
		struct node *temp = malloc(sizeof(struct node));
		temp->key = key;
		temp->parent = *parent;
		temp->leaf = 1;
		for (i = 0 ; i <= 9 ; i++)
			temp->children[i] = NULL;

		(*parent)->children[key[0]] = temp;
	}
	else {
		// case 1. complete match with the key of the child

	}
}


int main()  {
	int i;

	// create root
	struct node *root = malloc(sizeof(struct node));
	root->key = "";
	root->parent = NULL;
	root->leaf = 0;

	for (i = 0 ; i <= 9 ; i++)
        root->children[i] = NULL;

    // adding nodes
	addNumber(&root, "1348");

    return 0;
}
