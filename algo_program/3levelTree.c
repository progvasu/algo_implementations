#include<stdio.h>
#include<stdlib.h>

struct node{
    char data;
    int level;
    struct node *left;
    struct node *right;
    struct node *parent;
};

void addNode(struct node **parent, int l_r, char data)  {
    struct node *temp = malloc(sizeof(struct node));

    temp->data = data;
    temp->level = 0;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = *parent;

    if (l_r)    (*parent)->right = temp;
    else    (*parent)->left = temp;
}

void visit(struct node *cnode)    {
    if (cnode->parent == NULL)  {
        printf("%c:%d  ", cnode->data, cnode->level);
    }
    else    {
        cnode->level = cnode->parent->level + 1;
        printf("%c:%d  ", cnode->data, cnode->level);
    }
}

void preOrder(struct node *cnode)    {
    if (cnode == NULL)  return;

    visit(cnode);
    preOrder(cnode->left);
    preOrder(cnode->right);
}

int main()  {
    // initialize root
    struct node *root = malloc(sizeof(struct node));
    root->data = 'A';
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    root->level = 0;

    addNode(&root, 0, 'B');
    addNode(&root, 1, 'C');

    addNode(&(root->left), 1, 'D');
    addNode(&(root->left->right), 0, 'G');
    addNode(&(root->left->right), 1, 'H');

    addNode(&(root->right), 0, 'E');
    addNode(&(root->right), 1, 'F');
    addNode(&(root->right->right), 0, 'I');

    preOrder(root);

    return 0;
}
