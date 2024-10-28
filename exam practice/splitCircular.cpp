#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void splitList(Node* head, Node*& frontRef, Node*& backRef) {
    Node* slow = head;
    Node* fast = head;
    
    // move fast pointer two steps and slow pointer one step
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    // if there are even number of nodes, move the fast pointer one more step
    if (fast->next->next == head) {
        fast = fast->next;
    }
    
    // set the front and back pointers to the head and slow pointers
    frontRef = head;
    backRef = slow->next;
    
    // set the next pointer of the last node to the front of the list
    fast->next = backRef;
    
    // set the next pointer of the last node in the back list to the head of the list
    slow->next = frontRef;
}

void printList(Node* head) {
    Node* current = head;
    
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
}

int main() {
    Node* head = nullptr;
    Node* front = nullptr;
    Node* back = nullptr;
    
    // allocate nodes in heap
    head = new Node();
    head->data = 1;
    
    Node* second = new Node();
    second->data = 2;
    head->next = second;
    
    Node* third = new Node();
    third->data = 3;
    second->next = third;
    
    Node* fourth = new Node();
    fourth->data = 4;
    third->next = fourth;
    
    Node* fifth = new Node();
    fifth->data = 5;
    fourth->next = fifth;
    
    Node* sixth = new Node();
    sixth->data = 6;
    fifth->next = sixth;

    Node* seventh = new Node();
    seventh->data = 7;
    sixth->next = seventh;
    
    // make the list circular
    seventh->next = head;
    
    cout << "Original circular linked list: ";
    printList(head);
    
    splitList(head, front, back);
    
    cout << "\nFront half of the circular linked list: ";
    printList(front);
    
    cout << "\nBack half of the circular linked list: ";
    printList(back);
    
    // free memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;
    delete sixth;
    delete seventh;
    return 0;
}
