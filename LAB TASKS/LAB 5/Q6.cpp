#include<iostream>

using namespace std;
class node {
	public:
		int data;
		node *next;
};

node *head= new node();
node *curr= new node();
int length=0;

void GoToHead() { 
	curr= head;
}

void insertNodeAtEndHead(int val) { 
	GoToHead();
	node *p= new node();
	while(curr->next!=NULL)
		curr= curr->next;
	p->data= val;
	p->next= NULL;
	curr->next= p;
	length++;
}
void printLinklist() {
	GoToHead();
	while(curr!=NULL) {
		cout<<curr->data<<"\t";
		curr= curr->next;
	}
}

void removeDuplicate(node *h)
{
	GoToHead();
	node* prev;
	while(curr->next!=NULL)
	{
		prev=curr;
		curr=curr->next;
		if(prev->data == curr->data)
		{
			prev->next=curr->next;
			node* temp=curr;
			curr=curr->next;
			delete temp;
			length--;
		}
	}
}
int main()
{
	
	head->data=1;
	head->next=NULL;
	
	insertNodeAtEndHead(4);
	insertNodeAtEndHead(4);
	insertNodeAtEndHead(6);
	insertNodeAtEndHead(7);
	insertNodeAtEndHead(9);
	insertNodeAtEndHead(9);
	insertNodeAtEndHead(15);
	
	printLinklist();
	cout<<endl;
	removeDuplicate(head);
	
	printLinklist();
	return 0;
}