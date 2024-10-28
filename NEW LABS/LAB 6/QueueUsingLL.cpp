#include<iostream>
using namespace std;
class node
{
    public:
    node*next;
    int data;
    node(int val)
    {
        data = val;
        next= NULL;
    }

};
class Queue
{
    private:
    node*rear;
    node*front;
    int noOfElements;
    public:
    Queue()
    {
        front = rear = NULL;
        noOfElements= 0;
    }
    void enqueue(int val);
    void display();
    int dequeue();
    bool isEmpty();
    int size();
};
int main()
{
    Queue Queue1;
    Queue1.enqueue(1);
    Queue1.enqueue(2);
    Queue1.enqueue(3);
    Queue1.enqueue(4);
    Queue1.enqueue(5);
    Queue1.enqueue(6);
    Queue1.dequeue();
    Queue1.display();
    cout<<endl<<"queue size: "<<Queue1.size()<<endl;
    return 0;

    

}

int Queue ::size()
{
    return noOfElements;
}
bool Queue::isEmpty()
{
    if(noOfElements == 0)
    return true;
    else
    return false;
}
int Queue ::dequeue()
{
    node*curr = front;
    if(curr == NULL)
    {
        cout<<"List is empty: Queue Underflow ,return -1"<<endl;
        return -1;
    }
    else
    {
        node*curr = front;
        int data = curr->data;
        front = curr->next;
        delete curr;
        noOfElements--;
        return data;
    }
}
void Queue ::enqueue(int val)
{
    
        node*t=new node(val);
        if(front == NULL)
        {
            front=rear=t;
            noOfElements++;

        }
        else{
            rear->next=t;
            rear = rear->next;
            noOfElements++;

        }
    
}
void Queue::display()
{
    node*curr=front;
    while(curr!=NULL)
    {
        cout<<"Node: "<<curr->data<<endl;
        curr =curr->next;
    }
}
