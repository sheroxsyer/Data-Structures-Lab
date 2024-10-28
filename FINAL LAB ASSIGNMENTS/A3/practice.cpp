// #include <iostream>
// #include <stack>
// #include <string>

// using namespace std;

// bool isMatchingPair(char opening, char closing) 
// {
//     if (opening == '(' && closing == ')')
//         return true;
//     else if (opening == '{' && closing == '}')
//         return true;
//     else if (opening == '[' && closing == ']')
//         return true;
//         else
//     return false;
// }

// int findError(string s) {
//     stack<char> st;
//     int n = s.length();

//     for (int i = 0; i < n; i++) 
//     {
//         if (s[i] == '(' || s[i] == '{' || s[i] == '[') 
//         {
//             st.push(s[i]);
//         } 
//         else if (s[i] == ')' || s[i] == '}' || s[i] == ']') 
//         {
//             if (st.empty() || !isMatchingPair(st.top(), s[i])) 
//             {
//                 return i + 1;
//             } 
//             else 
//             {
//                 st.pop();
//             }
//         }
//     }

//     if (st.empty()) 
//     {
//         return 0; // Success
//     } else 
//     {
//         while (!st.empty() && (st.top() == '(' || st.top() == '{' || st.top() == '[')) 
//         {
//             st.pop();
//         }
//         if (st.empty()) 
//         {
//             return 0; // Success
//         } 
//         else
//         {
//             return n - st.size() + 1; // Return index of first unmatched opening bracket
//         }
//     }
// }

// int main() 
// {
//     string s;
//     cin >> s;
//     int error = findError(s);
//     if (error == 0) 
//     {
//         cout << "Success" << endl;
//     } 
//     else 
//     {
//         cout << error << endl;
//     }
//     return 0;
// }



#include <iostream>
#include <string>
using namespace std;

class Stack
{
    int* arr;
    int size;
    int len;
    int* curr;
    int top;

public:
    Stack()
    {
        size = 10;
        len = 0;
        arr = new int[size];
        top = -1;
    }

    void print()
    {
        // Fix: add a check to make sure the stack is not empty before printing
        while (!IsEmpty())
        {
            cout << arr[top] << " ";
            pop();
        }
        cout << endl;
    }

    void push(int val)
    {
        if (top == size - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            top++;
            arr[top] = val;
            len++;
        }
    }

    string removeDuplicates(string s)
    {
        int n = s.length();
        Stack st;
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            if (!st.IsEmpty() && st.peek() == c)
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        string result = "";
        while (!st.IsEmpty())
        {
            result = st.pop() + result;
        }
        return result;
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

    int findError(string s)
    {
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
            return 0;
        }
        else
        {
            while (!st.IsEmpty() && (st.peek() == '(' || st.peek() == '{' || st.peek() == '['))
            {
                st.pop();
            }
            if (st.IsEmpty())
            {
                return 0;
            }
            else
            {
                // Fix: change "st.size()" to "len" since there is no "size" member function in the Stack class
                return n - len + 1;
            }
        }
    }

    char pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            int x = arr[top];
            top--;
            len--;
            return x;
        }
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            return arr[top];
        }
    }

    bool IsEmpty()
    {
        if (top == -1)
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

 string s1 = "abbaca";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << s.removeDuplicates(s1) << endl;

    string s2 = "azkkzy";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << s.removeDuplicates(s2) << endl;


    string s;
    cout<<"enter string"<<endl;
    cin >> s;
    int error = s.findError(s);
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