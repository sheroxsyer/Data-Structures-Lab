#include <iostream>
#include <cmath>

using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    int sqrtn = sqrt(n);
    for (int i = 2; i <= sqrtn; i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

// Function to count the number of combinations of adding two integers at prime positions in the circular linked list that result in a prime number
int countPrimeCombinations(Node* head) {
    if (head == nullptr) {
        return 0;
    }

    int count = 0;
    Node* p = head;
    Node* q = head->next;

    // Traverse the linked list
    do {
        // Check if the first node is prime
        if (isPrime(p->data)) {
            Node* r = q->next;
            // Traverse the rest of the list
            while (r != p && r != head) {
                // Check if the second node is prime
                if (isPrime(q->data)) {
                    // Calculate the sum and check if it's prime
                    int sum = p->data + q->data;
                    if (isPrime(sum)) {
                        count++;
                    }
                }
                q = q->next;
                r = r->next;
            }
        }
        p = p->next;
        q = p->next;
    } while (p->next != head);

    return count;
}

// Main function
int main() {
    // Create a circular linked list
    Node* head = new Node(7);
    head->next = new Node(4);
    head->next->next = new Node(5);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(6);
    head->next->next->next->next->next = head;

    // Count the number of combinations
    int count = countPrimeCombinations(head);
    cout << "Number of combinations of adding two integers at prime positions in the circular linked list that result in a prime number: " << count << endl;

    return 0;
}
