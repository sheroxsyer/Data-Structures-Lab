//Write a program that inserts 15 random integers from 0 to 100 in order in a linked 
//list object. The program should calculate the sum of the elements and the floating-point
//average of the elements.

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
    int sum();
    void average();
    void printing();
};

int main()
{
    linkedlist obj;

    // this for loop will pass 15 random values to the insertion function and also display them
    for (int x=0; x<15;x++)
    {
        int randomNumber = (rand() % 100);
   	    obj.insertion(randomNumber,(x+1));
        cout << randomNumber << endl;
    }

    //calling the function
    obj.sum();
    obj.average();

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


//it will add all the values of the list.
int  linkedlist::sum()
{
    if(head==NULL)
    {
        cout<<"Sum = 0 .List is empty."<<endl;
        return 0;
    }
    
    int summ=0; //summ variable will store the sum 

    node *temp=head;

    while(temp!=NULL) // this condition will traverse through whole list
    {
        summ+=temp->info; // adding each elemnt to summ varaible
        temp=temp->next; 
    }

    cout<<"Sum of the linked list = "<<summ<<endl; // diply the sum to the screen

    return summ;
}

void linkedlist::average()
{
    int s =sum();

    int a;
    a=s/length; // divide the sum by the length to obtain the average

    cout<<"Average of the linked list = "<<a<<endl;    // display the average
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
