//Populate an array of your size choice and write a program to find the largest and smallest
//element in that array.

#include <iostream>
using namespace std;
int main()
{

int arr[10];
int i, n,Max,Min;

cout<<"enter size"<<endl;
cin>>n;

cout<<"enter elements"<<endl;
for(int i =0;i<n;i++)
{
    cin>>arr[i];
}
Max= arr[0];
for(int i = 0;i<n;i++)
{
    if(Max < arr[i])
    Max = arr[i];
}
Min= arr[0];
for(int i = 0;i<n;i++)
{
    if(Min > arr[i])
    Min = arr[i];
}
cout<<"Largest is "<<Max<<endl;
cout<<"Smallest is "<<Min <<endl;
}