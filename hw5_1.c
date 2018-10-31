#include<stdio.h> 
#include<stdlib.h> 

struct Node
{
	int data;
	struct Node *next;
};

void sortedInsert(struct Node** head_ref, struct Node* new_node)
{
	struct Node* current = *head_ref;

	if (current == NULL)
	{
		new_node->next = new_node;
		*head_ref = new_node;
	}

	else if (current->data >= new_node->data)
	{
		while (current->next != *head_ref)
			current = current->next;
		current->next = new_node;
		new_node->next = *head_ref;
		*head_ref = new_node;
	}

	else
	{
		while (current->next != *head_ref &&
			current->next->data < new_node->data)
			current = current->next;

		new_node->next = current->next;
		current->next = new_node;
	}
}

void printList(struct Node *start)
{
	struct Node *temp;

	if (start != NULL)
	{
		temp = start;
		printf("\n");
		do {
			printf("%d ", temp->data);
			temp = temp->next;
		} while (temp != start);
	}
}

int main()
{
	int data;

	struct Node *start = NULL;
	struct Node *temp;

	printf("\nWrite down unordered ramdom numbers >>\n");
	scanf("%d", &data);

	while (data != 0)
	{
		temp = (struct Node *)malloc(sizeof(struct Node));
		temp->data = data;
		sortedInsert(&start, temp);
		scanf("%d", &data);
	}

	printf("\nSorted Linked List >>");
	printList(start);
	printf("\n");

	return 0;
}
