#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};

// Define the Stack class
class Stack {
public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    
    void push(int data) {
        Node* temp = new Node;
        temp->data = data;
        temp->next = top;
        top = temp;
    }

    // Pop the top element from the stack
    void pop() {
        if (!top) {
            cout << "Stack is empty!" << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        delete temp;
    }

    
    bool isEmpty() {
        return (top == nullptr);
    }

    int peek() {
        if (top) {
            return top->data;
        } else {
            return -1;
        }
    }

    // Reverse the order of elements in the stack
    void reverse() {
        // use 3 variables to traverse list
        Node* prev = NULL;
        Node* curr = top;
        Node* next = NULL;

        while (curr) {
            // Store next in list
            next = curr->next;

            // Reverse list
            curr->next = prev;

            // Move the pointers 
            prev = curr;
            curr = next;
        }

        // Update top
        top = prev;
    }

    
    void printStack() {
        Node* temp = top;
        
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

private:
    Node* top;
};

int main() {
    
    Stack s;

    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.printStack();
    s.reverse();
    s.printStack();

    return 0;
}
