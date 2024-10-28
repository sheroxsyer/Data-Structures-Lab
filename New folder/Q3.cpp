#include<iostream>
using namespace std;
void common(int a1[8],int a2[4]){
	int a3[10];
	int count=0;
	for(int i=0; i<8;i++)
	{
		for(int j=0 ;  j<4; j++)
		{
			if(a1[i]==a2[j])
			{
				a3[count]=a1[i];
				count++;
				break;
			}
		}
	}
	cout<<"Common elemnts in arrays are "<<endl;
	cout<<"a3[";
	for(int i =0 ; i<count-1; i++)
	{
		cout<<a3[i];
	}
	cout<<"]";
}
int main()
{
	int a1[8]={1,2,3,4,5,6,3,2};
	int a2[4]={1,3,5,7};
	common(a1,a2);
	return 0;
}

