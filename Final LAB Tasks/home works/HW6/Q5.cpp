#include <iostream>

struct Node {
	int data;
	struct Node* next;
};
void printLL(struct Node* node)
{
	struct Node* start = node;

	while (node->next != start) {
		 node->data;
		node = node->next;
	}
	
	node->data;
}

void insert(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc
						(sizeof(struct Node));

	newNode->data = data;

	newNode->next = (*head);

	(*head) = newNode;
}


struct Node* circularLL(struct Node* head)
{
	struct Node* start = head;

	while (head->next != NULL)
		head = head->next;
		
	head->next = start;
	return start;
}

int main()
{
	struct Node* head = NULL;

	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	insert(&head, 5);

	circularLL(head);

	printf("Display list: \n");
	printLL(head);

	return 0;
}
