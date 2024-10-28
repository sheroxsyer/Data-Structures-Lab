#include<iostream>

using namespace std;

void findCommon(char arr1[], char arr2[], char arr3[],int n1,int n2,int n3)
{
    char ch;
    
 char* arr1;
 
 arr1 = new char[ch];
 char* arr2;
 
 arr2 = new char[ch];
 char* arr3;
 
 arr3 = new char[ch];
 cout<<"Enter 1st array"<<endl;
    cin>>arr1[ch];
 cout << "Enter  values for arr1 " << endl;
 for (int i = 0; i < ch; ++i)
 {
 cout << "Characters are:" << i + 1 << ": ";
 cin >> *(arr1 + i);
 }
 cout << "Your 1st araray is :" << endl;
 for (int i = 0; i < ch; ++i)
 {
 cout << "Characters are : " << i + 1 << " :" << *(arr1 + i) << endl;
 }

 cout<<"Enter 2nd array"<<endl;
    cin>>arr2[ch];
 cout << "Enter  values for arr2 " << endl;
 for (int i = 0; i < ch; ++i)
 {
 cout << "Characters are:" << i + 1 << ": ";
 cin >> *(arr2 + i);
 }
 cout << "Your 2nd araray is :" << endl;
 for (int i = 0; i < ch; ++i)
 {
 cout << "Characters are : " << i + 1 << " :" << *(arr2 + i) << endl;
 }

 cout<<"Enter 3rd array"<<endl;
    cin>>arr3[ch];
 cout << "Enter  values for arr3 " << endl;
 for (int i = 0; i < ch; ++i)
 {
 cout << "Characters are:" << i + 1 << ": ";
 cin >> *(arr3 + i);
 }
 cout << "Your 3rd araray is :" << endl;
 for (int i = 0; i < ch; ++i)
 {
 cout << "Characters are : " << i + 1 << " :" << *(arr3 + i) << endl;
 }

 

 
 
     int i = 0, j = 0, k = 0;
    while(i< n1 && j<n2 && k<n3)
    if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
    {cout<<arr1[i]<<"";
    i++;
    j++;
    k++;
}
else if(arr1[i] < arr2[j])
i++;
else if (arr2[j] < arr3[k])
j++;
else 
k++;
delete[]arr1;
 delete[]arr2;
 delete[]arr3;

}

int main()
{
    cout<<"common elements are:";
    findCommon(arr1,arr2,arr3,n1,n2,n3);
    return 0 ;
    
    
}