#include <iostream>
using namespace std;

void find_mode(int* arr, int size) {
    int mode_count = 0;
    int* mode_ptr = nullptr;

    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > mode_count) {
            mode_count = count;
            mode_ptr = &arr[i];
        }
    }

    if (mode_ptr != nullptr) {
        cout << "The mode is " << *mode_ptr << endl;
    } else {
        cout << "There is no mode ." << endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 4, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    find_mode(arr, size);

    return 0;
}
