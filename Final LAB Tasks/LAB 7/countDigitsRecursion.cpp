#include <iostream>
using namespace std;

int countDigits_Recursion(int n) {
    if (n == 0) 
    { 
        return 0;
    }
     else 
     { 
        return countDigits_Recursion(n/10) + 1;
    }
}

int main() {
    int n = 789456;
    cout<<"THis number "<< n <<"contains  "<<countDigits_Recursion(n)<<"digits"<<endl;
    return 0;
}
