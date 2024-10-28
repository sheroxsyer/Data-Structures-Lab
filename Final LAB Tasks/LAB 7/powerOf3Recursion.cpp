#include <iostream>
using namespace std;

bool Check_Power_3(int Number) {
    //check for valid number
    if (Number <= 0) 
    {
        return false;
    }
     else if (Number == 1) 
     {
        return true;
    }
    //check for divisibility
     else if (Number % 3 == 0) 
     {
        //recursively division
        return Check_Power_3(Number/3);
    }
     else 
     {
        return false;
    }
}

int main() {
    int Number;
    cout << "Enter an integer: ";
    cin >> Number;
    
    if (Check_Power_3(Number)) {
        cout << Number << " True" << endl;
    } else {
        cout << Number << " False" << endl;
    }
    return 0;
}
