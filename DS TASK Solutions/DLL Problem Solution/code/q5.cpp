//Write a function that accepts a linear linked list and converts it to a circular 
//linked list both for singly and doubly linked list.

#include<iostream>
using namespace std;

class LinkListnode // it will make node for linked list
{
    public:
    int data;
    LinkListnode *next;

    LinkListnode(int v) //parameterized constructor
    {
        data=v;
        next=NULL;
    }
};

class DoublyListnode // it will make node for doubly linked list 
{
    public:
    int data;
    DoublyListnode *next;
    DoublyListnode *prev;

    DoublyListnode(int v) //parameterized constructor
    {
        data=v;
        prev=NULL;
        next=NULL;
    }
};

class LinkList //class for linked list
{
    public:
    LinkListnode *head;
    int length;

    LinkList() // constructor
    {
        head=NULL;
        length=0;
    }

    // function declaration
    void insertion(int v, int p);
    void print();
    void circular();
};

class DoublyList // class for doubly linked list
{
    public:
    DoublyListnode *head;
    int length;

    DoublyList()
    {
        head=NULL;
        length=0;
    }

    //function declaration
    void insertion(int val, int pos);
    void print();
    void circular();
};

int main()
{
    LinkList obj; // creating object for the linked list class

    obj.insertion(1,1); 
    obj.insertion(2,1);
    obj.insertion(3,1);
    obj.insertion(4,1);

    cout<<"Before making Link List circular."<<endl;
    obj.print();

    cout<<"After making it circular."<<endl;
    obj.circular(); // calling the circular function for linked list

    cout<<endl<<endl;;

    DoublyList obj1;  // creating object for doubly linked list

    obj1.insertion(1,1);
    obj1.insertion(2,1);
    obj1.insertion(3,1);
    obj1.insertion(4,1);

    cout<<"Before making Doubly List circular."<<endl;
    obj1.print();

    cout<<"After making it circular."<<endl;
    obj1.circular(); // calling the circular function for doubly linked list


}

void LinkList::insertion(int v, int p)
{
    if(p<1 || p>length+1) // checking if the position is greater then length , return from the function
    {
        cout<<"Invalid position."<<endl;
        return;
    }

    LinkListnode *n=new LinkListnode(v); // creating the node
    
    if(p==1) // condition for inserting in the start
    {
        n->next=head; //put the current head in the next of the new node 
        head=n; // make the new node head
        length ++; // inc the length as new node is added to the list
    }

    else
    {
        LinkListnode *n=new LinkListnode(v);
        LinkListnode *curr=head;

        for(int i=1; i<(p-1); i++) // it will take curr pointer to the node after which we want to insert the new node
        {
            curr=curr->next; 
        }

        n->next=curr->next;  //the node which was after the curr node is now next to the new node
        curr->next=n; // it will palce the new node after the curr
        length ++;
        
    }
}

// print the linked list
void LinkList::print()
{
    LinkListnode *curr=head;

    while(curr!=NULL)
    {
        cout<<curr->data<<"->";
        if(curr->next==NULL)
        {
            cout<<"NULL";
        }
        curr=curr->next;
    }

    cout<<endl;
}

// this function will convert the linked list to circular linked list
void LinkList::circular()
{
    LinkListnode *curr=head;

    while(curr->next!=NULL) // this loop will take the current pointer to last node
    {
        curr=curr->next;
    }

    curr->next=head; // in the next of last node we will place head

    //this will display the new circular linkedlist
    LinkListnode *cur=head;

    while(cur->next!=head)
    {
        if(curr==head)
        {
            cout<<"<-";
        }
        cout<<cur->data<<"->";
        cur=cur->next;
    }

    if(cur->next==head)
    {
        cout<<cur->data<<"->";
    }
    
}

//this will dispkay the doubly linked list
void DoublyList::print()
{
    DoublyListnode *curr=head;

    while(curr->next!=NULL)
    {
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

//this will convert the doubly linked list to circular linked list. 
void DoublyList::circular()
{
    DoublyListnode *curr=head;

    while(curr->next!=NULL) // take the pointer to last node
    {
        curr=curr->next;
    }

    curr->next=head; //placing head in the previous of last node
    head->prev=curr; // placing the last node in the previous of head

    //  displaying the new doubly linked list
    DoublyListnode *cur=head;

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

// this function will insertnode in doubly linked list
void DoublyList::insertion(int val, int pos)
{
    if(pos>length+1 || pos< 1)
    {
        cout<<"Invalid position."<<endl;
        return;
    }

    DoublyListnode *n=new DoublyListnode(val);
    

    if(pos==1)
    {
        n->next=head;
        if(head!=NULL)
           head->prev=n;
        head=n;

    }

    else
    {
        DoublyListnode *curr=head;

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