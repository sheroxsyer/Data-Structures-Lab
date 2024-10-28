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

class DLL
{
Node* head1;
Node* head2;
int length;
public:
DLL()
{
head1=NULL;
head2=NULL;
length=0;
}

void printDLL1(){
Node* curr1=head1;
cout<<"DLL is:"<<endl;
while(curr1!=NULL)
{
cout<<curr1->data<<" ";
curr1=curr1->next;
}
cout<<endl;
}
void printDLL2(){
Node* curr2=head2;
cout<<"DLL is:"<<endl;
while(curr2!=NULL)
{
cout<<curr2->data<<" ";
curr2=curr2->next;
}
cout<<endl;
}

void insertAtHead1(int val)
{
Node* n=new Node(val);

head1=n;
length++;
}
void insertAtHead2(int val)
{
Node* n=new Node(val);

head2=n;
length++;
}
void insertAT1(int val, int pos)
{
if(pos>length && pos<0)
{
cout<<"Invalid "<<endl;
return;
}
Node* n=new Node(val);

if(pos==1)
{
n->next=head1;
head1->prev=n;
head1=n;
length++;
}
else if(pos==length+1)
{
Node*n=new Node(val);
Node*curr1=head1;
for(int i=1; i<pos-1; i++)
{
curr1=curr1->next;
}
curr1->next=n;
n->prev=curr1;
length++;
}
else
{
Node* n= new Node(val);
Node* curr1=head1;
for(int i=1; i<pos; i++)
{
curr1=curr1->next;
}
curr1->prev->next=n;
n->prev=curr1->prev;
curr1->prev=n;
n->next=curr1;
length++;

}

}

void insertAT2(int val, int pos)
{
if(pos>length && pos<0)
{
cout<<"Invalid "<<endl;
return;
}
Node* n=new Node(val);

if(pos==1)
{
n->next=head2;
head2->prev=n;
head2=n;
length++;
}
else if(pos==length+1)
{
Node*n=new Node(val);
Node*curr2=head2;
for(int i=1; i<pos-1; i++)
{
curr2=curr2->next;
}
curr2->next=n;
n->prev=curr2;
length++;
}
else
{
Node* n= new Node(val);
Node* curr2=head2;
for(int i=1; i<pos; i++)
{
curr2=curr2->next;
}
curr2->prev->next=n;
n->prev=curr2->prev;
curr2->prev=n;
n->next=curr2;
length++;

}

}
void deleteAt1(int pos)
{
if(pos<0&& pos>length)
{
cout<<"Invalid"<<endl;
return;
}
Node*curr1=head1;
for(int i=1; i<pos; i++)
{
curr1=curr1->next;
}
curr1->prev->next=curr1->next;
curr1->next->prev=curr1->prev;
length--;
}
void deleteAt2(int pos)
{
if(pos<0&& pos>length)
{
cout<<"Invalid"<<endl;
return;
}
Node*curr2=head2;
for(int i=1; i<pos; i++)
{
curr2=curr2->next;
}
curr2->prev->next=curr2->next;
curr2->next->prev=curr2->prev;
length--;
}

void concatenate( Node*List1, Node*List2)
{
    printDLL1();
    Node* curr1=head1;
    while(curr1!=NULL) {
        cout<<curr1->data<<"\t";
        curr1= curr1->next;
        curr1= curr1->prev;
    }
    curr1->next=List2;
    curr1->prev=List2;

}

};




int main()
{
DLL l1;
l1.insertAtHead1(1);

l1.insertAT1(2,1);
l1.insertAT1(3,1);
l1.insertAT1(4,1);
l1.insertAT1(5,1);
//l1.insertAT1(6,1);
//l1.insertAT1(7,1);

l1.printDLL1();
cout<<endl;
cout<<endl;

DLL l2;
l2.insertAtHead2(1);

l2.insertAT2(2,1);
l2.insertAT2(3,1);
l2.insertAT2(4,1);
l2.insertAT2(5,1);
//l2.insertAT2(6,1);
//l2.insertAT2(7,1);

l2.printDLL2();
cout<<endl;
cout<<endl;
concatenate(List1,List2);
return 0;
}