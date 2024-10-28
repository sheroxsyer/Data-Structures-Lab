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
  
bool isMatchingPair(char opening, char closing) 
{
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '{' && closing == '}')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
        else
    return false;
}

int findError(const std::string&  s) {
    Stack st;
    int n = s.length();

    for (int i = 0; i < n; i++) 
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
        {
            st.push(s[i]);
        } 
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') 
        {
            if (st.IsEmpty() || !isMatchingPair(st.peek(), s[i])) 
            {
                return i + 1;
            } 
            else 
            {
                st.pop();
            }
        }
    }

    if (st.IsEmpty()) 
    {
        return 0; // Success
    } else 
    {
        while (!st.IsEmpty() && (st.peek() == '(' || st.peek() == '{' || st.peek() == '[')) 
        {
            st.pop();
        }
        if (st.IsEmpty()) 
        {
            return 0; // Success
        } 
        else
        {
            return n - len + 1; // Return index of first unmatched opening bracket
        }
    }
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
//   istream& operator>>(istream& in, Stack& s)
// {
//     int val;
//     in >> val;
//     s.push(val);
//     return in;
// }

};
int main()
{
 Stack s;
 cout<<"push elements are:"<<endl;
 s.push(1);
 s.push(2);
 cout<<"deleted element 2 from stack"<<endl;
 s.pop();
 s.push(3);
 s.push(4);
 s.push(5);
 
 cout<<endl;

 cout<<"peek element :"<<s.peek();
 cout<<endl;
 s.print();

 cout<<endl;


//     Stack s;
// int val;
// while (cin >> val)
// {
//     s.push(val);
// }
    string str;
cout << "Enter a string: ";
getline(cin, str);
int error = s.findError(str);
    if (error == 0) 
    {
        cout << "Success" << endl;
    } 
    else 
    {
        cout << error << endl;
    }

	
 return 0;
}