

#include<iostream>
#include<cassert>
using namespace std;
int main()
{
	int arr[5];
	int *pp=arr;
	int pos,n;
	for(int i=0; i<5; i++){
		cout<<"Enter number : "<<endl;
		cin>>n;
		cout<<"Enter position : "<<endl;
		cin>>pos;
		try
		{
			if(pos>5 || pos<0)
			{
				throw(pp[i]);
			}
			else{
				pp[pos]=n;
			}
		}
		catch(int j){
			cout<<"Invalid";
			break;
		}
	}
	return 0;
}