#include<iostream>
using namespace std;
class Queue{
    private:
    int *arr;
    int size;
    int *rear;
    int * front; // Index
    int noOfElemets;
   
    public:
    Queue(int size){
        this->size= size;
        arr= new int[size];
        *rear= -1, front=rear,noOfElemets=0 ;
    }
    ~Queue(){
        delete []arr;
    }
    void enqueue(int val){
        if(*rear== size-1){
            cout<<"Queue OverFlow"<<endl;
            return;
        }
        if (*front == *rear)
              front = 0;
        arr[++*rear] =val;
        noOfElemets++;
    }
   
    int dequeue()
    {
        if (*front == *rear) {
              cout<<"Queue Underflow ";
              return -1;
           }
        else {
          cout<<"Element deleted from queue is : "<< arr[*front] <<endl;
         return arr[*front++];
           }
    }
    void display(){
        if (*front == *rear)
               cout<<"Queue is empty"<<endl;
           else
           {
              cout<<"Queue elements are : '/n' ";
              for (int i = *front; i <= *rear; i++)
              cout<<arr[i]<<" ";
                cout<<endl;
               }
    }
};
int main (){
    Queue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.display();
    return 0;
}