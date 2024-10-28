/*Implement a function that finds common elements in two arrays. You can assume that the sets
are stored using arrays. So, if array1 = {1,2,3,4,5,6,3,2} and array2 is {1,3,5,7}, then array3
should be {1,3,5}. Note array3 should not have any duplicate elements. You have to:
think of all the functions that are required for this problem. Each function should perform its
dedicated task. So, plan them out before implementing them.
Main should only have a set of function calls.*/

#include<iostream>
using namespace std;

void findCommon(int arr1[], int arr2[], int arr3[],int n1,int n2,int n3)
{
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
}

int main()
{
    int arr1[] = {1,2,3,4,5,6,7,9};
    int arr2[] = {5,6,7,8,9,10};
    int arr3[] = {9,10,11,12};

    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    cout<<"common elements are:";
    findCommon(arr1,arr2,arr3,n1,n2,n3);
    return 0 ;
}



