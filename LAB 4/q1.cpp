#include<iostream>
using namespace std;
class node{
    public:
    node*next;
    int info;
    //constructor
    node(int val)
    {
        info=val;
        next=NULL;
    }

};
class SLL{
    private:
    node*head;
    int length;
    public:

    SLL(){
        head=NULL;
        length=0;

    }
    //INSERTION
    void insert(int val,int pos)
    {
        if (pos<1 || pos>length + 1) {
                cout << "Invalid position." << endl;
                return;
            }
        node*t=new node(val);
        //CHECK FOR HEAD
        if(head ==NULL)
        {
            t->next=head;
            head =t;
            length++;
        }
        else{
            node*curr = head;
            while(curr->next!=NULL)
            {
                curr=curr->next;
            }
            t->next=curr->next;
            curr->next=t;
            

        }
        length++;
    }
//PRINTING SLL
    void printing()
    {
        
        node*curr=head;
        while(curr!=NULL)
        {
            cout<<curr->info;
            curr=curr->next;
        }
    }
    //DELETION FROM SLL
    void remove(int pos)
    {
        node*curr=head;
        if(head == NULL)
        {
            cout<<"list is empty"<<endl;
            return;
        }

        if(pos == 1)
        {
            head = curr->next;
            delete curr;
            length--;

        }
        else{
            node*temp=NULL;
            for(int i=0;i<pos-1;i++)
            {
                temp=curr;
                curr= curr->next;
            }
            temp->next=curr->next;
            curr->next=NULL;
            delete curr;
            length--;
        }
    }
    //SEARCHING IN SLL
    bool search(int val)
    {
        if (head == NULL)
        {
            cout<<"list is empty"<<endl;   
        }
            node*curr=head;
            while(curr!=NULL)
            {
                if (curr->info==val)
                {
                    cout<<"Value found"<<endl;
                    return true;
//                    cout<<curr->info<<endl;
                    
                    
                }
                
                
                   // return false;
                    
                   
                curr=curr->next;
            }
                cout<<"Value not found"<<endl;
    }
    //MOVING LAST VALUE TO HEAD
    void moveHead()
    {
        node*curr;
        node*last;
        node*temp=head;
            
        while(temp!=NULL)
        {
            temp=temp->next;
        }
            last=temp;
            temp=head;
            head=last;
            head->next=temp;
    }

    void sort()
    {
        
    }

    

};
int main()
{
    SLL s;
    cout<<"SINGLE LINK LIST "<<endl;
    cout<<"INSERTED VALUES ARE:"<<endl;
    
    s.insert(1,1);
    s.insert(2,2);
    s.insert(3,3);
    s.insert(5,4);
    s.insert(7,5);
    s.insert(8,6);
    s.printing();
    cout<<endl;
    cout<<endl;
    s.remove(2);
    cout<<"SSL AFTER DELETION IS:"<<endl;
    
    s.printing();
    cout<<endl;
    cout<<"Searching element is :"<<endl;
    s.search(5);
    cout<<endl;
    cout<<"MOVE NODE TO HEAD"<<endl;
    s.moveHead();
    s.printing();
    return 0;
}