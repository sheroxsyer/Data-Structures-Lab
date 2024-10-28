#include<iostream>
using namespace std;
class node
{
    public:
    node*next;
    int data;
    node(int val)
    {
        next=NULL;
        data=val;
    }

};
class Queue
{
    private:
    node *rear;
    node *front;
    int noOfElement;
    public:
    Queue()
    {
        rear =NULL;
        front=NULL;
        noOfElement=0;
    }

    bool isEmpty()
    {
        if(noOfElement == 0)
        {
            return true;
        }
        else{
            return false;
        }
    }
    void Enqueue(int val)
    {
        node*t = new node(val);
        if(front == NULL)
        {
            front = rear =t;
            noOfElement++;
        }
        else{
            rear->next=t;
            rear = rear->next;
            noOfElement++;
        }

    }
    int deQueue()
    {
        node*curr=front;
        if(isEmpty())
        {
            cout<<"queue is empty"<<endl;
            return -1;
        }
        int data=curr->data;
        front=curr->next;
        delete curr;
        noOfElement--;
        return data;
    }

    void display()
    {
        node*curr = front;
        while(curr!=NULL)
        {
            cout<<curr->data<<endl;
            curr=curr->next;

        }
    }
    
};

int main()
{
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.display();
    q.deQueue();
    q.display();


}