//Write a C++ program to move the last node to the front of a Singly Linked List.
//Example:
//Given: 1->2->3->4->NULL
//Return: 4->1->2->3->NULL

#include<iostream>
using namespace std;

class node
{
    public:
        node *next;
        int info;

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
    void LtoF();
    void printing();
};

int main()
{
    linkedlist obj;

    obj.insertion(1,1);
    obj.insertion(2,2);
    obj.insertion(3,3);
    obj.insertion(4,4);

    obj.printing();
    cout<<endl;

    obj.LtoF();
    obj.printing();
    cout<<endl;
    
    return 0;
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

void linkedlist::printing()
{
    node *n=head;

    while(n!=NULL)
    {
        cout<<n->info<<" ";
        n=n->next;
    }
}

//this function will make the last node the first node
void linkedlist::LtoF()
{
    node *curr=head;
    node *temp=head;

    while(curr->next->next!=NULL) // through this loop we will reach the last element
    {
        curr=curr->next;
    }

    node *n=curr->next; // save the last node in pointer n 
    curr->next=NULL; // putting null in the next of the last node
    n->next=temp; // place the first node in the next of the last node
    head=n; // make the last node the first node by placing the head pointer to it
}