//Write a program that creates a linked list of 10 integer nodes and then reverse the 
//list.

#include<iostream>
using namespace std;

class node
{
    public:
        int data;
        node *prev;
        node *next;

    node(int val)
    {
        data=val;
        prev=NULL;
        next=NULL;
    }
};

class DoublyList
{
    public:
        node *head;
        int length;

    DoublyList()
    {
        head=NULL;
        length=0;
    }    

    void insertion(int val, int pos);
    void print();
    void reverse();
    void tail(node *p);

};

int main()
{
    DoublyList obj;

    obj.insertion(10,1);
    obj.insertion(9,2);
    obj.insertion(8,3);
    obj.insertion(7,4);
    obj.insertion(6,5);
    obj.insertion(5,6);
    obj.insertion(4,7);
    obj.insertion(3,8);
    obj.insertion(2,9);
    obj.insertion(1,10);
    
    cout<<"Before reversing."<<endl;
    obj.print();

    obj.reverse();

    cout<<"After reversing."<<endl;
    obj.print();

}

void DoublyList::insertion(int val, int pos)
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

//this function will reverse the list. We will place one pointer at the head and the other
// at the end of the list and swap the values. Then the the pointer pointing to head will
//move in forward direction and the other will move backward and the swapping will be 
//performed. This will be done length/2 times.
void DoublyList::reverse()
{
    node *curr=head;

    while(curr->next!=NULL) // take the curr pointer to the end
    {
        curr=curr->next;
    }

    node *p=head;

    int stop=length/2; // condtion for stoping the loop

    for(int i=1; i<=stop; i++) // perform the swapping for reversing the list
    {
        int temp=curr->data;
        curr->data=p->data;
        p->data=temp;

        curr=curr->prev;
        p=p->next;
    }
}