#include <iostream>
using namespace std;
int main()
{
    int*p = NULL;
    p = new(nothrow) int;
    if(!p)
    cout<<"allocation of memory failed";
    else{
        *p = 29;
        cout<<"value of p :"<<*n<<endl;


    }
    float*r = new float(75.25);
    cout<<"value of r:"<<*r<<endl;
    int n= 5;
    int *q = new(nothrow) int[n];
    if (!q)
    cout<<"allocation of memory failed";
    else
    {
        for(int i = 0;i<n;i++)
        q[i] = i+1;
        cout<<"value stored in block of memory using index:";
        for (int i = 0;i<n;i++)
        cout<<endl<<"value stored in block of memory using ptr:";
        for(int i =0;i<n;i++)
        {
            cout<<*q<<" ";
            q= q+1;

        }
    }
    delete p;
    delete r;
    delete[] q;
    return 0;
}
