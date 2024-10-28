#include <iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *next;
};

void splitList(Node *head, Node **head1,
						Node **head2)
{
	Node *slow_ptr = head;
	Node *fast_ptr = head;
	
	if(head == NULL)
		return;
	
	while(fast_ptr->next != head &&
		fast_ptr->next->next != head)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}
	
	if(fast_ptr->next->next == head)
		fast_ptr = fast_ptr->next;
		
	*head1 = head;
		
	if(head->next != head)
		*head2 = slow_ptr->next;
		
	fast_ptr->next = slow_ptr->next;
		
	slow_ptr->next = head;
}

void insert(Node **head, int data)
{
	Node *ptr1 = new Node();
	Node *temp = *head;
	ptr1->data = data;
	ptr1->next = *head;
		
	if(*head != NULL)
	{
		while(temp->next != *head)
		temp = temp->next;	
		temp->next = ptr1;
	}
	else
		ptr1->next = ptr1;
	*head = ptr1;
}

void printList(Node *head)
{
	Node *temp = head;
	if(head != NULL)
	{
		cout << endl;
		do {
		cout << temp->data << " ";
		temp = temp->next;
		} while(temp != head);
	}
}

int main()
{
	int list_size, i;
		
	Node *head = NULL;
	Node *head1 = NULL;
	Node *head2 = NULL;
	
	
	insert(&head, 12);
	insert(&head, 56);
	insert(&head, 2);
	insert(&head, 11);
	
	cout << "Original Circular Linked List";
	printList(head);	
	
	
	splitList(head, &head1, &head2);
	
	cout << "\nFirst Circular Linked List";
	printList(head1);
	
	cout << "\nSecond Circular Linked List";
	printList(head2);
	return 0;
}