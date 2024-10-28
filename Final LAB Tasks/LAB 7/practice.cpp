#include <iostream>
using namespace std;

bool isPowerOfThree(int n) {
    if (n <= 0) {
        return false;
    } else if (n == 1) {
        return true;
    } else if (n % 3 == 0) {
        return isPowerOfThree(n/3);
    } else {
        return false;
    }
}

int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;
    if (isPowerOfThree(n)) {
        cout << n << " is a power of three." << endl;
    } else {
        cout << n << " is not a power of three." << endl;
    }
    return 0;
}
