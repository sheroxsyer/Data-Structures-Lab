#include <iostream>
using namespace std;

int main() {
    int Number ;
    cout << "Enter a number: ";
    cin >> Number;
    //here we take a variable a and let it equal to number as a loop when it becomes equal to number it teminates
    int a = Number;
    //now we use another while loop to check for some conditons
    while (a > 1 && a % 3 == 0)//this will check a is greater then 1 and same time a is divisible by 3 
     {
        //divide by 3 iteratively till while loop
        a/= 3;
    }
    if (a == 1) {
        cout << Number << " True" << endl;
    } else {
        cout << Number << " False" << endl;
    }
    return 0;
}
