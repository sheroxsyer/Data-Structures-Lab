#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};
void printList(struct Node* head)
{
	if (head == NULL)
		cout << "list empty";

	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}
void insert(struct Node** head, int data)
{
	struct Node* new_node =
		(struct Node*)malloc(sizeof(struct Node));

	new_node->data = data;

	new_node->prev = NULL;

	new_node->next = (*head);

	if ((*head) != NULL)
		(*head)->prev = new_node;

	(*head) = new_node;
}

void remove(struct Node** head, struct Node* curr)
{
    if (*head == NULL || curr == NULL)
		return;

	if (*head == curr)
		*head = curr->next;

	if (curr->next != NULL)
		curr->next->prev = curr->prev;

	if (curr->prev != NULL)
		curr->prev->next = curr->next;

	free(curr);
}

void removeDuplicate(struct Node** head)
{
	if ((*head) == NULL)
		return;

	struct Node* curr = *head;
	struct Node* next;

	while (curr->next != NULL) {

		if (curr->data == curr->next->data)

			remove(head, curr->next);

		else
			curr = curr->next;
	}
}



int main()
{
	struct Node* head = NULL;

	insert(&head, 1);
	insert(&head, 8);
	insert(&head, 3);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 6);
	insert(&head, 7);
	insert(&head, 8);
	insert(&head, 9);
	insert(&head, 9);

	cout << "DLL is :";
	printList(head);

	removeDuplicate(&head);

	cout << "after"
			" removing duplicates:";
	printList(head);

	return 0;
}
