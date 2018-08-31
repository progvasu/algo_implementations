// Find first minimum number on the RHS of ai - assuming all positive numbers

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct node	{
	int index;
	struct node *next;
};

void push(struct node **head, int value)	{
	// create a new node
	struct node *temp = malloc(sizeof(struct node));
	temp->index = value;
	temp->next = *head;
	*head = temp;
}

int peek(struct node *head)	{
	if (head == NULL)
		return -1;
	return head->index;
}

int pop(struct node **root)	{
	if ((*root) == NULL)
		return -1;
	int value = (*root)->index;
	*root = (*root)->next;
	return value;
}

int main()	{
	srand(time(0));
	int n = 10;
	int a[n], min[n], i, j ;

	// printing indices
	for(i = 0 ; i < n ; i++)
		printf("%4d", i);
	printf("  Indexes\n");

	// initialize a random array of 10 numbers
	for(i = 0 ; i < n ; i++)	{
		a[i] = (rand() % 100);
		printf("%4d", a[i]);
	}
	printf("  Input\n");

	// brute force approach - O(n^2)
	for(i = 0 ; i < n ; i++)	{
		for (j = i + 1 ; j < n ; j++)	{
			if (a[j] < a[i])	{
				min[i] = j; 
				break;
			}
		}
		if (j == n)	{
			min[i] = 0;
		}
	}

	for(i = 0 ; i < n ; i++)
		printf("%4d", min[i]);
	printf("  Brute\n");

	// optimized algo using stack
	// verifying stack operation
	//struct node *head = NULL;
	//push(&head, 1);
	//push(&head, 2);
	//pop(&head);
	//printf("%d\n", pop(&head));
	//printf("%d\n", head==NULL);

	int top_index;
	struct node *head = NULL;

	// pushing first element on the stack
	push(&head, 0);
	for(i = 1 ; i < n ; i++)	{
		top_index = peek(head);
		while(head != NULL && a[i] < a[top_index])	{
			min[top_index] = i;
			pop(&head);
			top_index = peek(head);
		}
		push(&head, i);
	}

	// will have the last element definitely in the stack
	while (peek(head) != -1)	{
		min[pop(&head)] = 0;
	}

	// print optimum algo
	for (i = 0 ; i < n ; i++)
		printf("%4d", min[i]);
	printf("  OptiAlgo\n");

	return 0;
}
