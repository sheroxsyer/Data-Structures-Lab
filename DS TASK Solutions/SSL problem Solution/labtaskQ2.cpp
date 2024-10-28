//Write a program that concatenates two linked list objects of characters. 
//The program should include function concatenate, which takes references to both list 
//objects as arguments and concatenates the second list to the first list.

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

    // function declaration
    void insertion(int val, int pos);
    void printing();
    void concatenate(linkedlist a , linkedlist b);
};

int main()
{
    linkedlist obj , obj1;

    obj.insertion('a',1);
    obj.insertion('b',2);
    obj.insertion('c',3);

    obj.printing();
    cout<<endl;

    obj1.insertion('d',1);
    obj1.insertion('e',2);
    obj1.insertion('f',3);

    obj1.printing();
    cout<<endl;

    obj.concatenate(obj, obj1); // calling the function and passing the parameters 
    
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

// function that will concatenate the both list
void linkedlist::concatenate(linkedlist a , linkedlist b)
{
    node *curr=a.head; // curr store the head of the first list

    while(curr->next!=NULL) // through this loop we tale the curr to the last node
    {
        curr=curr->next;
    }

    curr->next=b.head; // in the next of the last node we will place the head of the second list

    node *temp=a.head;

    while(temp!=NULL) // printing the new concatenated list
    {
        cout<<temp->info<<" ";
        temp=temp->next;
    }
}