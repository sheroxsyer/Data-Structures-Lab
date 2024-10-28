//Write a C++ program to sort doubly linked list by swapping there links not the data

#include<iostream>
using namespace std;

// This wil create a box like structure. It will contain our data and address of the next
// and previous boxes
class node 
{
    public:
        int data;
        node *prev;
        node *next;

    node(int val) //parameterized constructor
    {
        data=val;
        prev=NULL;
        next=NULL;
    }
};

// This class will conatin our data members and function
class DoublyList
{
    public:
        node *head;
        int length;

    DoublyList() //constructor
    {
        head=NULL;
        length=0;
    }  

    //function declaration
    void insertion(int val, int pos);
    void sort();
    void print();

};

int main()
{
    DoublyList obj; // crreating obj of class

    //  calling the insert ftn to insert values in the list
    obj.insertion(4,1);
    obj.insertion(3,2);
    obj.insertion(2,3);
    obj.insertion(1,4);

    cout<<"Before sorting."<<endl;
    obj.print();

    obj.sort(); // calling the sort function

    cout<<"After sorting."<<endl;
    obj.print();

    return 0;

}

void DoublyList::insertion(int val, int pos)
{
    if(pos>length+1 || pos< 1) // condition to check whether the position is valid or not
    {
        cout<<"Invalid position."<<endl;
        return;
    }

    node *n=new node(val); 
    

    if(pos==1) // for inserting at first position
    {
        n->next=head;
        if(head!=NULL)
           head->prev=n;
        head=n;

    }

    else // For inserting anywhere in between or at the end
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

// this funtion will print the values of list
void DoublyList::print()
{
    node *p=head;

    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

    cout<<endl;
}

//In this function we have sort the doubly link list by bubblesort. the whole nodes are
//swapped.... its not possible to explain the code through comments you can take viva 
//from me!
void DoublyList::sort()
{
    node *n=head;
    node *p=n;
    n=n->next;

    for(int i=1; i<length; i++) // traverse through list one less time the length
    {
        while(n!=NULL) // for traversing through the list once
        {
            if(p->data>n->data) // checking if the previous value is greater then the next value
            {
                if(p==head) // swapping when the previous node is head
                {
                    p->next=n->next;
                    n->next->prev=p;
                    n->next=p;
                    p->prev=n;
                    n->prev=NULL;
                    head=n;

                    node *store=n;
                    n=p;
                    p=store;
                }
                else // for all the other locations
                {
                    p->next=n->next;
                    if(n->next!=NULL)
                    {
                        n->next->prev=p;
                    }
                    p->prev->next=n;
                    n->prev=p->prev;
                    n->next=p;
                    p->prev=n;

                    node *store1=n;
                    n=p;
                    p=store1;

                }
            }

            p=p->next;
            n=n->next;
        }

        n=head;
        p=n;
        n=n->next;
    }  
}


// you are given the head of doubly link list in c++.reorder the list in the form of 
// given =1-2-3-4
// return 1-4-2-3
