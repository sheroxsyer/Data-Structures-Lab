//a) Write a C++ program to convert infix notation to postfix notation.
//Use the following expression to evaluate the expression.
//“a+b*(c^d-e)^(f+g*h)-I” (This notation will be passed to the program as a string)

#include<iostream>
using namespace std;
#include<cmath>

class stackUsingArray // class for stack
{
    private:
    int *arr;
    int top;
    int length;
    int size;

    public:

    stackUsingArray(int s) //constructor
    {
        arr=new int[s];
        top=-1 ;
        size=s;
    }

    //function declaration
    void push(int v);
    int pop();
    bool isfull();
    bool isempty();
    void postfix(char * a); 
    char topV();
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

    cout<<"Expression in postfix form = ";
    obj.postfix(expression);

}

//this function will push values in the stack
void stackUsingArray::push(int v)
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
int stackUsingArray::pop()
{
    if(isempty())
    {
        cout<<"Stack underflow."<<endl;
        return -1;
    }

    else
    {
        int v=arr[top];
        top--;
        return v;
    }
}

char stackUsingArray::topV()
{
    char vv=arr[top];
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


void stackUsingArray::postfix(char * a)
{
    while(*a!='\0') // traverse through whole character array
    {
        if(*a=='+' || *a=='-' || *a=='/' || *a=='*' || *a=='^' || *a=='(' || *a==')') 
        {
           if(*a==')')
            {
                char g=pop();
                do{
                    cout<<g;
                    g=pop();
                }while(g!='(');
            }
            else
            {
            while(*a=='+' && ((topV()=='*') || (topV()=='/') || (topV()=='^')))
            {
               char s=pop();
               cout<<s;
            }

            while(*a=='-' &&  ((topV()=='*') || (topV()=='/') || (topV()=='^') || (topV()=='+')))
            {
               char s=pop();
               cout<<s;
            }

            while(*a=='*' &&  ((topV()=='/') || (topV()=='^')))
            {
               char s=pop();
               cout<<s;
            }

            while(*a=='/' &&  (topV()=='^' ))
            {
               char s=pop();
               cout<<s;
            }

           push(*a);
            }
        }

        else // if numbersit will be pushed to the stack
        {
            cout<<*a;
        }

        *a++; //inc the pointer

        if(*a=='\0')
        {
            while(!isempty())
            {
                char s=pop();
                cout<<s;
            }
        }
    }
}