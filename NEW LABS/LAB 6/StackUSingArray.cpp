#include<iostream>
#include<string>
using namespace std;


class Stack
{
 int *arr;
 int size;
 int len;
 int* curr;
 int top;
 public:
  Stack()
  {
   size=10;
   len=0;
   arr=new int [size];
   top=-1;
   
  }
  
  void print()
  {
   while(!IsEmpty())
   {
    cout<<arr[top]<<" ";
    pop();
   }
   cout<<endl;
  }
  void push(int val)
  {
   
   if(top==size-1)
   {
    cout<<"Stack Overflow"<<endl;
   }
   else
   {
    top++;
    arr[top]=val;
    len++;
   }
  }
  //This function takes a string s as input and removes all duplicate from the string using a stack.
  string removeDuplicates(string s) 
  {
    //Getting the length of the input string s using s.length()
    int n = s.length();
    //It creates an instance of the Stack class.
    Stack st;
    //Iterates through each character using a for loop and pushes each character onto the stack
    for (int i = 0; i < n; i++) 
    {
        char c = s[i];
        //check emptiness and duplicates 
        // pushes each character onto the stack if it is not the same as the character on top of the stack.
        if (!st.IsEmpty() && st.peek() == c) 
        {
          //If it is the same, it pops the character from the stack.
            st.pop();
        } 
        else 
        {
            st.push(c);
        }
    }
    //Creates an empty string .
    string result = "";
    while (!st.IsEmpty()) 
    {
      //Pops each character and appends it to the beginning of the result
        result = st.pop() + result;
    }
    return result;
}
  
  char pop()
  {
   if (top==-1)
   {
    cout<<"Stack Underflow"<<endl;
   }
   else
   {
    
    int x=arr[top];
    top--;
    len--;
    return x;
   }
  }
  
  int peek()
  {
   if(top==-1)
   {
    cout<<"Stack Underflow"<<endl;
   }
   else
   {
    
    return arr[top];
    
   }
  }

int Sort(int* arr, int size)
  {
    int n;
    for (int i = 0; i < size - 1; i++)
    {
      for(int j = 0; j < size - i - 1; j++)
      {
        if(arr[j] > arr[j+1])
        {
          n = arr[j];
          arr[j] = arr[j+1];
          arr[j+1] = n;
        }
      }	
    }	
  }

  bool IsEmpty()
  {
   if (top==-1)
   {
    return true;
   }
   else
   {
    return false;
   }
  }
  
};
int main()
{
 Stack stack1,stack2,stack3;
 cout<<"push elements are:"<<endl;
 stack1.push(1);
 stack1.push(2);
 cout<<"deleted element 2 from stack"<<endl;
 stack1.pop();
 stack1.push(3);
 stack1.push(4);
 stack1.push(5);
 
 cout<<endl;

 cout<<"peek element :"<<stack1.peek();
 cout<<endl;
 stack1.print();

 cout<<endl;

 string s1 = "abbaca";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << stack1.removeDuplicates(s1) << endl;

    string s2 = "azkkzy";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << stack1.removeDuplicates(s2) << endl;

	
 return 0;
}