//Write a RemoveDuplicates() function which takes a list sorted in increasing order and
//deletes any duplicate nodes from the list. Ideally, the list should only be traversed
// once.

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
    void RemoveDuplicates();
    void deletion(int p);
};

int main()
{
    linkedlist obj , obj1;

    obj.insertion(7,1);
    obj.insertion(10,2);
    obj.insertion(4,3);
    obj.insertion(7,4);
    obj.insertion(1,5);
    obj.insertion(4,6);

    obj.printing();
    obj.RemoveDuplicates();

    cout<<"\nAfter removing duplicates."<<endl;
    obj.printing();

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

void linkedlist::RemoveDuplicates()
{

    for(int i=0; i<length; i++) //loop for sorting
    {
        node *temp=head; // temp point to the head
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

    node *temp=head;
    //node *temp1=temp;

    while(temp->next!=NULL) //this loop will help to traverse the list
    {
        if(temp->info==temp->next->info) // condition for removing the duplicates, As the list is sorted so if the element is the same as the next element we will delete it 
        {
            if(temp==head) // for deleting the the element at first pos
            {
                head=head->next;
                node *n=temp;
                temp=head;
                delete n;
            }

            else //for deleting the element anywhere in between or in the last 
            {
                node *n=temp->next;
                temp->next=temp->next->next;
                delete n;
            }

        }

        else // if the element adjacent to it, is not the same , we will move to the next element
        {
            temp=temp->next;
        }
        
    }
}

void linkedlist::deletion(int p)
{
   if(head==NULL)
   {
       cout<<"There isnothing to delete .List is empty."<<endl;
       return;
   }

   if(p>length) // check for invalid position
   {
       cout<<"Invalid position."<<endl;
       return;
   }

   node *prev=NULL;
   node *curr=head;

   if(p==1) // condition for deleting the first value
   {
       head=head->next;
   }

   else // for deleting the value in the end or in between
   {
       for(int i=1; i<p; i++) 
       {
           prev=curr; 
           curr=curr->next;
       }

       prev->next=curr->next;
   }

   delete curr; // the curr pointer is pointing to the value we want to delete thats why we are deleting curr here
   length--; // dec the length of the list as one value is deleted
}