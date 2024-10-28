#include <iostream>
#include <queue>

using namespace std;

// Function to reverse the order of odd integers in the queue
void reverseodd(queue<int>& q) {
    // Create a new queue to store the result
    queue<int> result;

    // Iterate over the original queue
    while (!q.empty()) {
        // If the current element is odd, enqueue it to the front of the result queue
        if (q.front() % 2 != 0) {
            result.push(q.front());
        }
        // Dequeue the current element from the original queue
        q.pop();
    }

    // Enqueue the elements from the original queue back into the result queue in reverse order
    while (!result.empty()) {
        q.push(result.back());
        result.pop();
    }
}

// Driver program
int main() {
    queue<int> q;

    // Enqueue some integers into the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Print the original queue
    cout << "Original queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // Enqueue the integers back into the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Reverse the order of the odd integers in the queue
    reverseodd(q);

    // Print the modified queue
    cout << "Modified queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
