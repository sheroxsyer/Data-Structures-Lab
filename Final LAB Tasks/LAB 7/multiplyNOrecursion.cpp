// Write a function for mutliply(a, b), where a and b are both positive integers, but you can only use the +
// or − operators.
// Note: Use Recursion to solve the above problem.
#include<iostream>
using namespace std;
int multiply_NO_Recusion(int x, int y) {
    if (y == 1) 
    {
        return x;
    }
     else if (x == 1) {
        return y;
    }
     else if (y < 0) {
        return -multiply_NO_Recusion(x, -y);
    } 
    else {
        return x + multiply_NO_Recusion(x, y - 1);
    }
}

// int multiply_NO_Recusion(int x,int y)
// {
//     int ans;
//     ans =0;
//     if(y == 1)
//     {
//         return x;
//     }
//     else if (x == 1) {
//         return y;
//     } else if (y < 0) {
//         return -multiply_NO_Recusion(x, -y);
//     } else {
//         return x + multiply_NO_Recusion(x, y - 1);
//     }
//     // for(int i=0;i<y;i++)
//     // {
//     //     ans += x;
        
//     // }
//     // return x;
// }
int main()
{
    int x;
    int y;
    int result;
    cout<<"Enter first no:"<<endl;
    cin>>x;
    cout<<"Enter second no:"<<endl;
    cin>>y;
    result=multiply_NO_Recusion(x,y);
    cout<<"Result is "<<result<<endl;
    return 0;
}























