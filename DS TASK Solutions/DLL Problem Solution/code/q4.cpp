//Write a code to split a doubly link list into sublists — one for the front half, and 
//one for the back half. If the number of elements is odd, the extra element should go in 
//the front list. So FrontBackSplit() on the list {2, 3, 5, 7, 11} should yield the two 
//lists {2, 3, 5} and {7,11}. You should check your solution against a few cases (length 
//= 2, length = 3, length=4) to make sure that the list gets split correctly near the 
//short-list boundary conditions. You will probably needspecial case code to deal with
// the (length<2) cases.

#include<iostream>
using namespace std;

class node // box that will contain the data and address of orevious and next node
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

class DoublyList // class that willc onatn the data members and function of doubly link list
{
    public:
        node *head;
        int length;

    DoublyList()
    {
        head=NULL;
        length=0;
    }

    // function declaration
    void insertion(int val, int pos);
    void split();
    void print();

};

int main()
{
    DoublyList obj; // creating object of the class

    obj.insertion(2,1);
    obj.insertion(3,2);
    obj.insertion(5,3);
    obj.insertion(7,4);
    obj.insertion(11,5);

    cout<<"Before split."<<endl;
    obj.print();

    cout<<endl;

    obj.split(); // calling the split function 

    return 0;
}

// this function will insert node in the doubly linked list
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

//display the doubly linked list
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

//This function will split the doubly linked list into two parts. We will divide the
// length by 2 if the length is odd then we will add 1 to it and run a loop till this
// many times and increment the current pointer. In another pointer we will store the next
//of the current and create one more object of the class and place its head to this pointer.
//and make its previos nulll. Now in the next of the current we will put NULL. In this way 
// we will create two doubly linked list
void DoublyList::split()
{
    if(length==1) // If the list is of length 1 it cannot be split.
    {
        cout<<"Its not possbile to split a list of length of 1."<<endl;
        return ;
    }

    int length1=0;
    node *curr=head;

    if(length%2==0) // checking whether the length is even or odd
    {
        length1=length/2;
    }
    else
    {
        length1=(length/2)+1; // adding one incase its odd
    }

    for(int i=1; i<length1; i++) // Taking the current pointer to the node that will be our last node of first list
    {
        curr=curr->next;
    }

    node *secondList=curr->next; 
    secondList->prev=NULL;

    curr->next=NULL; // creating first list

    DoublyList obj1;

    obj1.head=secondList; //creating second list
  

    //displaying the splited list
    cout<<"After split."<<endl;
    cout<<"List 1 : "<<endl;
    print();

    cout<<endl;

    cout<<"List 2 : "<<endl;
    obj1.print();

}