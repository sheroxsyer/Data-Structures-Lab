#include<iostream>
using namespace std;

class node //class for the box that will contain our data and address of the next box
{
    public:
        node *next;
        int info;

    node(int val) //parameterized constructor
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

    //function declaration 
    void insertion(int val, int pos);
    void printing();
};

int main()
{
    linkedlist obj; //making object of the list

    obj.insertion(12,1); // calling the function and passing the parameters
    obj.insertion(24,2);
    obj.insertion(36,3);
    
    obj.printing();
    
    return 0;
}

//function for inseting in the start , end and anywhere in the list
void linkedlist::insertion(int val, int pos)
{
    if(pos<1 || pos>length+1) // checking if the position is greater then length , return from the function
    {
        cout<<"Invalid position."<<endl;
        return;
    }

    node *n=new node(val); // creating the node
    
    if(pos==1) // condition for inserting in the start
    {
        n->next=head; //put the current head in the next of the new node 
        head=n; // make the new node head
        length ++; // inc the length as new node is added to the list
    }

    else
    {
        node *n=new node(val);
        node *curr=head;

        for(int i=1; i<(pos-1); i++) // it will take curr pointer to the node after which we want to insert the new node
        {
            curr=curr->next; 
        }

        n->next=curr->next;  //the node which was after the curr node is now next to the new node
        curr->next=n; // it will palce the new node after the curr
        length ++;
        
    }

}

void linkedlist::printing() // will print the list
{
    node *n=head;

    while(n!=NULL) //condition for traversing the whole list
    {
        cout<<n->info<<" ";
        n=n->next;
    }
}



