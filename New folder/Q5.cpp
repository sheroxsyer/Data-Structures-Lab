#include<iostream>
using namespace std;

void Swap(){
	char choice;
	int countA1=0,countA2=0,countA3=0;
	int* a1=new int[10],* a2=new int [10],* a3=new int[10];
;
	
	for(int i=0; i<10;i++){				//putting elements in a1
		cin>>a1[i];
		countA1++;
		cout<<"Do you want to continue ? y/n "<<endl;
		cin>>choice;
		if(choice=='n'){
			break;
		}
	}
	cout<<"now enter values for second array : "<<endl;
	for(int j=0; j<10; j++){				//putting elements in a2
		cin>>a2[j];
		countA2++;
		cout<<"Do you want to continue ? y/n "<<endl;
		cin>>choice;
		
		if(choice=='n'){
			break;
		}
	}
	
	
	for(int i=0 ;i<countA1; i++){				//putting a1 elements in a3 for swaping
		a3[i]=a1[i];
		countA3++;
	}
	
	for(int j=0; j<countA2;j++){				//putting a2 elements in a1
		a1[j]=a2[j];
	}
	
	for(int k=0; k<countA3; k++){				//putting a3 ellements in a2
		a2[k]=a3[k];
	}
	
	cout<<"After Swaping"<<endl;
	cout<<"A1[";
	for(int i=0; i<countA1; i++){
		cout<<a1[i];
	}
	cout<<"]";
	cout<<endl;
	cout<<"A2[";
	for(int i=0; i<countA2; i++){
		cout<<a2[i];
	}
	cout<<"]";

}
int main()
{
	Swap();
	return 0;
}

