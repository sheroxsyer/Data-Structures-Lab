//Write a code to take input in 2 dynamic arrays as long as the user doesn't enter 
//sentinel value. After you have finished taking input for one dynamic array start for
//the second. Their size depends on after entering how many elements the user enters the
//sentinel value and their size may be different. Now completely swap the contents of the
// two dynamic arrays.

#include<iostream>
using namespace std;

//function declaration
void swap(int a[], int b[], int s, int ss);

int main()
{
    int input1=0; // variable that will store sentinel value
    int s1=0; // variable storing the size of array 1

    int *arr1= new int[s1]; //  array declaration
    *arr1=0;
    int *temp=arr1; 
    cout<<"Enter values for array 1 ."<<endl;
    cout<<"Enter -11 when you are done entering the data."<<endl;
    do //this loop will take values from the user
    {
       cin>>input1;
       *(arr1)=input1;
       arr1++;
       s1++;
        
    } while (input1!=-11);

    cout<<endl;

    int s2=0; // varaible storing the size of array 2 
    int *arr2= new int[s2];
    int *temp2=arr2;
    *arr2=0;
    int input2=0;
    
    cout<<"Enter values for array 2 ."<<endl;
    cout<<"Enter -11 when you are done entering the data."<<endl;
    // this loop will take values from the user
    do
    {
       cin>>input2;
       *(arr2)=input2;
       arr2++;
       s2++;
        
    } while (input2!=-11);

    arr1=temp;
    arr2=temp2;

   

   arr1=temp;
   cout<<endl;

    //calling the function
    swap(arr1, arr2,s1,s2);
    
}

// this function will swap the values of arrays ... we will store the element of first
// array in a varaible then store the element of the second  array in first array and the
// stored value in first array 
void swap(int a[], int b[], int s, int ss)
{
   int *temp=a;
   int *temp2=b;

   cout<<"Before swaping."<<endl;
   cout<<"array 1 :";
   for(int i=0; i<(s-1); i++)
   {
       cout<<*a<<" ";
       a++;
   }

   a=temp;

   cout<<endl;

   cout<<"array 2 :";
   for(int i=0; i<(ss-1); i++)
   {
       cout<<*b<<" ";
       b++;
   }

   b=temp2;

   cout<<endl;

   int size; // this varaible will store the size of the array that is smaller 
   if(s<ss)
   {
       size=s;
   }
   else
   {
       size=ss;
   }

   for(int i=0 ; i<(size-1); i++)// this loop will swap the values 
   {
       int store=*a; 
       *a=*b;
       *b=store;
       a++;
       b++;
   }

   a=temp;
   b=temp2;

   cout<<endl;

   //displaying in the screen after swapping

   cout<<"After swaping."<<endl;
   cout<<"array 1 :";
   for(int i=0; i<(s-1); i++)
   {
       cout<<*a<<" ";
       a++;
   }

   cout<<endl;

   cout<<"array 2 :";
   for(int i=0; i<(ss-1); i++)
   {
       cout<<*b<<" ";
       b++;
   }
}