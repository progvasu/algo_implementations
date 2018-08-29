#include<stdio.h>
#include<stdlib.h>

// stack implementation
struct ll_node  {
    struct node *tnode;
    struct ll_node *next;
};

struct ll_node *top = NULL;

void push(struct node *tnode) {
    struct ll_node *temp = malloc(sizeof(struct ll_node));
    temp->tnode = tnode;

    temp->next = top;
    top = temp;
}

struct node* pop()  {
    if (top == NULL)    return NULL;

    struct ll_node *temp;
    temp = top;
    top = top->next;

    return temp->tnode;
};

struct node {
    char data;
    int visited;
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
    temp->visited = 0;
    temp->parent = *parent;

    if(l_r)
        (*parent)->right = temp;
    else
        (*parent)->left = temp;
}

void visit(struct node *tnode)  {
    tnode->visited = 1;
    printf("%c ", tnode->data);
}

void inOrder(struct node* root)  {
    if (root == NULL)  return;

    struct node *cnode;
    push(root);

    while ((cnode = pop()) != NULL) {
        // pushing all left child to stack
        while(cnode != NULL && cnode->visited == 0) {
            push(cnode);
            cnode = cnode->left;
        }

        // popping and visiting the node
        cnode = pop();
        if (cnode->visited == 0)    {
            visit(cnode);
        }

        // push right child
        if (cnode->right != NULL)
            push(cnode->right);
    }
}

void preOrder(struct node* root)  {
    if (root == NULL)  return;

    struct node *cnode;
    push(root);

    while((cnode = pop()) != NULL)    {
        visit(cnode);
        if (cnode->right != NULL) push(cnode->right);
        if (cnode->left != NULL) push(cnode->left);
    }
}

void postOrder(struct node* root)  {
    if (root == NULL)  return;

    struct node *cnode;
    push(root);

    while((cnode = pop()) != NULL)    {
        // visit
        if (cnode->left == NULL || cnode->left->visited == 1)
            if (cnode->right == NULL || cnode->right->visited == 1)
                visit(cnode);

        // push current node onto stack
        if (cnode->visited == 0)
            push(cnode);

        // right child
        if (cnode->right != NULL && cnode->right->visited == 0)    {
            push(cnode->right);
        }

        // left child
        if (cnode->left != NULL && cnode->left->visited == 0)   {
            cnode = cnode->left;
            push(cnode);
        }
    }
}

int main()  {
    // initialize root
    struct node *root = malloc(sizeof(struct node));
    root->data = 'A';
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;
    root->visited = 0;

    addNode(&root, 0, 'B');
    addNode(&root, 1, 'C');

    addNode(&(root->left), 1, 'D');
    addNode(&(root->left->right), 0, 'G');
    addNode(&(root->left->right), 1, 'H');

    addNode(&(root->right), 0, 'E');
    addNode(&(root->right), 1, 'F');
    addNode(&(root->right->right), 0, 'I');

    //printf("Inorder Traversal: ");
    //inOrder(root);
    //printf("\n");

    //printf("Preorder Traversal: ");
    //preOrder(root);
    //printf("\n");

    printf("Postorder Traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}
