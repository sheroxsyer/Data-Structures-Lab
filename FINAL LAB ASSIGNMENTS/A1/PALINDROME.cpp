
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

    void Palindrome(linkedlist a, linkedlist b)
{
    node *curr=a.head;

    node * curr1=NULL;

    //first list in reverse order
    while(curr!=NULL)
    {
        node *n=new node(curr->data);
        n->next=b.head;
        b.head=n;
        curr=curr->next;
    }

    
    node *cp1=b.head;
    node *cp=a.head;

    
    while(cp!=NULL)
    {
        if(cp->data!=cp1->data)  
        {
            cout<<"Linklist is  not a palindrome."<<endl;
            // cout<<cp1->info<<" "<<cp->info<<endl;
            return;
        }

        cp=cp->next;
        cp1=cp1->next;
    }

     
    cout<<"Link list is a palindrome."<<endl;
}

void insert(int val, int pos)
{
    if(pos<1 || pos>length+1) 
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

void print()
{
    node *n=head;

    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }
}

    
};

int main()
{
    linkedlist l; 
    linkedlist l1;

    l.insert(1,1);
    l.insert(7,2);
    l.insert(1,3);
    
    l.print();
    cout<<endl;
    l.Palindrome(l, l1);

    linkedlist l2; 
    linkedlist l3;   

    cout<<endl;
    l2.insert(5,1);
    l2.insert(4,2);
    l2.insert(2,3);
    
    l2.print();
    cout<<endl;
    l2.Palindrome(l2, l3);
    
    cout<<endl;
    return 0;
}

 
