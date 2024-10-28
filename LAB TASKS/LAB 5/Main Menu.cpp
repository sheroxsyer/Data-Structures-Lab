
//Single Linklist implementation
#include<iostream>
using namespace std;
class node {
	public:
		int data;
		node *next;
        
};

node *head1= new node();
node *head2= new node();
node *curr1= new node();
node *curr2= new node();
node *List1= new node();
node *List2= new node();
int length=0;
void GoToHead1() { // set curr pointer to head node;
	curr1= head1;
    
}
void GoToHead2(){
    curr2 = head2;
}

void insertNodeAtEnd1(int val) { // This function will insert new node at the end.
	GoToHead1();
	node *t= new node();
	while(curr1->next!=NULL)
		curr1= curr1->next;
	t->data= val;
	t->next= NULL;
	curr1->next= t;
	length++;
}

void insertNodeAtEnd2(int val) { // This function will insert new node at the end.
	GoToHead2();
	node *t= new node();
	while(curr2->next!=NULL)
		curr2= curr2->next;
	t->data= val;
	t->next= NULL;
	curr2->next= t;
	length++;
}
void AddNodeBeforeHead1( int val) { // This function will insert new node as a head.
	GoToHead1();
	node *t= new node();
	t->data= val;
	t->next= curr1;
	head1= t;
	length++;
}
void AddNodeBeforeHead2( int val) { // This function will insert new node as a head.
	GoToHead2();
	node *t= new node();
	t->data= val;
	t->next= curr2;
    head2= t;
	length++;
}
void InsertAfterSpecificKey1(int val, int key ) {
	node *t= new node();
	GoToHead1();
	while (curr1!=NULL) {
		if (curr1->data==key) {
			t->data= val;
			t->next= NULL;
			t->next= curr1->next;
			curr1->next= t;
			length++;
			break;
		}
		curr1= curr1->next;
	}
}
void InsertAfterSpecificKey2(int val, int key ) {
	node *t= new node();
	GoToHead2();
	while (curr2!=NULL) {
		if (curr2->data==key) {
			t->data= val;
			t->next= NULL;
			t->next= curr2->next;
			curr2->next= t;
			length++;
			break;
		}
		curr2= curr2->next;
	}
}
void InsertBeforeSpecificKey1(int val, int key ) {
	node *ptr=NULL;
	GoToHead1();
	while (curr1!=NULL) {
		if (curr1->data==key) {
			node *t= new node();
			t->data= val;
			t->next= NULL;
			t->next= curr1;
			ptr->next= t;
			length++;
			break;
		}
		ptr= curr1;
		curr1= curr1->next;
	}
}
void InsertBeforeSpecificKey2(int val, int key ) {
	node *ptr=NULL;
	GoToHead2();
	while (curr2!=NULL) {
		if (curr2->data==key) {
			node *t= new node();
			t->data= val;
			t->next= NULL;
			t->next= curr2;
			ptr->next= t;
			length++;
			break;
		}
		ptr= curr2;
		curr2= curr2->next;
	}
}
void printLinklist1() {
	GoToHead1();
	while(curr1!=NULL) {
		cout<<curr1->data<<"\t";
		curr1= curr1->next;
	}
}
void printLinklist2() {
	GoToHead2();
	while(curr2!=NULL) {
		cout<<curr2->data<<"\t";
		curr2= curr2->next;
	}
}

void DeleteNodeUsingKey1(int key) {
	GoToHead1();
	node *prenode= new node();
	if(curr1->data== key) {
		head1= curr1->next;
		delete curr1;
		length--;
		return;
	} else
		while(curr1!=NULL) {
			if(curr1->data==key) {
				prenode->next= curr1->next;
				delete curr1;
				length--;
				break;
			}
			prenode= curr1;
			curr1=curr1->next;
		}

}
void DeleteNodeUsingKey2(int key) {
	GoToHead2();
	node *prenode= new node();
	if(curr2->data== key) {
        head2= curr2->next;
		delete curr2;
		length--;
		return;
	} else
		while(curr2!=NULL) {
			if(curr2->data==key) {
				prenode->next= curr2->next;
				delete curr2;
				length--;
				break;
			}
			prenode= curr2;
			curr2=curr2->next;
		}

}
void DeleteNodeUsingPos1(int pos) {
	GoToHead1();
	node *prenode= new node();
	if(pos>length) {
		cout<<"This Position dosenot exist"<<endl;
		return;
	} else if (pos==1 ) { // if we want to delet head node
		prenode= curr1;
		head1= curr1->next;
		delete prenode;
		length--;
	} else {
		for (int x=1; x<pos; x++) {
			prenode= curr1;
			curr1= curr1->next;
		}
		prenode->next= curr1->next;
		delete curr1;
		length--;

	}
}
void DeleteNodeUsingPos2(int pos) {
	GoToHead2();
	node *prenode= new node();
	if(pos>length) {
		cout<<"This Position dosenot exist"<<endl;
		return;
	} else if (pos==1 ) { // if we want to delet head node
		prenode= curr2;
        head2= curr2->next;
		delete prenode;
		length--;
	} else {
		for (int x=1; x<pos; x++) {
			prenode= curr2;
			curr2= curr2->next;
		}
		prenode->next= curr2->next;
		delete curr2;
		length--;

	}
}

