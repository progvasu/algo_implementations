#include<stdio.h>
#include<stdlib.h>

struct node {
    char data;
    struct node *left;
    struct node *right;
    struct node *parent;
};

// l_r = 0(left) / 1(right)
void addNode(struct node **parent, int l_r, char data)  {
    // create a node
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = *parent;

    if(l_r)
        (*parent)->right = temp;
    else
        (*parent)->left = temp;
}

void visit(struct node *tnode)  {
    printf("%c ", tnode->data);
}

void inOrder(struct node* tnode)  {
    if (tnode == NULL)  return;

    if (tnode->left != NULL)    inOrder(tnode->left);
    visit(tnode);
    if (tnode->right != NULL)   inOrder(tnode->right);
}

void preOrder(struct node* tnode)  {
    if (tnode == NULL)  return;

    visit(tnode);
    if (tnode->left != NULL)    preOrder(tnode->left);
    if (tnode->right != NULL)   preOrder(tnode->right);
}

void postOrder(struct node* tnode)  {
    if (tnode == NULL)  return;

    if (tnode->left != NULL)    postOrder(tnode->left);
    if (tnode->right != NULL)   postOrder(tnode->right);
    visit(tnode);
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

    printf("Inorder Traversal: ");
    inOrder(root);
    printf("\n");

    printf("Preorder Traversal: ");
    preOrder(root);
    printf("\n");

    printf("Poatorder Traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}
