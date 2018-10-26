#if 0
#include <stdio.h> 
#include <stdlib.h> 

struct Node
{
	int data;
	struct Node *next;
};

void push(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

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

void deleteNode(struct Node **head_ref, int position)
{
	if (*head_ref == NULL)
		return;

	struct Node* temp = *head_ref;

	if (position == 0)
	{
		*head_ref = temp->next;
		free(temp);
		return;
	}

	for (int i = 0; temp != NULL && i<position - 1; i++)
		temp = temp->next;

	if (temp == NULL || temp->next == NULL)
		return;

	struct Node *next = temp->next->next;

	free(temp->next);

	temp->next = next;
}

void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
}

int main()
{
	struct Node* head = NULL;
	int size, *numbers;
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

	//get rid of element 3 (index = 2)
	deleteNode(&head, 2);
	printf("\n");
	puts("\nAfter delete 3 in Linked List >>");
	printList(head);
	printf("\n");

	if (numbers != NULL) {
		free(numbers);
	}

	return 0;
}
#endif