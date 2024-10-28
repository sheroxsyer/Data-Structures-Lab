#include<iostream>
using namespace std;
class Queue
{
    private:
    int *arr;
    int size;
    int rear;
    int front;
    int noOFelement;
    public:
    Queue(int size)
    {
        this->size=size;
        arr=new int [size];
        
        rear=-1;
        front=-1;
        noOFelement=0;
    }
    ~Queue()
    {
        delete []arr;
    }

    bool isFull()
{
    if(rear== size-1)
    {
        return true;
    }
    else{
        return false;
    }
    
}
bool isEmpty()
{
    if(front == - 1)
    {
        return true;
    }
    else{
        return false;
    }
    
}
void Enqueue(int val)
{
    if(isFull()){
            cout<<"Queue OverFlow"<<endl;
            return;
        }
        if (front == - 1)
              front = 0;
        arr[++rear] =val;
        noOFelement++;
}

void display()
{
    if(front ==-1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else{
        for(int i=front;i<=rear;i++)
        cout<<arr[i]<<endl;
    }


}
int Dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue Underflow"<<endl;
        return 0;
    }
    else{
        int val=arr[front];
        if(front==size-1)
        {
            front =0;

        }
        else{
            front ++;
            noOFelement--;
            return val;
        }
    }

}

};
int main()
{
    Queue q(10);

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.display();
    q.Dequeue();
    q.display();

    return 0;

}









