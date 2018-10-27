#include<stdio.h> 
#include<stdlib.h> 

struct Node
{
	int data;
	struct Node* next;
};

void append(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref;
	new_node->data = new_data;
	new_node->next = NULL;

	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	while (last->next != NULL)
		last = last->next;

	last->next = new_node;
	return;
}

static void reverse(struct Node** head_ref)
{
	struct Node* prev = NULL;
	struct Node* current = *head_ref;
	struct Node* next = NULL;
	
	while (current != NULL)
	{
		next = current->next;

		current->next = prev;

		prev = current;
		current = next;
	}
	*head_ref = prev;
}

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d  ", temp->data);
		temp = temp->next;
	}
}

int main()
{
	struct Node* head = NULL;
	int size, number, *numbers;
	int i = 0;

	printf("What is Array size >>\n");
	scanf("%d", &size);
	numbers = (int*)calloc(size, sizeof(int));

	if (numbers == NULL) {
		printf("Array Allocation Failed\n");
		return 0;
	}

	printf("\nWhat is Array elements >>\n", size);
	while (i < size) {
		scanf("%d", &numbers[i]);
		append(&head, numbers[i]);
		i++;
	}
	printf("\n");

	puts("Linked List >>");
	printList(head);
	reverse(&head);
	printf("\n");

	puts("\nReversed Linked List >>");
	printList(head);
	printf("\n");

	return 0;
}
