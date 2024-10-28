#include <iostream>
#include <queue>

using namespace std;

void reverseOdd(queue<int>& q) {
    int n = q.size();
    queue<int> temp;

    // push all odd integers to temp queue in reverse order
    for (int i = 0; i < n; i++) {
        int x = q.front();
        q.pop();
        if (x % 2 == 1) {
            temp.push(x);
        }
        else {
            q.push(x);
        }
    }

    // pop all odd integers from temp and push back to original queue
    while (!temp.empty()) {
        q.push(temp.front());
        temp.pop();
    }
}

int main() {
    queue<int> q;
    q.push(14);
    q.push(13);
    q.push(17);
    q.push(8);
    q.push(4);
    q.push(10);
    q.push(11);
    q.push(4);
    q.push(15);
    q.push(18);
    q.push(19);

    reverseOdd(q);

    // print the modified queue
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
// #include <iostream>

// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// class Queue {
// private:
//     Node* front;
//     Node* rear;

// public:
//     Queue() {
//         front = nullptr;
//         rear = nullptr;
//     }

//     bool isEmpty() {
//         return (front == nullptr);
//     }

//     void enqueue(int x) {
//         Node* temp = new Node;
//         temp->data = x;
//         temp->next = nullptr;
//         if (isEmpty()) {
//             front = rear = temp;
//         }
//         else {
//             rear->next = temp;
//             rear = temp;
//         }
//     }

//     int dequeue() {
//         int x = -1;
//         if (!isEmpty()) {
//             Node* temp = front;
//             x = temp->data;
//             front = front->next;
//             delete temp;
//         }
//         return x;
//     }

//     void reverseOdd() {
//         int n = 0, x;
//         Node* p = front;
//         while (p) {
//             n++;
//             p = p->next;
//         }

//         int* a = new int[n];
//         p = front;
//         for (int i = 0; i < n; i++) {
//             x = p->data;
//             p = p->next;
//             a[i] = x;
//         }

//         for (int i = 0, j = n - 1; i < j; i++, j--) {
//             if (a[i] % 2 == 1) {
//                 while (a[j] % 2 == 0 && j > i) {
//                     j--;
//                 }
//                 int temp = a[i];
//                 a[i] = a[j];
//                 a[j] = temp;
//             }
//         }

//         front = rear = nullptr;
//         for (int i = 0; i < n; i++) {
//             enqueue(a[i]);
//         }
//         delete[] a;
//     }

//     void display() {
//         Node* p = front;
//         while (p) {
//             cout << p->data << " ";
//             p = p->next;
//         }
//         cout << endl;
//     }
// };

// int main() {
//     Queue q;
//     q.enqueue(14);
//     q.enqueue(13);
//     q.enqueue(17);
//     q.enqueue(8);
//     q.enqueue(4);
//     q.enqueue(10);
//     q.enqueue(11);
//     q.enqueue(4);
//     q.enqueue(15);
//     q.enqueue(18);
//     q.enqueue(19);

//     q.reverseOdd();
//     q.display();

//     return 0;
// }