void InsertNodeUsingKey1(int val, int key, bool isBefore) {
	if (isBefore)
		InsertBeforeSpecificKey1( val, key);
	else
		InsertAfterSpecificKey1( val, key);

}
void InsertNodeUsingKey2(int val, int key, bool isBefore) {
	if (isBefore)
		InsertBeforeSpecificKey2( val, key);
	else
		InsertAfterSpecificKey2( val, key);

}
void InsertNodeUsingPos1(int val, int pos, bool isBefore) {
	GoToHead1();
	if(pos>length) {
		cout<<"This Position dosenot exist"<<endl;
		return;
	} else if (pos==1 && isBefore ) { // if we want to insert before head
		AddNodeBeforeHead1(val);
	} else {
		node *prenode= new node();
		for (int x=1; x<pos; x++) {
			prenode= curr1;
			curr1= curr1->next;
		}
		if (isBefore) {
			node *t= new node();
			t->data= val;
			t->next= NULL;
			t->next= curr1;
			prenode->next= t;

		} else {
			node *t= new node();
			t->data= val;
			t->next= NULL;
			t->next= curr1->next;
			curr1->next= t;
		}
	}

}
void InsertNodeUsingPos2(int val, int pos, bool isBefore) {
	GoToHead2();
	if(pos>length) {
		cout<<"This Position dosenot exist"<<endl;
		return;
	} else if (pos==1 && isBefore ) { // if we want to insert before head
		AddNodeBeforeHead2(val);
	} else {
		node *prenode= new node();
		for (int x=1; x<pos; x++) {
			prenode= curr2;
			curr2= curr2->next;
		}
		if (isBefore) {
			node *t= new node();
			t->data= val;
			t->next= NULL;
			t->next= curr2;
			prenode->next= t;

		} else {
			node *t= new node();
			t->data= val;
			t->next= NULL;
			t->next= curr2->next;
			curr2->next= t;
		}
	}

}
void concatenate( node*List1, node*List2)
{
    printLinklist1();
    while(curr1!=NULL) {
		cout<<curr1->data<<"\t";
		curr1= curr1->next;
	}
    curr1->next=List2;

}
int main () {
	head1->data= 1;
    head2->data=1;
	head1->next=NULL;
    head2->next=NULL;

	insertNodeAtEnd1(2);
	insertNodeAtEnd1(3);
	insertNodeAtEnd1(4);
	printLinklist1();
	cout<<endl;     

	// InsertAfterSpecificKey1(99, 2);
	// printLinklist1();
	// cout<<endl;

	// DeleteNodeUsingKey1(99);
	// printLinklist1();
	// cout<<endl;

	// InsertBeforeSpecificKey1(99, 2);
	// printLinklist1();
	// cout<<endl;

	// InsertNodeUsingPos1(88,1,true);
	// printLinklist1();
	// cout<<endl;

	// DeleteNodeUsingPos1(1);
	// DeleteNodeUsingPos1(2);

	// printLinklist1();
	// cout<<endl;
    insertNodeAtEnd2(2);
	insertNodeAtEnd2(3);
	insertNodeAtEnd2(4);
	printLinklist2();
	cout<<endl;

	// InsertAfterSpecificKey2(99, 2);
	// printLinklist2();
	// cout<<endl;

	// DeleteNodeUsingKey2(99);
	// printLinklist2();
	// cout<<endl;

	// InsertBeforeSpecificKey2(99, 2);
	// printLinklist2();
	// cout<<endl;

	// InsertNodeUsingPos2(88,1,true);
	// printLinklist2();
	// cout<<endl;

	// DeleteNodeUsingPos2(1);
	// DeleteNodeUsingPos2(2);

	// printLinklist2();
	// cout<<endl;

    concatenate(List1,List2);
	return 0;
}