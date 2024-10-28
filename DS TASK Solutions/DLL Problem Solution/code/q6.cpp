//Write a menu driven C++ program for following functions of a Circular Linked list.
//1. InsertAtBegin()
//2. DeleteAtEnd()

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

// class that will contain the data members and data function
class Circularlinkedlist 
{
    private:
        node *head;
        int length;

    public:
    Circularlinkedlist() // constructor
    {
        head=NULL;
        length=0;
    }    

    //function declaration 
    void insertAtbegin(int val);
    void deleteAtEnd();
    void printing();
};

int main()
{
    Circularlinkedlist obj;

    int option; // variable to store user choice

    do // use do while loop to create a menu driven program
    {
        cout<<"Enter the option number.Press 0 to exit."<<endl;
        cout<<"1)InsertAtBegin()"<<endl;
        cout<<"2)deleteAtEnd()"<<endl;
        cout<<"3)printing()"<<endl;
        cin>>option;

        switch(option)
        {
            case 1:
                int val;
                cout<<"Enter the value :";
                cin>>val;
                obj.insertAtbegin(val);
                cout<<endl;
            break;

            case 2:
                obj.deleteAtEnd();
                cout<<endl;
            break;

            case 3:
                obj.printing();
                cout<<endl;
            break;  


            default:
                cout<<"Enter correct option."<<endl;
                cout<<endl;
            break;  

        }

    }while(option!=0);
    
    return 0;
}

//function for inseting in the start. In the next of new node head will be placed and 
// head will be placed at this new node. In the next of last node head will be placed
void Circularlinkedlist::insertAtbegin(int val)
{
    if(head==NULL) //inserting the node is the llist ie empty
    {
        node *n=new node(val);
        head=n;
        n->next=head;

        length++;
    }
    else  // inserting the node if the list is node empty
    {
        node *n=new node(val); // creating the node
        node *curr=head;

        while(curr->next!=head)
        {
            curr=curr->next;
        }

        n->next=head;
        head=n;
        curr->next=head;

        length ++; // inc the length as new node is added to the list
    }    
}

// this function will delete at the end. WE will take the pointer to the second last 
//node put head in the next of it. And delete the last node
void Circularlinkedlist::deleteAtEnd()
{
    node *cur=head;

    while(cur->next->next!=head) // loop that will take pointer to the second last node
    {
        cur=cur->next;
    }

    node *n=cur->next; // saving the node to be deleted
    cur->next=head; // placing head in the next of the second last node
    delete n; // deleting the node
}


void Circularlinkedlist::printing() // will print the circular list
{
    if(length==0)
    {
        cout<<"List is empty."<<endl;
    }

    node *curr=head;

    while(curr->next!=head)
    {
        if(curr==head)
        {
            cout<<"<-";
        }
        cout<<curr->info<<"->";
        curr=curr->next;
    }

    if(curr->next==head)
    {
        cout<<curr->info<<"->";
    }
}

