#include <iostream>
using namespace std;
int* find(int* a, int s )
 {
     int max; 
      
    
     int *ptr1=a; 

     max=*a; 

     for(int i=0; i<s ; i++) // loop for finding max value
     {
         if(*a>max)
         {
             max=*a;
         }
         *a++;
         
     }

    a=ptr1; 


     // displaying the results on screen
    cout<<"Maximum element in the array = "<<max<<endl;
    
    
}

int* secondMax(int arr[], int size) {
    int *max_ptr = &arr[0];
    int *second_max_ptr = &arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > *max_ptr) {
            second_max_ptr = max_ptr;
            max_ptr = &arr[i];
        } 
        else if 
        (arr[i] > *second_max_ptr && arr[i] != *max_ptr) {
            second_max_ptr = &arr[i];
        }
    }

    return second_max_ptr;
}




    int main()
{
   int size=6; 
   int arr[size]; 

   int *ptr=NULL; 
   ptr=arr; 

   cout<<"Enter 6 values in the array"<<endl;

   for(int i=0 ; i<size ;i++) 
   {
       cin>>*ptr;
       ptr++; 
   }
   
   
   ptr=arr;

//    find(ptr, size); 



     
   secondMax(arr, size); 
//    int*maxptr=find(ptr,size);
   int *second_max_ptr = secondMax(arr, size);
    cout << "The second maximum is " << *second_max_ptr << endl;
   return 0;
}



    


