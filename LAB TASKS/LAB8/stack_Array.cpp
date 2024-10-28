#include<iostream>
using namespace std;

class stack_Array
{
    
    
    public:
    int top;
    int*arr;
    int size;
        
    stack_Array()
    {
        int s=5;
        
        size=s;
        arr = new int[size];
        top = -1;
        void push(int val);

    }
void push(int val)
{
    if (top == size-1)
    {
        cout<<"stack overflow"<<endl;
    }
    else{
        top++;
        arr[top] = val;
    }
}

int pop()
{
    if (top == -1)
    {
        cout<<"Stack underflow"<<endl;
    }
    else{
        int val = arr[top];
        top--;
        return val;
    }
}

int peek()
{
    int val;
    if (top == -1)
    {
        cout<<"Stack underflow"<<endl;
    }
    else{
        return val;
}
}

bool isEmpty()
{
    if(top < 0)
    {
        cout<<"Stack is empty"<<endl;
        return true;
    }
    else
    {
        return false;
    }
}


void display()
{
    for( int i = top;top>=0;top--)
    {
        cout<<"Your stack is :"<<endl;
        cout<<top;
    }
}
};

int main()
{
    
    class stack_Array s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(6);
    s.push(8);
    //s.push(7);
    cout << s.pop() << " Popped from stack";
    cout<<"Elements present in stack : ";
    cout<<s.peek()<<" ";
        
        s.pop();
    

    return 0;
}
