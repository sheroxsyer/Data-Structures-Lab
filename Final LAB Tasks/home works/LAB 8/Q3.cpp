#include<iostream> 
using namespace std; 
   
class Queue { 
    public:
    int rear, front; 
    
    int size; 
    int *circularQueue; 
   
    Queue(int s) { 
       front = rear = -1; 
       size = s; 
       circularQueue = new int[s]; 
    } 
   void enQueue(int val); 
    int deQueue(); 
    void displayQueue();
    int isfull();
    int isEmpty(); 
}; 
   
void Queue::enQueue(int val) 
{ 
    if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))  { 
        cout<<"Queue over loaded"<<endl; 
        return; 
    } 
    else if (front == -1) {     
         front = rear = 0; 
        circularQueue[rear] = val; 
    } 
   else if (rear == size-1 && front != 0) { 
        rear = 0; 
        circularQueue[rear] = val; 
    } 
    else {  
        rear++; 
        circularQueue[rear] = val; 
    } 
} 
int Queue::deQueue() 
{ 
    if (front == -1)  { 
        cout<<"Queue is Empty"<<endl; 
        return -1; 
    } 
   
    int data = circularQueue[front]; 
    circularQueue[front] = -1; 
    if (front == rear)  { 
        front = -1; 
        rear = -1; 
    } 
    else if (front == size-1) 
        front = 0; 
    else
        front++; 
   
    return data; 
} 
int Queue::isEmpty()
{
	return front == NULL;
}
int Queue :: isfull()
	{
		return rear == NULL;
	}

  
void Queue::displayQueue() 
{ 
    if (front == -1) { 
        cout<<"Queue is Empty"<<endl; 
        return; 
    } 
    cout<<"your  Queue is: "<<endl; 
    if (rear = front) { 
        for (int i = front; i = rear; i++) 
            cout<<circularQueue[i]<<" "<<endl; 
    } 
    else  { 
        for (int i = front; i < size; i++) 
            cout<<circularQueue[i]<<" "<<endl; 
   
        for (int i = 0; i = rear; i++) 
            cout<<circularQueue[i]<<" "<<endl; 
    } 
} 
   
int main() 
{ 
    Queue q(5); 
   
    q.enQueue(1); 
    q.enQueue(2); 
    q.enQueue(3); 
    q.enQueue(4); 
    
    q.displayQueue(); 
   
    cout<<" Dequeued = "<<q.deQueue()<<endl; 
    cout<<" Dequeued = "<<q.deQueue()<<endl; 
   
    q.displayQueue(); 
   
    q.enQueue(0); 
    q.enQueue(2); 
    q.enQueue(4); 
   
    q.displayQueue(); 
   
    q.enQueue(10); 
    return 0; 
}