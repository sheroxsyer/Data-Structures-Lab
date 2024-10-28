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
    node*top;
    int noOfElements;
    int size;
    public:
    // public:
    // Stack() : top(nullptr) {}
    

    Stack() :top(nullptr)
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
    void push(int val);
    void display();
    int pop();
    void reverse();

    int peek()
    
    {
        return top->data;


    }
    bool isEmpty();
    int getLength();
    void setSize(int size)
    {
        this->size=size;

    }
};
int main()
{
    Stack stack1,stack2;
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    stack1.push(6);
    stack1.pop();
    stack1.display();
    cout<<endl<<"Stack size: "<<stack1.getLength()<<endl;
    stack1.reverse();
    stack1.display();
    return 0;

}
void Stack::reverse() {
        // Initialize three pointers to traverse the linked list
        node* prev = nullptr;
        node* current = top;
        node* next = nullptr;

        while (current) {
            // Store the next node in the linked list
            next = current->next;

            // Reverse the link
            current->next = prev;

            // Move the pointers to the next position
            prev = current;
            current = next;
        }

        // Update the top pointer to the new head of the linked list
        top = prev;
    }


int Stack ::getLength()
{
    return this->noOfElements;
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
        cout<<"Node: "<<curr->data<<endl;
        curr =curr->prev;
    }
}