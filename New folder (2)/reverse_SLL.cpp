#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;
    
    while (curr != nullptr) {
        next = curr->next; // store the next node
        curr->next = prev; // reverse the next pointer
        prev = curr; // move prev to current node
        curr = next; // move current to next node
    }
    
    return prev; // return the new head node
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main() {
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;
    
    // allocate nodes in heap
    head = new Node();
    second = new Node();
    third = new Node();
    
    // assign data values
    head->data = 1;
    second->data = 2;
    third->data = 3;
    
    // connect nodes
    head->next = second;
    second->next = third;
    third->next = nullptr;
    
    cout << "Original linked list: ";
    printList(head);
    
    head = reverse(head);
    
    cout << "\nReversed linked list: ";
    printList(head);
    
    // free memory
    delete head;
    delete second;
    delete third;
    
    return 0;
}
