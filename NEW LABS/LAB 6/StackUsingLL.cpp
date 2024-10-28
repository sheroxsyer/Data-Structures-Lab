#include<iostream>
using namespace std;
class node
{
    public:
    node*prev;
    node*next;
    
    int data;
    node(int val)
    {
        data = val;
        prev=next=NULL;
    }

};

class Stack
{
    private:
    
    int noOfElements;
    int size;
    public:
    node*top;
    Stack()
    {
        top = NULL;
        noOfElements = 0;
        size=10;
    }
    ~Stack() {
        while (top) {
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }
//declaring funtions
    void push(int val);
    void display();
    int pop();
    void reverseStack();
        

    int peek()
    
    {
        return top->data;


    }
    bool isEmpty();
    
    
};
int main()
{
    Stack s;
    cout<<"push elements are:"<<endl;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.display();
    cout<<"after removal "<<endl;
    s.pop();
    s.display();
    
    cout<<"reverese list is"<<endl;
    s.reverseStack();
    s.display();
    return 0;

}



bool Stack ::isEmpty()
{
    if(noOfElements == 0)
    return true;
    else
    return false;
}
int Stack ::pop()
{
    node*curr = top;
    if(curr == NULL)
    {
        cout<<"List is empty: Stack Underflow ,return -1"<<endl;
        return -1;
    }
    else
    {
        node*curr = top;
        int data = curr->data;
        top = curr->prev;
        delete curr;
        noOfElements--;
        return data;
    }
}
void Stack ::push(int val)
{
    if(noOfElements<size)
    {
        node*t=new node(val);
        if(top == NULL)
        {
            top=t;
            noOfElements++;

        }
        else{
            t->prev=top;
            top=t;
            noOfElements++;

        }
    }
    else
    cout<<"Stack full : Overflow"<<endl;
}

void Stack::display()
{
    node*curr=top;
    while(curr!=NULL)
    {
        cout<<curr->data<<endl;
        curr =curr->prev;
    }
}

void Stack ::reverseStack() {
    // use 3 variables to traverse list
        node* prev = NULL;
        node* curr = top;
        node* next = NULL;

        while (curr) {
            // Store next in list
            next = curr->next;

            // Reverse list
            curr->next = prev;

            // Move the pointers 
                
            prev = curr;
            curr = next;
        }

        // Update top
        top = prev;
}
