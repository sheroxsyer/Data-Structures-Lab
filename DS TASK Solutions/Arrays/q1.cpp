#include<iostream>
using namespace std;

//function declaration
void find(int array[6], int s);

int main()
{
   int size=6; // defining array size
   int arr[size]; // making the array which will store the values

   cout<<"Enter 6 values in the array"<<endl;

   for(int i=0; i<size; i++) // loop for aking vakues from the user
   {
        cin>>arr[i];
   }

   find(arr, size); // calling the function

   return 0;
}

// this funnction will find the maximum and minimmum vakue from the array
// first we will consider the first element of the araay to be the max and min value
// then in a loop check if the next value is greater then the previous value we will replace it
void find(int array[6], int size)
{
    int max=0; // variable that will store maximum value
    int min=0; // variable that will store minimum value

    max=array[0];

    for(int i=1 ; i<size ; i++) //  loop thatt will find max value
    {
        if(array[i]>max)
        {
            max=array[i];
        }
    }

    min=array[0];

    for(int i=1 ; i<size ; i++) // value that will find min value
    {
        if(array[i]<min)
        {
            min=array[i];
        }
    }

    //displaying the max and value on the screen
    cout<<"Maximum element in the array = "<<max<<endl;
    cout<<"Minimum element in the array = "<<min<<endl;
}