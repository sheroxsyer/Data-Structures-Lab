#include <iostream>

using namespace std;

// Doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
};

// Function to add a new node at the end of the list
void addNode(Node** head, int data) {
    // Allocate new node and initialize its data
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    // Traverse the list to find the last node
    Node* lastNode = *head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    // Add the new node after the last node
    lastNode->next = newNode;
    newNode->prev = lastNode;
}

// Function to count the number of nodes in the list
int countNodes(Node* head) {
    int count = 0;

    // Traverse the list and increment the count for each node
    Node* currentNode = head;
    while (currentNode != NULL) {
        count++;
        currentNode = currentNode->next;
    }

    return count;
}

// Driver program
int main() {
    Node* head = NULL;

    // Add some nodes to the list
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);

    // Count the number of nodes in the list and print the result
    int nodeCount = countNodes(head);
    cout << "Number of nodes in the list: " << nodeCount << endl;

    return 0;
}
