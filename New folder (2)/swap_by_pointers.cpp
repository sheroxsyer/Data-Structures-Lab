// //program to swap two values by passing pointers as arguments to the function.

// #include<iostream>
// using namespace std;
// void swap(int *,int*);
// int main()
// {
//     int a ,b;
//     cout<<"a = ";
//     cin>>a;
//     cout<<"b = ";
//     cin>>b;
//     swap(&a,&b);
//     {
//         cout<<"after change a ="<<a<<endl;
//         cout<<"after change b ="<<b<<endl;
//         return 0;
//     }
// }
//     void swap(int *x,int *y)
//     {
//         int t;
//         t = *x;
//         *x = *y;
//         *y = t;


//     }





#include<iostream>
using namespace std;
int main()
{
	int Arr[100],n,i,temp;
	cout<<"Enter number of elements you want to insert ";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter element "<<i+1<<":";
		cin>>Arr[i];
	}
	temp=Arr[0];
	Arr[0]=Arr[n-1];
	Arr[n-1]=temp;
	cout<<"\nArray after swapping"<<endl;
	for(i=0;i<n;i++)
		cout<<Arr[i]<<" ";
	return 0;
}