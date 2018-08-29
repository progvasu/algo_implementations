#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    struct node *left;
    struct node *right;
    struct node *parent;
};

void addNode(struct node **parent, int l_r, char data)  {
    struct node *temp = malloc(sizeof(struct node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = *parent;

    if (l_r)    (*parent)->right = temp;
    else    (*parent)->left = temp;
}

int max(int a, int b)   {
    return a > b ? a : b;
}

int heightTree(struct node *root)    {
    if (root->left == NULL && root->right == NULL)
        return 0;
    else if(root->left == NULL)
        return 1 + heightTree(root->right);
    else if(root->right == NULL)
        return 1 + heightTree(root->left);
    else
        return 1 + max(heightTree(root->left), heightTree(root->right));
}


int main()  {
    // initialize root
    struct node *root = malloc(sizeof(struct node));
    root->data = 'A';
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;

    addNode(&root, 0, 'B');
    addNode(&root, 1, 'C');

    addNode(&(root->left), 1, 'D');
    addNode(&(root->left->right), 0, 'G');
    addNode(&(root->left->right), 1, 'H');

    addNode(&(root->right), 0, 'E');
    addNode(&(root->right), 1, 'F');
    addNode(&(root->right->right), 0, 'I');

    printf("Height of Tree is %d", heightTree(root));

    return 0;
}
