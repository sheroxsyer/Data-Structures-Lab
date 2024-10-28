#include <iostream>

void find_mode(int arr[], int size) {
    int mode_count = 0;
    int *mode_ptr = nullptr;

    for (int i = 0; i < size; i++) {
        int count = 1;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] == arr[i]) {
                count++;
            }
        }

        if (count > mode_count) {
            mode_count = count;
            mode_ptr = &arr[i];
        }
    }

    if (mode_ptr != nullptr) {
        std::cout << "The mode of the array is " << *mode_ptr << std::endl;
    } else {
        std::cout << "There is no mode in the array." << std::endl;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 4, 5, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    find_mode(arr, size);

    return 0;
}
