#include<iostream>
using namespace std;
int main()
{
    //declaring array and assign size
    int arr[5];
    int min,max;
    //Enter values
    cout<<"Enter values in array:"<<endl;
    for(int i=0;i<=4;i++)
    {
        cin>>arr[i];
    }
    //printing array 
    cout<<"Array elements are:"<<endl;
    for(int i=0;i<=4;i++)
    {
        cout<<arr[i]<<"\t";

    }
    //To find second max of aray 
    max=arr[0];
    cout<<endl;
    
    for(int i=0;i<=4;i++)
    {
        if(arr[i]>max)
        {
        max=arr[i];
        }
    }
    
    cout<<"The largest element in array is :"<<max<<endl;

    return 0;

}