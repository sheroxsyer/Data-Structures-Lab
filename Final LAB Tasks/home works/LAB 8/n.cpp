#include<iostream> 
using namespace std; 
   
class Queue { 
    public:
    int rear, front; 
    
    int size; 
    int *circularQueue; 
   
    Queue(int sz) { 
       front = rear = -1; 
       size = sz; 
       circularQueue = new int[sz]; 
    } 
   void enQueue(int elem); 
    int deQueue(); 
    void displayQueue(); 
}; 
   
void Queue::enQueue(int elem) 
{ 
    if ((front == 0 && rear == size-1) || (rear == (front-1)%(size-1)))  { 
        cout<<"\nQueue is Full"<<endl; 
        return; 
    } 
    else if (front == -1) {     
         front = rear = 0; 
        circularQueue[rear] = elem; 
    } 
   else if (rear == size-1 && front != 0) { 
        rear = 0; 
        circularQueue[rear] = elem; 
    } 
    else {  
        rear++; 
        circularQueue[rear] = elem; 
    } 
} 
int Queue::deQueue() 
{ 
    if (front == -1)  { 
        cout<<"\nQueue is Empty"<<endl; 
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
  
void Queue::displayQueue() 
{ 
    if (front == -1) { 
        cout<<"\nQueue is Empty"<<endl; 
        return; 
    } 
    cout<<"\nCircular Queue elements: "<<endl; 
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
    Queue pq(5); 
   
    pq.enQueue(2); 
    pq.enQueue(4); 
    pq.enQueue(6); 
    pq.enQueue(8); 
    
    pq.displayQueue(); 
   
    cout<<"Element Dequeued = "<<pq.deQueue()<<endl; 
    cout<<"Element Dequeued = "<<pq.deQueue()<<endl; 
   
    pq.displayQueue(); 
   
    pq.enQueue(10); 
    pq.enQueue(12); 
    pq.enQueue(14); 
   
    pq.displayQueue(); 
   
    pq.enQueue(10); 
    return 0; 
}