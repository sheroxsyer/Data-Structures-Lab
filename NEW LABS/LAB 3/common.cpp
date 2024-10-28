#include<iostream>
using namespace std;
#define SIZE  10
class ArrayList {
private:
    int count;
    int pos;
    int * Array;
    int * Array1;
    int * Array2;
    int *Array3;
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
       
        Array = new int [SIZE];
        count = 0;
        pos = 0;
        curr = Array;
        Array1 = new int[SIZE];
        Array2 = new int[SIZE];
        Array3 = new int[SIZE];





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
    void uniqueElements (ArrayList *obj,ArrayList*obj1,ArrayList*obj2)
    {
        this->head();
        int *p,*q,*r;
        Array1 = p;
        Array2 = q;
        Array3 = r;

        if(Array1 != Array2 )
        {
            cout<<"unique elements are"<<*r;
        }


    }


};
int main() {
    ArrayList* obj = new ArrayList();
    ArrayList* obj1 = new ArrayList();

     ArrayList *obj2 = new ArrayList();
     ArrayList* obj2 = new ArrayList();

     obj.uniqueElements(obj,obj1,obj2)

     Array1 = {2,1,3};
     Array2 = {9,3,2};
     Array3 ={1,2,2,3,3,9};

    obj1->emptylist();
    obj1->InsertElement(1);
    obj1->InsertElement(2);
    obj1->InsertElement(3);
    obj1->InsertElement(4);

    obj1->printArray(); cout << endl;
    obj1->InsertAtPos(2, 99);

    obj1->printArray(); cout << endl;

   

    return 0;
}