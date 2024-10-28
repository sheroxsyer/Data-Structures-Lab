#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
};

void duplicateNodes(Node* front) {
    Node* current = front;
    while (current != nullptr) {
        int value = current->value;
        for (int i = 0; i < value - 1; i++) {
            Node* newNode = new Node;
            newNode->value = value;
            newNode->next = current->next;
            current->next = newNode;
            current = newNode;
        }
        current = current->next;
    }
}

void printQueue(Node* front) {
    while (front != nullptr) {
        cout << front->value << " ";
        front = front->next;
    }
    cout << endl;
}

int main() {
    Node* front = new Node;
    Node* second = new Node;
    Node* third = new Node;
    front->value = 3;
    second->value = 4;
    third->value = 5;
    front->next = second;
    second->next = third;
    third->next = nullptr;
    
    duplicateNodes(front);
    printQueue(front);
    
    return 0;
}
