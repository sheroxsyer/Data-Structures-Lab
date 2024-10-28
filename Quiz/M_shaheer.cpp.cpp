#include<iostream>
using namespace std;

class node 
{
    public:
        int data;
        node *prev;
        node *next;

    node(int val) 
    {
        data=val;
        prev=NULL;
        next=NULL;
    }
};

class DoublyList
{
    public:
        node *head;
        int length;

    DoublyList() 
    {
        head=NULL;
        length=0;
    }  

    
    void insertion(int val, int pos);
    void swap();
    void print();
    

};

int main()
{
    DoublyList obj;

    obj.insertion(1,1);
    obj.insertion(2,2);
    obj.insertion(3,3);
    obj.insertion(4,4);

    cout<<"Before swapping."<<endl;
    obj.print();

    obj.swap();

    cout<<"After swapping."<<endl;
    obj.print();

    return 0;

}

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

void DoublyList::swap()
{
    node*curr_nextL=head;
    node*curr_prevL=NULL;
    int lPos;
    int rPos;
    if (lPos == rPos) {
        return;
    }
    //for swapping first and last nodes
    while(curr_nextL!=NULL)
    {
        curr_nextL->next;
        while(curr_prevL!=curr_nextL)
        {
            curr_prevL->prev;
            
        }

    }

    for (int i = 1; i < lPos && curr_nextL != NULL; i++) {
        curr_prevL = curr_nextL;
        curr_nextL = curr_nextL->next;
        curr_prevL = curr_nextL->prev;

    }

    node* prevR = NULL;
    node* currR = head;
    for (int i = 1; i < rPos && currR != NULL; i++) {
        prevR = currR;
        currR = currR->next;
        prevR = currR->prev;
    }
    if (curr_nextL == NULL || currR == NULL) {
        return;
    }

    if (curr_prevL != NULL) {
        curr_prevL->next = currR;

    } else {
        head = currR;
    }

    if (prevR != NULL) {
        prevR->next = curr_nextL;
    } else {
        head = curr_nextL;
    }

    node* temp = currR->next;

    currR->next = curr_nextL->next;
    currR->prev=curr_prevL->prev;
    curr_nextL->next = temp;

}

