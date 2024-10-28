#include<iostream>
using namespace std;
class MaxHeap
{
    public:

    bool IsMaxHeap(int Array[],int totalElements)
{
    int index;
    int lChildIndex = index*2+1;
    int rChildIndex = index*2+2;
    int parent = (index-1)/2;

    for(int index=0;index<=parent;index++)
    {
        if(Array[lChildIndex] > Array[index])
        {
            cout<<" Not a Max heap"<<endl;
            return false;
        }

        if(Array[rChildIndex] < totalElements)
        {
            cout<<" Not a Max heap"<<endl;
            return false;

        }
        if(Array[rChildIndex] > Array[index])
        {
            cout<<" Not a Max heap"<<endl;
            return false;
        }
        else
        {
            cout<<"Max heap"<<endl;
            return true;
        }
    }
    

}


};


int main()
{
    MaxHeap heap;

    int Array[] = {90, 15, 10, 7, 12, 2};
    int totalElements = sizeof(Array)/sizeof(Array[0]);
    heap.IsMaxHeap(Array,totalElements);

    
    
    

 
    return 0;
}


