#include<stdio.h>
#include<stdlib.h>

struct node	{
	int key;
	int leaf;
	struct node *parent;
	struct node *children[10];
};

// number to array - tested
void numberToArray(int *num_array, int number)	{
	int key, i = 0;

	while(number > 0)	{
		key = number % 10;
		num_array[i++] = key;
		number /= 10;
	}

	if (i != 10)
		num_array[i] = -1;
}

// get size of array - tested
int getLength(int *num_array)	{
	int i = 0, count = 0;

	while(i <= 9 && num_array[i] != -1)	{
		count++;
		i++;
	}

	return count;
}

// can make a new function to search for a particular key
// and another for number which calls key function
// search if a number exist
int search(struct node *cnode, int search_value)	{
	if (cnode == NULL)	return 0;

	int i, num_array[10], num_len;

	numberToArray(num_array, search_value);
	num_len = getLength(num_array);

	for (i = num_len - 1 ; i >= 0 ; i--)	{
        cnode = cnode->children[num_array[i]];
        if (cnode == NULL)
            return 0;
	}

	// if entire loop executes we found the search_value
	if (cnode->leaf == 1)
        return 1;
    else
        return 0;
}

void addNode(struct node **parent, int key)	{
	// otherwise add that as a key
	int i;
	struct node *temp = malloc(sizeof(struct node));
	temp->key = key;
	temp->parent = *parent;
    temp->leaf = 0;
    for (i = 0 ; i <= 9 ; i++)
        temp->children[i] = NULL;

	(*parent)->children[key] = temp;

}

void addNumber(struct node **cnode, int number)	{
	// converting number to number array
	int num_array[10], num_len;
	numberToArray(num_array, number);
	num_len = getLength(num_array);

	// looping over the number array
	int i;
	for(i = num_len - 1 ; i >= 0 ; i--) {
        // check to see if the child exists
        if ((*cnode)->children[num_array[i]] == NULL)   {
            // child doesn't exist so adding it
            addNode(cnode, num_array[i]);
        }

        // moving forward to child
        cnode = &((*cnode)->children[num_array[i]]);
	}

	// we inserted the given number so changing the leaf value to one
	(*cnode)->leaf = 1;
}

int childrenExists(struct node *cnode)  {
    int i;

    for (i = 0; i <= 9 ; i++)  {
        if (cnode->children[i] != NULL)
            return 1;
        else
            return 0;
    }

    return 0;
}

// 0 = delete unsuccessful, 1 = delete successful
int delNumber(struct node **cnode, int number)  {
    // if number doesn't exist in the tree return 0
    if (!search(*cnode, number))    {
        printf("Can't delete node %d - Doesn't exist\n");
        return 0;
    }

    // delete node
    // start from last number and keep on deleting until
    // leaf = 1 exists for some parent
    int num_array[10], num_len, i;
    struct node *temp;
    numberToArray(num_array, number);
    num_len = getLength(num_array);

    // get to the last node of number
    for (i = num_len - 1 ; i >= 0 ; i--)    {
        cnode = &((*cnode)->children[num_array[i]]);
    }

    // if the children of the node exists we cannot delete that node
    // just change the leaf flag to 0
    if (childrenExists(*cnode)) {
        (*cnode)->leaf = 0;
        return 1;
    }
    else    {
        // backtrack from here and keep deleting until leaf != 1
        for (i = num_len - 1 ; i >= 0 ; i--)    {
            temp = (*cnode);
            cnode = &((*cnode)->parent);
            free(temp);
            (*cnode)->children[i] = NULL;

            // check to see if parent of the node is a leaf or has some children
            if ((*cnode)->leaf == 1 || childrenExists(*cnode))
                // cannot delete more
                return 1;
        }
    }
}

int main()	{
    int i;

	// create root
	struct node *root = malloc(sizeof(struct node));
	root->key = 0;
	root->parent = NULL;
	root->leaf = 0;

	for (i = 0 ; i <= 9 ; i++)
        root->children[i] = NULL;

    // printf("ANSWER = %d", root->children[0] == NULL);

	// adding nodes
	addNumber(&root, 1348);
    addNumber(&root, 1);
    addNumber(&root, 475);
    addNumber(&root, 4589);
    addNumber(&root, 731);
    addNumber(&root, 8910);

    // deleting a node
    delNumber(&root, 8910);

	// search for a node
	printf("1348 exist? = %d\n", search(root, 1348));
	printf("134 exist? = %d\n", search(root, 134));
    printf("1 exist? = %d\n", search(root, 1));
    printf("132 exist? = %d\n", search(root, 132));
    printf("475 exist? = %d\n", search(root, 475));
    printf("4750 exist? = %d\n", search(root, 4750));
    printf("4589 exist? = %d\n", search(root, 4589));
    printf("731 exist? = %d\n", search(root, 731));
    printf("73111 exist? = %d\n", search(root, 73111));
    printf("8910 exist? = %d\n", search(root, 8910));
    printf("99991 exist? = %d\n", search(root, 99991));

    // testing numberToArray
    // int num_array[10], number = 1234567890, length, i = 0;
    // numberToArray(num_array, number);
    // for(i ; i < getLength(num_array) ; i++)
    //    printf("%d\n", num_array[i]);

	return 0;
}
