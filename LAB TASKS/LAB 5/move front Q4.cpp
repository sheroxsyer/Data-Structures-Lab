
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
class node {
	public:
		int data;
		node *next;
};

node *head= new node();
node *curr= new node();
int length=0;
void GoToHead() { // set curr pointer to head node;
	curr= head;
}

void insertNodeAtEnd(int val) { // This function will insert new node at the end.
	GoToHead();
	node *t= new node();
	while(curr->next!=NULL)
		curr= curr->next;
	t->data= val;
	t->next= NULL;
	curr->next= t;
	length++;
}
void AddNodeBeforeHead( int val) { // This function will insert new node as a head.
	GoToHead();
	node *t= new node();
	t->data= val;
	t->next= curr;
	head= t;
	length++;
}
void InsertAfterSpecificKey(int val, int key ) {
	node *t= new node();
	GoToHead();
	while (curr!=NULL) {
		if (curr->data==key) {
			t->data= val;
			t->next= NULL;
			t->next= curr->next;
			curr->next= t;
			length++;
			break;
		}
		curr= curr->next;
	}
}
void InsertBeforeSpecificKey(int val, int key ) {
	node *ptr=NULL;
	GoToHead();
	while (curr!=NULL) {
		if (curr->data==key) {
			node *t= new node();
			t->data= val;
			t->next= NULL;
			t->next= curr;
			ptr->next= t;
			length++;
			break;
		}
		ptr= curr;
		curr= curr->next;
	}
}
// void printLinklist(node*node) {
// 	GoToHead();
// 	while(curr!=NULL) {
// 		cout<<curr->data<<"\t";
// 		curr= curr->next;
// 	}
// }

void DeleteNodeUsingKey(int key) {
	GoToHead();
	node *prenode= new node();
	if(curr->data== key) {
		head= curr->next;
		delete curr;
		length--;
		return;
	} else
		while(curr!=NULL) {
			if(curr->data==key) {
				prenode->next= curr->next;
				delete curr;
				length--;
				break;
			}
			prenode= curr;
			curr=curr->next;
		}

}
void DeleteNodeUsingPos(int pos) {
	GoToHead();
	node *prenode= new node();
	if(pos>length) {
		cout<<"This Position dosenot exist"<<endl;
		return;
	} else if (pos==1 ) { // if we want to delet head node
		prenode= curr;
		head= curr->next;
		delete prenode;
		length--;
	} else {
		for (int x=1; x<pos; x++) {
			prenode= curr;
			curr= curr->next;
		}
		prenode->next= curr->next;
		delete curr;
		length--;

	}
}

void InsertNodeUsingKey(int val, int key, bool isBefore) {
	if (isBefore)
		InsertBeforeSpecificKey( val, key);
	else
		InsertAfterSpecificKey( val, key);

}
void InsertNodeUsingPos(int val, int pos, bool isBefore) {
	GoToHead();
	if(pos>length) {
		cout<<"This Position dosenot exist"<<endl;
		return;
	} else if (pos==1 && isBefore ) { // if we want to insert before head
		AddNodeBeforeHead(val);
	} else {
		node *prenode= new node();
		for (int x=1; x<pos; x++) {
			prenode= curr;
			curr= curr->next;
		}
		if (isBefore) {
			node *t= new node();
			t->data= val;
			t->next= NULL;
			t->next= curr;
			prenode->next= t;

		} else {
			node *t= new node();
			t->data= val;
			t->next= NULL;
			t->next= curr->next;
			curr->next= t;
		}
	}

}

void moveToFront(node **head)
{
	/* If linked list is empty, or
	it contains only one node,
	then nothing needs to be done,
	simply return */
	if (*head == NULL || (*head)->next == NULL)
		return;

	/* Initialize second last
	and last pointers */
	node *secLast = NULL;
	node *last = *head;

	/*After this loop secLast contains
	address of second last node and
	last contains address of last node in Linked List */
	while (last->next != NULL)
	{
		secLast = last;
		last = last->next;
	}

	/* Set the next of second last as NULL */
	secLast->next = NULL;

	/* Set next of last as head node */
	last->next = *head;

	/* Change the head pointer
	to point to last node now */
	*head = last;
}
void insert(node** head, int new_data)
{
	/* allocate node */
	node* new_node = new node();

	/* put in the data */
	new_node->data = new_data;

	/* link the old list off the new node */
	new_node->next = (*head);

	/* move the head to point to the new node */
	(*head) = new_node;
}
void printLinklist(node *node)
{
	while(node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}


int main () {
	// head->data= 1;
	// head->next=NULL;
    node *start = NULL;

	// insertNodeAtEnd(2);
	// insertNodeAtEnd(3);
	// insertNodeAtEnd(4);
	// //printLinklist(start);
	// cout<<endl;



	// InsertAfterSpecificKey(99, 2);
	// printLinklist();
	// cout<<endl;

	// DeleteNodeUsingKey(99);
	// printLinklist();
	// cout<<endl;

	// InsertBeforeSpecificKey(99, 2);
	// printLinklist();
	// cout<<endl;

	// InsertNodeUsingPos(88,1,true);
	// printLinklist();
	// cout<<endl;

	// DeleteNodeUsingPos(1);
	// DeleteNodeUsingPos(2);

	// printLinklist();
	// cout<<endl;

    insert(&start, 5);
	insert(&start, 4);
	insert(&start, 3);
	insert(&start, 2);
	insert(&start, 1);

    cout<<"Linked list before moving last to front\n";
	printLinklist(start);

	//moveToFront(&start);

	cout<<"\nLinked list after removing last to front\n";
	
    moveToFront(&start);
    printLinklist(start);

	return 0;
}