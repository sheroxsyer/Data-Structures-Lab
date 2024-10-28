
#include<iostream>
using namespace std;

class node
{
    public:
        node *next;
        int data;

    node(int val)
    {
        data=val;
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
    void middleInsert(int val);
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

    obj.middleInsert(100);
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
        cout<<n->data<<" ";
        n=n->next;
    }
}

// this function will insert in the middle of the insert
void linkedlist::middleInsert(int val) 
{
    int pos=length/2; // divide the length by 2 to find the middle position

    //our insertion function add the new value at the position provided to it but we want to insert the value after the position ,So we will inc the length by one
    pos++;
    
    insertion(val,pos);
}