//ArrayList Implementation
#include<iostream>
using namespace std;
#define SIZE  10
class ArrayList {
private:
    int count;
    int pos;
    int* Array;
    int* curr;

    void head() {
        curr = Array;
    }
    void tail() {
        curr = Array + count - 1;
    }

    void back() {
        curr = curr - 1;
    }
    void next() {
        curr = curr + 1;
    }
public:
    ArrayList() {
       
        Array = new int[SIZE];
        count = 0;
        pos = 0;
        curr = Array;
    }
    ~ArrayList() {
        delete[]Array;
        delete curr;
    }
    void printArray() {
        if (count > 0) {
            head();
            for (int x = 0; x < count; x++)
                cout << *curr++ << "\t";
        }
        else cout << "Array is Empty" << endl;
    }
    void InsertElement(int val) {
        if (!IsFull()) {
            head();
            curr = curr + count;
            *curr = val;
            count++;
        }
        else {
            cout << "ArrayList is Full" << endl;
        }
    }
    void InsertAtPos(int pos, int val) {
        if (!IsFull())
            if (pos <= count && pos > 0) {
                tail();
                for (int i = count; i >= pos; i--) {
                    *(curr + 1) = *curr;
                    back(); //curr= curr-1;
                }
                next();//curr= curr+1;
                *(curr) = val;
                count++;
            }
            else if (pos > count && pos <= SIZE) {
                head();
                curr = curr + pos - 1;
                *curr = val;
                count++;
            }
            else
                cout << "Invalid Position" << endl;
    }
   

    bool IsFull() {
        if (count == SIZE)
            return true;
        else return false;
    }
    bool IsEmpty() {
        if (count == 0)
            return true;
        else return false;
    }

    int Count() {
        return count;
    }
    void emptylist() {
        head();
        for (int x = 0; x < SIZE; x++) {
            *curr++ = 0;
        }
    }
    void concatenate(*A1,*A2){
        int A1[] = {1,2,3};
        int A2[] = {4,5,6};
        int *p = A1;
        int *q = A2;
        while(curr!=NULL) {
		cout<<*curr<<"\t";
		*curr= *(curr+1);
	}
    *(curr+1) =A2;

    for (int i = 0;i<A1;i++)
    {
         *p=*curr;
         *p++;

    }
    for (int j = 0; j<A2;j++)
    {
        *q = *curr;
        *q++;
    }




    }
}


};
int main() {
    ArrayList* obj = new ArrayList();
    ArrayList* obj1 = new ArrayList();

    obj->emptylist();
    obj->InsertElement(1);
    obj->InsertElement(2);
    obj->InsertElement(3);
    obj->InsertElement(4);

    obj->printArray(); cout << endl;
    obj->InsertAtPos(2, 99);

    obj->printArray(); cout << endl;
    obj->concatenate();
   

    return 0;
}