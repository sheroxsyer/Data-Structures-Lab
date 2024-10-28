#include<iostream>
using namespace std;
class MinHeap
{
    public:



    void swap(int& num1, int& num2) 
    {
    int temp = num1;
    num1 = num2;
    num2 = temp;
    }

    void  BuildHeap(int Array[],int totalElements)
{
    for( int index =(totalElements / 2) - 1;index >= 0;index--)
    {
        int parent = index;
        int lChildIndex = index*2+1;
        int rChildIndex = index*2+2;
        

        if(lChildIndex < totalElements )
        {
            swap(Array[lChildIndex],Array[parent]);
            
        }

        if(Array[lChildIndex] < Array[parent])
        {
            swap(Array[lChildIndex],Array[parent]);

        }


        



         if(rChildIndex < totalElements )
        {
            swap(Array[rChildIndex],Array[parent]);
        }

        if(Array[rChildIndex] < Array[parent])
        {
            swap(Array[rChildIndex],Array[parent]);

        }
    }
    

}


};
 


int main()
{
    MinHeap heap;

    int Array[] = {4, 10, 3, 5, 1};
    int totalElements = sizeof(Array)/sizeof(Array[0]);
    heap.BuildHeap(Array,totalElements);
    cout << "Your minHeap is : ";
    for (int i = 0; i < totalElements; i++) 
    {
        cout << Array[i] << " ";
    }
    return 0;
}


