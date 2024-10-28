//Write a program that merges two ordered list objects of integers into a single ordered 
//list object of integers. Function merge should receive references to each of the list 
//objects to be merged and reference to a list object into which the merged elements will
// be placed.

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
    void printing();
    void merge(linkedlist a , linkedlist b);
};

int main()
{
    linkedlist obj , obj1;

    obj.insertion(5,1);
    obj.insertion(10,2);
    obj.insertion(4,3);

    obj.printing();
    cout<<endl;

    obj1.insertion(7,1);
    obj1.insertion(1,2);
    obj1.insertion(0,3);

    obj1.printing();
    cout<<endl;

    obj.merge(obj, obj1);
    
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

//function merge will concatenate the two list passed as a parameter and then sort it
void linkedlist::merge(linkedlist a , linkedlist b)
{
      node *curr=a.head;

    while(curr->next!=NULL)
    {
        curr=curr->next;
    }

    curr->next=b.head;

    int l=a.length+b.length; // variable l conation the total length of the concatenated list

    for(int i=0; i<l; i++)
    {
        node *temp=a.head; // temp point to the head
        node *temp1=temp->next; // temp1 will always point one step ahead of the temp

        while(temp->next!=NULL) // through this condition we will traverse through the whole list
        {
            if(temp->info>temp1->info)  // check if the prev value is lesser then the next value
            {
                // the following line swap the both values
                int v=temp->info;
                temp->info=temp1->info;
                temp1->info=v;
            }

            temp=temp1;
            temp1=temp->next;
        }
    }

     node *temp2=a.head; 

    // this loop will traverse the whole list
    while(temp2!=NULL)
    {
        cout<<temp2->info<<" ";
        temp2=temp2->next;
    }
    
   
}