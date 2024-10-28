#include <iostream>

using namespace std;

// Function to check if the given binary tree represented by an array is a heap
bool isHeap(int arr[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int parentIndex = (i - 1) / 2;

        if (arr[i] < arr[leftChild]) {
            return false;
        }

        if (rightChild < n && arr[i] < arr[rightChild]) {
            return false;
        }

        if (i != 0 && arr[i] > arr[parentIndex]) {
            return false;
        }
    }

    return true;
}

// Sample usage
int main() {
    int heapArr[] = {9, 6, 7, 2, 3, 1, 5};
    int n = sizeof(heapArr) / sizeof(heapArr[0]);

    if (isHeap(heapArr, n)) {
        cout << "The given binary tree is a heap." << endl;
    } else {
        cout << "The given binary tree is not a heap." << endl;
    }

    return 0;
}
