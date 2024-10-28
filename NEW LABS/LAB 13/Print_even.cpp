#include<assert.h>
#include<iostream>
using namespace std;
class MaxHeap
{
    private:

    struct Node
    {
        int key;
        
    };
    
    Node*arr;
    int capacity;
    int totalItems;
    void doubleCapacity()
    {
        if(this->arr==NULL)
        {
            this->arr= new Node[1];
            this->capacity= 1;
            return;

        }
        int newCapacity = capacity*2;
        Node *newArr = new Node[newCapacity];
        for(int i = 0;i<this->totalItems;i++)
        {
            newArr[i] = this->arr[i];
        }
        if(this->arr != NULL)
        delete this->arr;
        this->capacity = newCapacity;
        this->arr = newArr;

    }
    void shiftUp(int index)
    {
        if(index<1)
        return;
        int parent = (index-1)/2;
        if(this->arr[index].key > this->arr[parent].key)
        {
            swap(this->arr[index],this->arr[parent]);
            shiftUp(parent);
        }
        return;

        
    }
    void shiftDown(int index)
    {
        int maxIndex = -1;
        int lChildIndex = index*2+1;    //1
        int rChildIndex = (index*2)+2;  //2

        if(lChildIndex < totalItems)
        {
            if(arr[index].key < arr [lChildIndex].key)
            {
            maxIndex = lChildIndex;

        }
        }
        if(rChildIndex < totalItems)
        {
        int newindex = (maxIndex == -1 ? index : maxIndex);
        {
            if(arr[newindex].key < arr [rChildIndex].key)
            {
            maxIndex = rChildIndex;
            }

        } 
        if (maxIndex == -1);
        return;
        swap(arr[index],arr[maxIndex]);
            shiftDown(maxIndex);
        }
    }
        public:
        MaxHeap()
        {
            this->arr = NULL;
            this->capacity = 0;
            this ->totalItems= 0;

        }
        MaxHeap(int _capacity)
        {
            assert(_capacity >=1);
            this->arr = new Node[_capacity];
            this ->capacity = _capacity;
            this->totalItems = 0;


        }
        void insert(int key)
        {
            if(this->totalItems == this->capacity)
            {
                doubleCapacity();
            }
            this->arr[totalItems].key=key;
            shiftUp(totalItems);
            this->totalItems++;
        }
        void Find_Parent(int index)
        {
            if(index<1)
            return;
            int count;
            int parent = (index-1)/2;
            int lChildIndex = index*2+1;    //1
            int rChildIndex = (index*2)+2;  //2

            for(int i = 0;i<this->totalItems;i++)
            {
                if(index = (index-1)/2);
                count++;
                cout<<"Parent Nodes on left side "<<endl;
                Find_Parent(lChildIndex);
                cout<<"Parent Nodes on right side "<<endl;
                Find_Parent(rChildIndex);
            }

            //even parent nodes

            if(count %2 ==0)
            {
                Find_Parent(lChildIndex);
                cout<<"Even parent nodes on left side"<<endl;
                cout<<parent;

                Find_Parent(rChildIndex);
                cout<<"Even parent nodes on right side"<<endl;
                cout<<parent;
            }

        }
        void getMax(int & key)
        {
            assert(totalItems !=0);
            key = this->arr[0].key;
        }
        
        void deleteMax()
        {
            assert(totalItems !=0);
            swap(arr[0],arr[this->totalItems-1]);
            totalItems--;
            shiftDown(0);
        }
        bool isEmpty() const
        {
            return totalItems ==0;
        }
        void deleteAll()
        {
            if(this->arr != NULL)
            {
                delete []arr;
                arr = NULL;
                this->capacity= 0;
                this->totalItems=0;
            }
        }
        ~MaxHeap()
        {
            deleteAll();
        }
    };
    int main()
    {
        MaxHeap heap;
        for(int i = 1;i<=200;i++)
        {
            heap.insert(i);
        }
        heap.deleteAll();
        for(int i = 201;i<=205;i++)
        heap.insert(i);

        while(!heap.isEmpty())
        {
            int s;
            heap.getMax(s);
            cout<<s<<endl;
            heap.deleteMax();

        }
        return 0 ;

        heap.Find_Parent(5);


    };
    