// testing program 37

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

int test()	{
	int n = 10;
	int a[n], i, j, k, min_h, max_area = -1, left, right;

	// initializing the input array
	for (i = 0 ; i < n ; i++)	{
		a[i] = rand() % 9 + 1; // doesn't make sense to have a zero
	}

	// finding max area using brute force method
	for (i = 0 ; i < n ; i++)	{
		for (j = i ; j < n  ; j++)	{
			min_h = a[i];
			for (k = i + 1 ; k <= j ; k++)	{
				if (a[k] < min_h)
					min_h = a[k];
			}

			if (min_h * (j - i) > max_area)	{
				max_area = min_h * (j - i);
				left = i;
				right = j;
			}
		}
	}

	// using optimized algorithm
	int l_min[n], r_min[n], top_index;
	struct node *head = NULL;

	// initializing r_min
	// pushing first element on the stack
	push(&head, 0);
	for(i = 1 ; i < n ; i++)	{
		top_index = peek(head);
		while(head != NULL && a[i] < a[top_index])	{
			r_min[top_index] = i;
			pop(&head);
			top_index = peek(head);
		}
		push(&head, i);
	}

	// will have the last element definitely in the stack
	while (peek(head) != -1)	{
		r_min[pop(&head)] = n; // for ease in calculating max are of hist
	}

	head = NULL;
	// initializing l_min
	// pushing last element on the stack
	push(&head, n - 1);
	for(i = n - 2 ; i >= 0 ; i--)	{
		top_index = peek(head);
		while(head != NULL && a[i] < a[top_index])	{
			l_min[top_index] = i;
			pop(&head);
			top_index = peek(head);
		}
		push(&head, i);
	}

	// will have the last element definitely in the stack
	while (peek(head) != -1)	{
		l_min[pop(&head)] = -1; // for ease of calculating area of the hist
	}

	// optimized algorithm
	int max_area_o = -1 , left_o = -1, right_o = -1;
	for (i = 0 ; i < n ; i++)	{
		if (a[i] * (r_min[i] - l_min[i] - 2) > max_area_o)	{
			max_area_o = a[i] * (r_min[i] - l_min[i] - 2);
			left_o = l_min[i] + 1;
			right_o = r_min[i] - 1;
		}
	}

	for (i = 0 ; i < n ; i++)	{
		printf("%3d", a[i]);
	}
	
	if (max_area == max_area_o)	{
		printf("  Correct\n");
		return 1;
	}
	else	{
		printf("  Incorrect\n");
		printf("Brute Area = %d, Left = %d, Right = %d\n", max_area, left, right);
		printf("Opti_Area = %d, Left = %d, Right = %d\n", max_area_o, left_o, right_o);
		return 0;
	}
}

int main()	{
	srand(time(0));
	int n = 100000;

	while(n-- > 0 && test());

	return 0;
}

