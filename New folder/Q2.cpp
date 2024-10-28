#include<iostream>
using namespace std;

int Max(int (&arr)[5]){
	int* max=&arr[0];
	cout<<"Max "<<*max<<endl;
	for(int i=0; i<5;i++){
		if(arr[i]>*max){
			*max=arr[i];
		}
	}
	
	return *max;
}

int Min(int (&arr)[5]){
	int* min=arr;
	cout<<"Minimum  : "<<*min<<endl;
	for(int i=0; i<5; i++){
		if(arr[i]<(*min)){
			min=&arr[i];
		}
	}
	
	return *min;
}

int main()
{
	int arr[5]={1,2,3,4,5};
	cout<<"Maximum number is : "<<Max(arr)<<endl;
	cout<<"Minimum number is : "<<Min(arr);
	return 0;
}

