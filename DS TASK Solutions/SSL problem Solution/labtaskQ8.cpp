//Write a function to check whether the given Singly Linked List is Palindrome or not.

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
    void Palindrome(linkedlist a, linkedlist b);
};

int main()
{
    linkedlist obj; 
    linkedlist obj1;

    obj.insertion(1,1);
    obj.insertion(2,2);
    obj.insertion(1,3);
    
    obj.printing();
    cout<<endl;
    obj.Palindrome(obj, obj1);

    linkedlist obj2; 
    linkedlist obj3;   

    cout<<endl;
    obj2.insertion(2,1);
    obj2.insertion(3,2);
    obj2.insertion(1,3);
    
    obj2.printing();
    cout<<endl;
    obj2.Palindrome(obj2, obj3);
    
    cout<<endl;
    return 0;
}

//this function will check whether the number remain the same if we write it in reverse order just like the number 121 
void linkedlist::Palindrome(linkedlist a, linkedlist b)
{
    node *curr=a.head;

    node * curr1=NULL;

    //making a new list which will contain the elements of first list in reverse order
    while(curr!=NULL)
    {
        node *n=new node(curr->info);
        n->next=b.head;
        b.head=n;
        curr=curr->next;
    }

    
    node *cp1=b.head;
    node *cp=a.head;

    // if the elements of the original and reverse list is not same it will retrun from here and tell the user that the list is not palindrome
    while(cp!=NULL)
    {
        if(cp->info!=cp1->info) // checking whether the elements are same or not 
        {
            cout<<"Its not a palindrome."<<endl;
            // cout<<cp1->info<<" "<<cp->info<<endl;
            return;
        }

        cp=cp->next;
        cp1=cp1->next;
    }

    //After matching both the list if all the elements come same we will display that the list is palindrome 
    cout<<"Its a palindrome."<<endl;
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