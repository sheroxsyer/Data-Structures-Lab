#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* prev;
	node* next;

	node(int data)
	{
		this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}
};



void insert(node*& head, node*& tail,
		int val)
{

	//Check for empty
	if (tail == NULL) {

		node* curr = new node(val);
		tail = curr;
		head = curr;
	}

	
	else {
		node* curr = new node(val);
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
	}
}


pair<node*, node*> search(node*& head,
						int a, int b)
{
	node* N1 = NULL;
	node* N2 = NULL;
	node* curr = head;

	
	while (curr != NULL) {
		if (curr->data == a)
			N1 = curr;
		else if (curr->data == b)
			N2 = curr;
		curr = curr->next;
	}
	return make_pair(N1, N2);
}


void swapLink(node*& head, node*& tail,
		int x, int y)
{

	
	if (head == NULL || head->next == NULL
		|| x == y)
		return;

	//searching
	pair<node*, node*> p = search(head, x, y);

	node* Node1 = p.first;
	node* Node2 = p.second;

	if (Node1 == head)
		head = Node2;
	else if (Node2 == head)
		head = Node1;
	if (Node1 == tail)
		tail = Node2;
	else if (Node2 == tail)
		tail = Node1;

	//swapping
	node* curr;
	curr = Node1->next;
	Node1->next = Node2->next;
	Node2->next = curr;

	if (Node1->next != NULL)
		Node1->next->prev = Node1;
	if (Node2->next != NULL)
		Node2->next->prev = Node2;

	curr = Node1->prev;
	Node1->prev = Node2->prev;
	Node2->prev = curr;

	if (Node1->prev != NULL)
		Node1->prev->next = Node1;
	if (Node2->prev != NULL)
		Node2->prev->next = Node2;
}
void printDLL(node* head)
{
	node* curr = head;

	while (curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}
	cout << endl;
}


int main()
{

	node* head = NULL;
	node* tail = NULL;

	insert(head, tail, 1);
	insert(head, tail, 8);
	insert(head, tail, 7);
	insert(head, tail, 9);
	insert(head, tail, 4);

	int X = 1, Y = 4;

	cout << "Before Swapping: ";
	printDLL(head);

	swapLink(head, tail, X, Y);
	cout << "After Swapping: ";
	printDLL(head);

	return 0;
}
