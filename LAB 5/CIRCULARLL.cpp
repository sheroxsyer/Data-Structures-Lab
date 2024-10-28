#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node*next;
    node(int val)
    {
        data=val;
        next=NULL;
    }

};
class CIRCULARLL
{
    private:
    int length;
    node*head;
    public:
    CIRCULARLL()
    {
        length=0;
        head=NULL;
    }
    void insertAtbegin(int val);
    void deleteAtEnd();
    void printing();
};
void CIRCULARLL::insertAtbegin(int val)
{
    if(head == NULL)
    {
        node*t=new node(val);
        head=t;
        t->next=head;
        length++;
    }
    else
    {
        node*t=new node(val);
        node*curr=head;
        while(curr->next!=head)
        {
            curr=curr->next;
        }
        t->next =head;
        head=t;
        curr->next=head;
        length++;

    }

}
void CIRCULARLL::deleteAtEnd()
{
    node*curr=head;
    while(curr->next->next!=head)
    {
        curr=curr->next;
    }
    node*t=curr->next;
    curr->next=head;
    delete t;

}
void CIRCULARLL::printing()
{
    if(length==0)

    {
        cout<<"LINKLIST is empty"<<endl;
    }
    node*curr=head;
    while(curr->next!=head)
    {
        if(curr==head)
        {
            cout<<" ";
        }
        cout<<curr->data<<endl;
        curr=curr->next;
    }
    if(curr->next==head)
    {
        cout<<curr->data<<endl;
    }

} 
int main()
{
    CIRCULARLL obj;
    int menue_option;
    do
    {
        cout<<"Enter the option number.Press 0 to exit."<<endl;
        cout<<"1)InsertAtBegin()"<<endl;
        cout<<"2)deleteAtEnd()"<<endl;
        cout<<"3)printing()"<<endl;
        cin>>menue_option;

        switch (menue_option)
        {
        case 1:
            int val;
            cout<<"Enter the value :";
                cin>>val;
                obj.insertAtbegin(val);
                cout<<endl;
            
            break;
        case 2:
            
                obj.deleteAtEnd();
                cout<<endl;
            
            break;
        case 3:
            
                obj.printing();
                cout<<endl;
            
            break;        
        
        default:
                cout<<"enter correct option"<<endl;
            break;
        }
    } while (menue_option !=0);
    

    return 0;


}