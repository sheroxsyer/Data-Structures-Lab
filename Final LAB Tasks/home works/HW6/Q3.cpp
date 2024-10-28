#include <iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
	Node *prev;
};

void printList(Node *node)
{
	while(node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}


void insert(Node** head, int data)
{
	Node* new_node = new Node();

	new_node->data = data;
	
	new_node->prev = NULL;

	new_node->next = (*head);	

	if((*head) != NULL)
	(*head)->prev = new_node ;

	(*head) = new_node;
}

void reverse(Node **head)
{
	Node *temp = NULL;
	Node *curr = *head;
	
	while (curr != NULL)
	{
		temp = curr->prev;
		curr->prev = curr->next;
		curr->next = temp;			
		curr = curr->prev;
	}
	
	if(temp != NULL )
		*head = temp->prev;
}

int main()
{
	Node* head = NULL;
	
	insert(&head, 1);
	insert(&head, 2);
	insert(&head, 3);
	insert(&head, 4);
	
	cout << "DLL is:" << endl;
	printList(head);
	
	reverse(&head);
	
	cout << "\nReversed DLL is:" << endl;
	printList(head);		
	
	return 0;
}