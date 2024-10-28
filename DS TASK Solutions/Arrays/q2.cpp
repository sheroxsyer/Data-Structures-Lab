#include<iostream>
using namespace std;

//function declaration
void find(int* , int s);

int main()
{
   int size=6; //array size
   int arr[size]; // declaring the array

   int *ptr=NULL; // declaring a pointer
   ptr=arr; // intializing the pointer ... pointer will point to the first element
            // of the array.. we will handle the array through this pointer onwards

   cout<<"Enter 6 values in the array"<<endl;

   for(int i=0 ; i<size ;i++) // loop that will take the values from the user
   {
       cin>>*ptr;
       ptr++; // inc the pointer to point to the next location
   }
   
   // placing the ptr again to the first position of the array
   ptr=arr;
     
   find(ptr, size); //caling the function

   return 0;
}

// this function will return the max and min vakue of the array 
// we will pass a pointer pointing to the array and the size of the array to this ftn
// we will consider the first element of the array as the max and min value of the array
// for finding in the max value we will check in aloop if the nextvalue is greter then 
//the prev value we will replace the max variable value with it

void find(int* a, int s )
{
    int max; // variable that will store the max value
    int min; // varaible that will store the min value
    
    int *ptr1=a; // pointer that will srore the first element of the array

    max=*a; // storing the first element of the array in max vaiable

    for(int i=0; i<s ; i++) // loop for finding max value
    {
        if(*a>max)
        {
            max=*a;
        }
        *a++;
    }

    a=ptr1; // restoring the first position in the array

    min=*a; // storing the first element of the array in min vaiable

    for(int i=0; i<s ; i++) // loop for finding max value
    {
        if(*a<min)
        {
            min=*a;
        }
        *a++;
    }

    // displaying the results on screen
    cout<<"Maximum element in the array = "<<max<<endl;
    cout<<"Minimum element in the array = "<<min<<endl;
}