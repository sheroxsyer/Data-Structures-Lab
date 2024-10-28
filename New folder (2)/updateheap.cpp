#include <iostream>

using namespace std;

// Function to reorganize the heap after updating a node value
void heapify(int arr[], int n, int i) {
    int largest = i;  // Initialize the largest as root
    int leftChild = 2 * i + 1;  // Left child
    int rightChild = 2 * i + 2;  // Right child

    // Check if the left child is larger than the root
    if (leftChild < n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }

    // Check if the right child is larger than the current largest
    if (rightChild < n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }

    // If the largest is not the root, swap values and recursively heapify
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to update the value of a node in the heap
void updateValue(int arr[], int n, int position, int newValue) {
    if (position >= n) {
        cout << "Invalid position!" << endl;
        return;
    }

    // Update the value at the given position
    arr[position] = newValue;

    // Reorganize the heap to maintain the heap property
    int parent = (position - 1) / 2;
    if (position > 0 && arr[parent] < arr[position]) {
        // If the parent value is smaller, perform bottom-up heapify
        while (position > 0 && arr[parent] < arr[position]) {
            swap(arr[position], arr[parent]);
            position = parent;
            parent = (position - 1) / 2;
        }
    } else {
        // If the parent value is larger or it's the root, perform top-down heapify
        heapify(arr, n, position);
    }
}

// Sample usage
int main() {
    int heapArr[] = {9, 6, 7, 2, 3, 1, 5};
    int n = sizeof(heapArr) / sizeof(heapArr[0]);

    cout << "Original heap: ";
    for (int i = 0; i < n; i++) {
        cout << heapArr[i] << " ";
    }
    cout << endl;

    updateValue(heapArr, n, 2, 10);

    cout << "Updated heap: ";
    for (int i = 0; i < n; i++) {
        cout << heapArr[i] << " ";
    }
    cout << endl;

    return 0;
}
