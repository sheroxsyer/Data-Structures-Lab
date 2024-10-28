#include <iostream>

using namespace std;

// Structure for a node in the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Recursive function to count nodes in a doubly linked list
int countNodes(Node* current) {
    // Base case: If the current node is null, return 0
    if (current == nullptr) {
        return 0;
    }
    // Recursive case: Add 1 to the count and recursively count the remaining nodes
    return 1 + countNodes(current->next);
}

// Sample usage
int main() {
    // Create a doubly linked list with 4 nodes
    Node* head = new Node();
    head->data = 1;

    Node* node2 = new Node();
    node2->data = 2;
    head->next = node2;
    node2->prev = head;

    Node* node3 = new Node();
    node3->data = 3;
    node2->next = node3;
    node3->prev = node2;

    Node* node4 = new Node();
    node4->data = 4;
    node3->next = node4;
    node4->prev = node3;

    node4->next = nullptr;

    // Call the countNodes function
    int count = countNodes(head);

    cout << "Number of nodes: " << count << endl;

    // Clean up the memory
    delete node4;
    delete node3;
    delete node2;
    delete head;

    return 0;
}
