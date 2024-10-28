#include<iostream>
using namespace std;
class Node {
public:
Node *next;
Node * prev;
int data;

Node(int val) {
data= val;
next= prev=NULL;
}
};

class DoubleLL
{
Node* head;
int length;
public:
DoubleLL()
{
head=NULL;
length=0;
}
void printDoubleLL(){
Node* curr=head;
cout<<"Printing in ascending order"<<endl;
while(curr!=NULL)
{
cout<<curr->data<<" ";
curr=curr->next;
}
cout<<endl;
cout<<"Printing in descending order"<<endl;
curr=head;
for(int i=1; i<length; i++)
{
curr=curr->next;
}
while(curr!=NULL)
{
cout<<curr->data<<" ";
curr=curr->prev;
}
}

void insertAtHead(int val)
{
Node* n=new Node(val);

head=n;
length++;
}

void insertAT(int val, int pos)
{
if(pos>length && pos<0)
{
cout<<"Invalid Position"<<endl;
return;
}
Node* n=new Node(val);

if(pos==1)
{
n->next=head;
head->prev=n;
head=n;
length++;
}
else if(pos==length+1)
{
Node*n=new Node(val);
Node*curr=head;
for(int i=1; i<pos-1; i++)
{
curr=curr->next;
}
curr->next=n;
n->prev=curr;
length++;
}
else
{
Node* n= new Node(val);
Node* curr=head;
for(int i=1; i<pos; i++)
{
curr=curr->next;
}
curr->prev->next=n;
n->prev=curr->prev;
curr->prev=n;
n->next=curr;
length++;

}

}
void deleteAt(int pos)
{
if(pos<0 && pos>length)
{
cout<<"Invalid position"<<endl;
return;
}
Node*curr=head;
for(int i=1; i<pos; i++)
{
curr=curr->next;
}
curr->prev->next=curr->next;
curr->next->prev=curr->prev;
length--;
}

};




int main()
{
DoubleLL l1;
l1.insertAtHead(1);
// l1.insertAT(1,1);
l1.insertAT(2,1);
l1.insertAT(3,1);
l1.insertAT(4,1);
l1.insertAT(5,1);
l1.insertAT(6,1);
l1.insertAT(7,1);

l1.printDoubleLL();
cout<<endl;
cout<<endl;
cout<<"After deleting"<<endl;
l1.deleteAt(3);
l1.printDoubleLL();
return 0;
}