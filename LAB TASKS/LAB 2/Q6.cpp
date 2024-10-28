

#include<iostream>

using namespace std;
void returnString(char *a,int x, int y){
	
	for(int i=x; i<=y;i++)
	{
		cout<<a[i];
	}
}

int main()
{
	int startIndex,stopIndex;
	char arr[15];
	cout<<"Enter the string "<<endl;
	cin>>arr;
	char *p=arr;
	cout<<"Enter the starting index"<<endl;
	cin>>startIndex;
	cout<<"Enter the stoping index"<<endl;
	cin>>stopIndex;
	
	returnString(p,startIndex,stopIndex);
	return 0;
}
