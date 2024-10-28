#include <iostream>
#include <cmath>

using namespace std;

// Structure for a node in the circular linked list
struct Node {
    int data;
    Node* next;
};

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1)
        return false;

    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

// Function to count combinations of prime-sum pairs
int countPrimeSumPairs(Node* head) {
    if (head == nullptr)
        return 0;

    Node* primeNode = head;
    int count = 0;

    // Traverse the circular linked list
    do {
        if (isPrime(primeNode->data)) {
            Node* secondNode = primeNode->next;
            
            // Check combinations with subsequent nodes
            while (secondNode != primeNode) {
                if (isPrime(secondNode->data) && isPrime(primeNode->data + secondNode->data))
                    count++;
                secondNode = secondNode->next;
            }
        }
        primeNode = primeNode->next;
    } while (primeNode != head);

    return count;
}

// Sample usage
int main() {
    // Create a circular linked list
    Node* head = new Node();
    head->data = 2;

    Node* node3 = new Node();
    node3->data = 3;
    head->next = node3;

    Node* node5 = new Node();
    node5->data = 5;
    node3->next = node5;

    Node* node7 = new Node();
    node7->data = 7;
    node5->next = node7;

    Node* node11 = new Node();
    node11->data = 11;
    node7->next = node11;

    node11->next = head;

    // Count the combinations of prime-sum pairs
    int count = countPrimeSumPairs(head);

    cout << "Number of combinations: " << count << endl;

    // Clean up the memory
    delete node11;
    delete node7;
    delete node5;
    delete node3;
    delete head;

    return 0;
}
