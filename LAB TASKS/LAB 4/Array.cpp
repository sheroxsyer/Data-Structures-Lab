#include<iostream>
using namespace std;
class ArrayList
{
    private:
    int SIZE;
    int length;
    int pos;
    int *Array;
    int *curr;
    public:
    ArrayList()
    {
        SIZE=10;
        Array=new int[SIZE];
        length=0;
        pos=0;
        curr = Array;

    }
    ~ArrayList()
    {
        delete[]Array;
        delete curr;
    }
    void printArray()
    {
        if(length >0)
        {
            head();
            for (int x=0;x<length;x++)
                cout<<*curr++<<"\t";

        }
        else 
            cout<<"Array is empty"<<endl;
    }
    void InsertElement(int val)
    {
        if(!IsFull())
        {
            head();
            curr= curr+length;
            *curr=val;
            length++;
        }
        else
            {
                cout<<"Array is full"<<endl;
            }
    }

    void InsertAtPos(int val,int pos)
    {
        if(!IsFull())
        if(pos<=length && pos>0)
        {
            tail();
            for(int i=length;i<pos;i-- )
            {
                *(curr+1) =*curr;
                back();
            }
            next();
            *(curr)=val;
            length++;

        }
        else if(pos >length && pos<=SIZE)
        {
            head();
            curr = curr + pos-1;
            *curr =val;
            length++;

        }
        else
            cout<<"INvalid Position"<<endl;

    }

    void reverseArray()
    {
        int*p1,*pn,temp;
        p1 = Array;
        pn = Array+length-1;
        int val = length/2;
        for(int i=0;i<val;i++)
        {
            temp = *p1;
            *p1=*pn;
            *pn = temp;
            p1++;
            pn--;

        }
    }

    void deleteElementAtPos(int pos)
    {
        if(!IsEmpty())
        {
            if (pos<=SIZE && pos>0)
            {
                head();
                curr = curr +pos-1;
                for(int x=0;x<=length-pos;x++)
                {
                    *(curr)=*(curr +1);
                    next();
                }
                length--;
            }
            else
                cout<<"Array is Empty,Delete operation failed"<<endl;
        }
    }

    void head()
    {
        curr = Array;
    }

    void tail()
    {
        curr = Array+length-1;
    }

    bool IsEmpty()
    {
        if (length == 0)
        return true;
        else
        return false;
    }

    bool IsFull()
    {
        if (length == SIZE)
        return true;
        else
        return false;
        
    }

    void back()
    {
        curr = curr-1;
    }
    void next()
    {
        curr = curr + 1;
    }

    int Length()
    {
        return length;
    }

    void emptylist()
    {
        head();
        for(int x=0;x<SIZE;x++)
        {
            *curr++=0;
        }
    }

};
int main()
{
    ArrayList *obj = new ArrayList;
    obj->emptylist();
    obj->InsertElement(1);
    obj->InsertElement(2);
    obj->InsertElement(3);
    obj->InsertElement(4);

    obj->printArray();
    cout<<endl;
    obj->InsertAtPos(99,2);

    obj->printArray();
    cout<<endl;
    obj->deleteElementAtPos(2);
    obj->reverseArray();
obj->printArray();
}