// d) Provide array base implementation of circular queue. Also create a driver function
// e) Functions:
// f) Enqueue()
// g) Dequeue()
// h) Isempty()
// i) Isfull()

#include<iostream>
using namespace std;

class CircularQueue
{
    private:
    int *arr;
    int *rear;
    int *front;
    int size;
    int noOfElements;

    public:
    CircularQueue(int s)
    {
        arr=new int[s];
        size=s;
        noOfElements=0;
        front=NULL;
        rear=NULL;
    }

    void Enqueue(int v);
    int Dequeue();
    bool Isempty();
    bool Isfull(); 
    void print();
};

int main()
{
    int s=0;
    cout<<"Enter queue size."<<endl;
    cin>>s;
    CircularQueue obj(s);

    int option; 
    

    do
    {
        cout<<"Press 1 to call Enqueue function."<<endl;
        cout<<"Press 2 to call Dequeue function."<<endl;
        cout<<"Press 3 to call isfull function."<<endl;
        cout<<"Press 4 to call isempty function."<<endl;
        cout<<"Press 5 to call print function."<<endl;
        cout<<"Press 0 to exit."<<endl;

        cout<<"Enter option number."<<endl;
        cin>>option;

        switch (option)
        {
        case 1:
            int value;
            cout<<"Enter value you want to Enqueue."<<endl;
            cin>>value;
            obj.Enqueue(value);
            break;

        case 2:
            int save;
            save=obj.Dequeue();
            if(save==-1)
                cout<<"Queue is empty there is nothing to delete."<<endl;
            else    
            {  
                cout<<"Dequeue Value = "<<save<<endl;
            }
            break;

        case 3:
        if(obj.Isfull())
            cout<<"Queue is full."<<endl;    
        else
            cout<<"Queue is not full."<<endl;
        break;

        case 4:
        if(obj.Isempty())
            cout<<"Queue is empty."<<endl;    
        else
            cout<<"Queue is not empty."<<endl;
        break;

        case 5:
            obj.print();
            cout<<endl;
            break;

        default:
            break;
        }
    } while (option!=0);

    return 0;
}

void CircularQueue::Enqueue(int v)
{
    if(Isfull())
    {
        cout<<"Queue is full. More elements cannot be added."<<endl;
        return ;
    }

    if(front==NULL && rear==NULL)
    {
        front=arr;
        rear=arr;
        *rear=v; //ask sir arr or rear
        noOfElements++; 
        return;
    }

    if(rear==arr+size-1)
    {
        rear=arr;
        *rear=v;
        noOfElements++;
    }
    else
    {
        rear++;
        *rear=v;
        noOfElements++;
    }

}

int CircularQueue::Dequeue()
{
    if(Isempty())
    {
        return -1;
    }
    int s=*front;
    front++;
    noOfElements=noOfElements-1;
    return s;
}

bool CircularQueue::Isempty()
{
    if(rear==NULL && front==NULL || noOfElements==0)
        return true;
    else
        return false;
}

bool CircularQueue::Isfull()
{
    if(noOfElements==size)
        return true;
    else
        return false;    
}

void CircularQueue::print()
{
    int *f=front;
    int *r=rear;

    if(f==arr+size-1 && f==r)
    {
        cout<<*f<<" ";
        return;
    }

    if(f==arr+size-1 && f!=r)
    {
        cout<<*f<<" ";
        f=arr;
    }

    while(f!=r)
    {
        cout<<*f<<" ";
        f++;
    }
    cout<<*f;
}