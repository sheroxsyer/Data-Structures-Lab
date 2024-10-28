#include<iostream>
using namespace std;
// Making node for doubly linked list 
class node 

{
    public:
    int data;
    node *next;
    node *prev;

    //parameterized constructor

    node(int val) 
    {
        data=val;
        prev=NULL;
        next=NULL;
    }
};
// class for double linked list
class DoubleList 
{
    public:
    node *head;
    int length;

    DoubleList()
    {
        head=NULL;
        length=0;
    }

    //function declaration
    void insert(int val, int pos);
    void print();
    void DLL_To_circular();
};

int main()
{
// creating object for DLL
    DoubleList d;  

    d.insert(1,1);
    d.insert(2,2);
    d.insert(3,3);
    d.insert(4,4);
    d.insert(5,5);

    cout<<"Before conversion:."<<endl;
    d.print();

    cout<<"After Conversion."<<endl;
    d.DLL_To_circular(); 


}



//For display DLL
void DoubleList::print()
{
    node *curr=head;

    while(curr->next!=NULL)
    {
        //for display in a better manner to understand the concept easily.
        if(curr==head)
        {
            cout<<"NULL<-";
        }
        cout<<curr->data<<"-> <-";

        curr=curr->next;
    }

    if(curr->next==NULL)
    {
        cout<<curr->data<<"->NULL";
    }                        

    cout<<endl;
}

//For converting  the DLL to circularLL. 
void DoubleList::DLL_To_circular()
{
    node *curr=head;
// take the pointer curr to last node
    while(curr->next!=NULL) 
    
    {
        curr=curr->next;
    }

    curr->next=head; 
    //place head in the prev of last node
    head->prev=curr; 
    
    node *cur=head;

    while(cur->next!=head) 
    {
        if(cur==head)
        {
            cout<<"<-";
        }
        cout<<cur->data<<"-> <-";
        cur=cur->next;
    }

    if(cur->next==head)
    {
        cout<<cur->data<<"->";
    }
}

// For insert node in DLL
void DoubleList::insert(int val, int pos)
{
    if(pos>length+1 || pos< 1)
    {
        cout<<"Invalid position."<<endl;
        return;
    }

    node *n=new node(val);
    

    if(pos==1)
    {
        n->next=head;
        if(head!=NULL)
           head->prev=n;
        head=n;

    }

    else
    {
        node *curr=head;

        for(int i=1; i<(pos-1); i++)
        {
            curr=curr->next;
        }

        n->next=curr->next;
        n->prev=curr;
        if(curr->next!=NULL)
            curr->next->prev=n;
        curr->next=n;
    }

    length++;
}