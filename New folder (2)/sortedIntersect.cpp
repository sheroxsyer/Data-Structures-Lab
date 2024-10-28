#include <iostream>

using namespace std;

int* sortedIntersect(int* arr1, int* arr2, int size1, int size2) {
    int* result = new int[min(size1, size2)];
    int* ptr1 = arr1 + size1 - 1;
    int* ptr2 = arr2 + size2 - 1;
    int* ptr3 = result;
    while (ptr1 >= arr1 && ptr2 >= arr2) {
        if (*ptr1 == *ptr2) {
            *ptr3 = *ptr1;
            ptr1--;
            ptr2--;
            ptr3++;
        } else if (*ptr1 > *ptr2) {
            ptr1--;
        } else {
            ptr2--;
        }
    }
    int* ptr4 = result;
    int* ptr5 = result + (ptr3 - result) - 1;
    while (ptr4 < ptr5) {
        int temp = *ptr4;
        *ptr4 = *ptr5;
        *ptr5 = temp;
        ptr4++;
        ptr5--;
    }
    return result;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 4, 5, 6, 7};
    int* result = sortedIntersect(arr1, arr2, 5, 5);
    for (int i = 0; i < 3; i++) {
        cout << result[i] << " "; // output: 5 4 3
    }
    delete[] result;
    return 0;
}
