//Write a program that concatenates two double linked list objects of characters.

#include<iostream>
using namespace std;

class node
{
    public:
        char data;
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
    void concatenate(DoublyList obj, DoublyList obj1);

};

int main()
{
    DoublyList obj , obj1;

    //calling insertion function
    obj.insertion('a',1);
    obj.insertion('b',2);
    obj.insertion('c',3);
    obj.insertion('d',4);

    obj1.insertion('e',1);
    obj1.insertion('f',2);
    obj1.insertion('g',3);
    obj1.insertion('h',4);
    

    cout<<"Before concatenation."<<endl;
    cout<<"list 1 :";
    obj.print();

    cout<<"\nList 2 :";
    obj1.print();

    cout<<endl;

    //  caaling the function
    obj.concatenate(obj, obj1);

}

// this function will insert node in the list
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

//print the doubly linked list
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

//this function will concatenate two doubly linked list. We wil take curr pointer to the
//last node of the first list. Then in the next of curr pointer we will place the head of 
//the second list and in the previous of second list we will place this curr pointer.

void DoublyList::concatenate(DoublyList obj, DoublyList obj1)
{
    node *curr=obj.head;

    while(curr->next!=NULL) //loop that will take pointer to the last node
    {
        curr=curr->next;
    }

    curr->next=obj1.head; //in the next of curr pointer we will place the head of 
                          //the second list
    obj1.head->prev=curr; //in the previous of second list we will place this curr pointer.

    cout<<"After concatenation."<<endl;
    obj.print();

}



