
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

	//push()
	while (i < size - 3) {
		scanf("%d", &numbers[i]);
		push(&head, numbers[i]);
		i++;
	}
	//append()
	while (i < size) {
		scanf("%d", &numbers[i]);
		append(&head, numbers[i]);
		i++;
	}

	puts("\nLinked List >>");
	printList(head);
	printf("\n");

	if (numbers != NULL) {
		free(numbers);
	}

	return 0;
}
