#include<iostream>
#include<string>
#include<conio.h>
using namespace std;
struct Node
{
    string name;
    int roll_no;
    float cgpa;

};

class Queue{
    private:
    Node *arr;
    int size;
    int rear, front; // Index
    int noOfElemets;
    Node*name;
    Node*roll_no;
    Node*cgpa;
    
   
    public:
    Queue(int size){
        this->size= size;
        arr= new Node[size];
        rear= -1, front=-1,noOfElemets=0 ;
        Node*name;
    Node*roll_no;
    Node*cgpa;

    }
    ~Queue(){
        delete []arr;
    }
    void enqueue(int val ){//,string name,int roll_no,float cgpa
        if(rear== size-1){
            cout<<"Queue OverFlow"<<endl;
            return;
        }
        
        

        if (front == - 1)
              front = 0;
        arr[++rear].cgpa =val;
        // arr[++rear] =name;
        // arr[++rear] =roll_no;
        // arr[++rear] =cgpa;

        noOfElemets++;
    }
   
    int dequeue()
    {
        if (front == - 1) {
              cout<<"Queue Underflow ";
              return -1;
           }
        else {
          cout<<"Element deleted from queue is : "<< arr[front] <<endl;
         return arr[front++];
           }
    }
    void Record()
    {
        
    }
    void display(){
        if (front == - 1)
               cout<<"Queue is empty"<<endl;
           else
           {
              cout<<"Queue elements are : ";
              for (int i = front; i <= rear; i++)
              cout<<arr[i]<<" ";
                cout<<endl;
               }
    }
};
int main (){
    string name;
    int roll_no;
    float cgpa;
    cout<<"Enter name "<<endl;
        cin>>name;
        cout<<"Enter roll no "<<endl;
        cin>>roll_no;
        cout<<"Enter CGPA"<<endl;
        cin>>cgpa;

        cout<<"Queue Elements are : '\n' << Name "<<name<<'\t'<<"Roll no : '\t'"<<roll_no<<'\t'<<"CGPA : '\n'"<<cgpa<<endl;
    Queue q1(5);
    
    q1.enqueue(1);//,name,roll_no,cgpa
    // q1.enqueue(2);
    // q1.enqueue(3);
    // q1.enqueue(4);
    // q1.enqueue(5);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.display();
    return 0;
}