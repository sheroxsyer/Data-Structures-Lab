//Write a C++ program to remove every duplicate from a doubly linked list.
//Input:
//NULL<-1<->2<->2<->3<->4<->4<->5<->5<->5->NULL
//Output:
//1->2->3->4->5->NULL

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
    void deletion(int p);
    void print();
    void RemoveDuplicates();
};

int main()
{
    DoublyList obj;

    obj.insertion(1,1);
    obj.insertion(2,2);
    obj.insertion(2,3);
    obj.insertion(3,4);
    obj.insertion(4,5);
    obj.insertion(4,6);
    obj.insertion(5,7);
    obj.insertion(5,8);
    obj.insertion(5,9);

    cout<<"Before removing duplicates."<<endl;
    obj.print();

    cout<<"After removing duplicates."<<endl;
    obj.RemoveDuplicates();
    obj.print();
    
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

// In function we will remove the duplicates from the list. First we sort the list in 
// ascending order. Then we will check if the values of adjacent node is same we will
// delete the one node from them. In this way duplicates will be removed
void DoublyList::RemoveDuplicates()
{
    node *n=head;

    //this for loop will sort the list
    for(int i=1; i<length; i++)
    {
        for(int i=1; i<=(length-1); i++)
        {
            if(n->data>n->next->data)
            {
                int temp=n->data;
                n->data=n->next->data;
                n->next->data=temp;
            }

            n=n->next;
        }

        n=head;
    }

    node *temp=head;

    //deleting the duplicates
    while(temp->next!=NULL) //this loop will help to traverse the list
    {
        if(temp->data==temp->next->data) // condition for removing the duplicates, As the list is sorted so if the element is the same as the next element we will delete it 
        {
            if(temp==head) // for deleting the the element at first pos
            {
                head=temp->next;
                head->prev=temp->prev;
                node *n=temp;
                temp=head;
                delete n;
            }

            else //for deleting the element anywhere in between or in the last 
            {
                node *n=temp;
                node *p=temp->prev;
                p->next=temp->next;
                if(temp->next!=NULL)
                temp->next->prev=p;

                temp=p->next;
                delete n;
            }

        }

        else // if the element adjacent to it, is not the same , we will move to the next element
        {
            temp=temp->next;
        }
        
    }


}
