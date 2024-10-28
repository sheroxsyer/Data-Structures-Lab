//Write a program that creates a linked list object of 10 characters and creates a second
//list object containing a copy of the first list, but in reverse order.

#include<iostream>
using namespace std;

class node
{
    public:
        node *next;
        char info;

    node(int val)
    {
        info=val;
        next=NULL;
    }    

};

class linkedlist  
{
    private:
        node *head;
        int length;

    public:
    linkedlist()
    {
        head=NULL;
        length=0;
    }    

    void insertion(int val, int pos);
    void reverse(int val);
    void copyReverse(linkedlist a, linkedlist b);
    void printing();
};

int main()
{
    linkedlist obj; 
    linkedlist obj1;

    //calling the function and passing the parameters to it.
    obj.insertion('a',1);
    obj.insertion('b',2);
    obj.insertion('c',3);
    obj.insertion('d',4);
    obj.insertion('e',5);
    obj.insertion('f',6);
    obj.insertion('g',7);
    obj.insertion('h',8);
    obj.insertion('i',9);
    obj.insertion('j',10);

    obj.printing();
    cout<<endl;

    obj.copyReverse(obj,obj1);

    return 0;
}

// this function will place each val in the first position 
void linkedlist::reverse(int val)
{

    node *n=new node(val);
    
        n->next=head;
        head=n;
        length ++;

}

void linkedlist::printing()
{
    node *n=head;

    while(n!=NULL)
    {
        cout<<n->info<<" ";
        n=n->next;
    }
}

// this function will copy the elements of the first list into the second list but in reverse order
void linkedlist::copyReverse(linkedlist a, linkedlist b)
{
    node *curr=a.head; 

    //this loop will take each value of the first list and insert it at the first position of the second list
    while(curr!=NULL)
    {
        b.reverse(curr->info);
        curr=curr->next;
    }

    node *cuur=b.head;
    
    //this loop will print the new reversed list
    while(cuur!=NULL) 
    {
        cout<<cuur->info<<" ";
        cuur=cuur->next;
    }

}


void linkedlist::insertion(int val, int pos)
{
    if(pos<1 || pos>length+1) // checking if the position is greater then length , return from the function
    {
        cout<<"Invalid position."<<endl;
        return;
    }

    node *n=new node(val);
    
    if(pos==1)
    {
        n->next=head;
        head=n;
        length ++;
    }

    else
    {
        node *n=new node(val);
        node *curr=head;

        for(int i=1; i<(pos-1); i++)
        {
            curr=curr->next; 
        }

        n->next=curr->next;
        curr->next=n;
        length ++;
        
    }

}