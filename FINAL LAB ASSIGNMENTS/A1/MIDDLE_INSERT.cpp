
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

    node *t=new node(val);
    
    if(pos==1)
    {
        t->next=head;
        head=t;
        length ++;
    }

    else
    {
        node *t=new node(val);
        node *curr=head;

        for(int i=1; i<pos-1; i++)
        {
            curr=curr->next; 
        }

        t->next=curr->next;
        curr->next=t;
        length ++;
        
    }

}

void print()
{
    node *temp=head;

    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

//for insertion in middle in link list
void midInsert(int val) 
{
    // here we divide the length by 2 to find the mid pos
    int pos=length/2; 

    // insert the value after the pos ,So we will increment the length
    pos++;
    //here using  previous function of insert instead of making new function and using updated pos it insert it in middle  
    insert(val,pos);
}
};

int main()
{
    linkedlist obj;

    obj.insert(1,1);
    obj.insert(2,2);
    obj.insert(3,3);
    obj.insert(4,4);

    obj.print();
    cout<<endl;

    obj.midInsert(7);
    obj.print();
    cout<<endl;
    
    return 0;
}

