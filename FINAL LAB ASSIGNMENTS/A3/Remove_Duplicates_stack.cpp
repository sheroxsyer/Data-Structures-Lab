#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // Maximum size of the stack

class Stack {
private:
    char arr[MAX_SIZE];
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(char c) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = c;
    }
    char pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return '\0';
        }
        return arr[top--];
    }
    char peek() {
        if (top < 0) {
            cout << "Stack is Empty" << endl;
            return '\0';
        }
        return arr[top];
    }
    bool isEmpty() {
        return top < 0;
    }
};

string removeDuplicates(string s) {
    int n = s.length();
    Stack st;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (!st.isEmpty() && st.peek() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }
    string result = "";
    while (!st.isEmpty()) {
        result = st.pop() + result;
    }
    return result;
}

int main() {
    string s1 = "abbaca";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << removeDuplicates(s1) << endl;

    string s2 = "azkkzy";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << removeDuplicates(s2) << endl;

    return 0;
}
