//Also write a cod to  the following postfix notation to Infix notation. Check for the following
//input.
//abc++

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#include<cmath>

class stackUsingArray // class for stack
{
    private:
    string *arr;
    int top;
    int length;
    int size;

    public:

    stackUsingArray(int s) //constructor
    {
        arr=new string[s];
        top=-1 ;
        size=s;
    }

    //function declaration
    void push(string v);
    string pop();
    bool isfull();
    bool isempty();
    string postfix(char * a); 
    string topV();
};

int main()
{
    stackUsingArray obj(20); // creating stack object

    int expLen=0; // store char array length
    cout<<"Enter expression length."<<endl;
    cin>>expLen;

    char expression[expLen]; //char array that will store our data

    //taking the array from user
    cout<<"Enter expression."<<endl;
    cin>>expression; // why cin.get not working ask sir 

    string j=obj.postfix(expression);

    cout<<"Expression in postfix form = "<<j;
    
}

//this function will push values in the stack
void stackUsingArray::push(string v)
{
    if(isfull())
    {
        cout<<"Stack overflow."<<endl;
        return;
    }
    else
    {
        top=top+1;
        arr[top]=v; 
    }
}

//this function will return the value from the top of the stack 
string stackUsingArray::pop()
{
    if(isempty())
    {
        cout<<"Stack underflow."<<endl;
        return NULL;
    }

    else
    {
        string v=arr[top];
        top--;
        return v;
    }
}

string stackUsingArray::topV()
{
    string vv=arr[top];
    return vv;
}

//return true if the stack is full
bool stackUsingArray::isfull()
{
    if(top==(size-1))
        return true;
    else
        return false;
}

//return true if the stack is empty
bool stackUsingArray::isempty()
{
    if(top==-1)
        return true;
    else
        return false;
}


string stackUsingArray::postfix(char * a)
{
    while(*a!='\0') // traverse through whole character array
    {
        if((*a=='+' || *a=='-' || *a=='/' || *a=='*' || *a=='^'))
        {
            string one=pop();
            string two=pop();
            string opt(1, *a);
            string out=two+opt+one;
            push(out);    
        }   
        else 
        {
            string ch(1, *a);
            push(ch);
        }

        *a++; //inc the pointer


    }

    string f=pop();

    return f;
}