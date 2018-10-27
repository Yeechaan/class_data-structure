
#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h>

struct Node
{
	int key;
	struct Node* next;
};

void push(struct Node** head_ref, int new_key)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->key = new_key;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void append(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

	struct Node *last = *head_ref;
	new_node->key = new_data;
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

bool search_loop(struct Node* head, int x)
{
	struct Node* current = head;
	while (current != NULL)
	{
		if (current->key == x)
			return true;
		current = current->next;
	}
	return false;
}

bool search_recursion(struct Node* head, int x)
{
	if (head == NULL)
		return false;

	if (head->key == x)
		return true;

	return search_recursion(head->next, x);
}

void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d  ", temp->key);
		temp = temp->next;
	}
}

void printList_recursion(struct Node *head)
{
	struct Node *temp = head;
	if (temp != NULL)
	{
		printf("%d  ", temp->key);
		printList_recursion(temp->next);
	}
}

int main()
{
	struct Node* head = NULL;
	int size, number, *numbers;
	int i = 0;

	printf("\nWhat is Array size >>\n");
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
	printList(head);
	printf("\n");

	printf("Which number do you want to find : ");
	scanf("%d", &number);
	search_loop(head, number) ? printf("Yes") : printf("No");
	printf("\nSearched by loop  \n\n");

	printf("Which number do you want to find : ");
	scanf("%d", &number);
	search_recursion(head, number) ? printf("Yes") : printf("No");
	printf("\nSearched by recursion  \n");

	if (numbers != NULL) {
		free(numbers);
	}

	return 0;
}
