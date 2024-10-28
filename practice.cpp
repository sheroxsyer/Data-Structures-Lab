#include <iostream>
using namespace std;

// Function to build a Min Heap from an array
void buildMinHeap(int arr[], int n) {
    // Starting from the last non-leaf node and heapifying all the subtrees
    for (int i = (n / 2) - 1; i >= 0; i--) {
        int parent = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        // If left child is smaller than parent, swap them
        if (leftChild < n && arr[leftChild] < arr[parent]) {
            swap(arr[leftChild], arr[parent]);
        }

        // If right child is smaller than parent, swap them
        if (rightChild < n && arr[rightChild] < arr[parent]) {
            swap(arr[rightChild], arr[parent]);
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Building the Min Heap from the given array
    buildMinHeap(arr, n);

    cout << "The Min Heap is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
