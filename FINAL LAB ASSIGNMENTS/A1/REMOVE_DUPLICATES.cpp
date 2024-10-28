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

void RemoveDuplicates()
{
    //sorting

    for(int i=0; i<length; i++) 
    {
        node *temp=head; 
        node *temp1=temp->next; 

        while(temp->next!=NULL) 
        {
            if(temp->data>temp1->data) 
            {
                // swapping
                int v=temp->data;
                temp->data=temp1->data;
                temp1->data=v;
            }

            temp=temp1;
            temp1=temp->next;
        }
    }

    node *temp=head;
    
    //traversing
    while(temp->next!=NULL)  
    {
        if(temp->data==temp->next->data)  
        {
            if(temp==head) 
            {
                head=head->next;
                node *n=temp;
                temp=head;
                delete n;
            }

            else  
            {
                node *n=temp->next;
                temp->next=temp->next->next;
                delete n;
            }

        }

        else 
        {
            temp=temp->next;
        }
        
    }
}

void remove(int p)
{
   if(head==NULL)
   {
       cout<<"List is empty."<<endl;
       return;
   }

   if(p>length) 
   {
       cout<<"Invalid position."<<endl;
       return;
   }

   node *prev=NULL;
   node *curr=head;

   if(p==1) 
   {
       head=head->next;
   }

   else 
   {
       for(int i=1; i<p; i++) 
       {
           prev=curr; 
           curr=curr->next;
       }

       prev->next=curr->next;
   }

   delete curr; 
   length--; 
}    

    
};

int main()
{
    linkedlist l , l1;

    l.insert(7,1);
    l.insert(10,2);
    l.insert(4,3);
    l.insert(7,4);
    l.insert(1,5);
    l.insert(4,6);

    l.print();
    l.RemoveDuplicates();

    cout<<"\nAfter removing duplicates."<<endl;
    l.print();

    return 0;
}

