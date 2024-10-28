#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node*next;
    node*prev;
    node(int val)
    {
        val = data;
        next=prev=NULL;
    }

};
class SplitDLL
{
    public:
    node*head;
    int length;
    SplitDLL()
    {
        head=NULL;
        length=0;
    }

    void insert(int val, int pos)
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
void print()
{
    node *p=head;

    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }

    cout<<endl;
}

void splitlist()
{
    if(length==1)
    {
        cout<<"NOt possible to split insert element"<<endl;
        return;
    }
    int size=0;
    node*curr=head;
    //checking odd and even
    if(length%2==0)
    {
        size=length/2;
    }
    else
    {
        size=(length/2)+1;

    }
    for(int i=1;i<size;i++)
    {
        curr=curr->next;
    }
    node*newlist=curr->next;
    newlist->prev=NULL;
     
    curr->next=NULL;
    
    SplitDLL s;
    s.head=newlist;
    //print

    cout<<"After split."<<endl;
    cout<<"List 1 : "<<endl;
    print();

    cout<<endl;

    cout<<"List 2 : "<<endl;
    s.print();


}


};
int main()
{
    SplitDLL li;
    li.insert(100,1);
    li.insert(1,2);
    li.insert(2,3);
    li.insert(3,4);
    li.insert(4,5);
    li.print();
    
    cout<<"Before split."<<endl;
    li.print();

    cout<<endl;

    li.splitlist();
    li.print();

    return 0;


}