#include <iostream>

using namespace std;

// Definition of a singly linked list node
struct ListNode {
    int val;
    ListNode* next;
    
    ListNode(int x) : val(x), next(nullptr) {}
};

// Recursive function to find the middle node of a singly linked list
ListNode* findMiddle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to insert a new node at the beginning of a linked list
void insertNode(ListNode*& head, int value) {
    ListNode* newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
}

// Function to display the linked list
void displayList(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr->val << " -> ";
        curr = curr->next;
    }
    cout << "null" << endl;
}

int main() {
    ListNode* head = nullptr;

    // Insert elements into the linked list
    insertNode(head, 5);
    insertNode(head, 4);
    insertNode(head, 3);
    insertNode(head, 2);
    insertNode(head, 1);

    // Display the original linked list
    cout << "Original Linked List: ";
    displayList(head);

    // Find the middle node
    ListNode* middle = findMiddle(head);

    // Display the middle node value
    if (middle != nullptr) {
        cout << "Middle Node Value: " << middle->val << endl;
    } else {
        cout << "Empty Linked List" << endl;
    }

    return 0;
}
