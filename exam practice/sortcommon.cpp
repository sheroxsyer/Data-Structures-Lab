#include <iostream>
using namespace std;

int* sortedIntersect(int* arr1, int size1, int* arr2, int size2) {
    int* result = new int[min(size1, size2)];
    int* p1 = arr1 + size1 - 1; // pointer to last element of arr1
    int* p2 = arr2 + size2 - 1; // pointer to last element of arr2
    int* pr = result; // pointer to first element of result
    
    while (p1 >= arr1 && p2 >= arr2) {
        if (*p1 == *p2) {
            *pr++ = *p1; // add common element to result array
            p1--; // move p1 to next element
            p2--; // move p2 to next element
        } else if (*p1 > *p2) {
            p1--; // move p1 to next element
        } else {
            p2--; // move p2 to next element
        }
    }
    
    return result;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};
    int* result = sortedIntersect(arr1, 5, arr2, 5);
    int size = sizeof(result) / sizeof(result[0]);
    
    for (int i = 0; i < size; i++) {
        cout << result[i] << " ";
    }
    
    delete[] result;
    return 0;
}
