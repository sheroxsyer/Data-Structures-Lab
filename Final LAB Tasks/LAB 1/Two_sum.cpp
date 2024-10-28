#include<iostream>
using namespace std;
int main()
{
    //declaring array and assign size
    int arr[5];
    int target=9;
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
    for(int i=0;i<4;i++)
    {
        for (int j=i+1;j<4;j++)
        {
        if(arr[i]+arr[j]==target)
        {
            cout<<"Taget acheived"<<endl;
            
            cout<<"With elements "<<endl<<arr[i]<<"\t"<<arr[j]<<endl;
            cout<<"target ="<<target<<endl;
        
        }
        
        }
    }
    //else{
      //      cout<<"you miss target"<<endl;
        //}
    


    return 0;

}