//ADT Implementation using 
#include<iostream>
using namespace std;
//Defining  and fix size of array insteas of declaring in class
#define SIZE  20
class ArrayList {
private:
    int count;
    int loc;
    int* Array;
    int length;
    int* curr;
//Function used to go to first position in array 
    void GoTohead() {
        curr = Array;
    }
//Funtion used to go to end of array
    void tail() {
        curr = Array + count - 1;
    }
//Function used to move back one position in array 

    void back() {
        curr = curr - 1;
    }
//Function used to move forward one position in array
    void next() {
        curr = curr + 1;
    }
public:
//Constructor used to initialize variables
    ArrayList() {
       
        Array = new int[SIZE];
        count = 0;
        length=0;
        loc = 0;
        curr = Array;
    }
//Destructor used to delete dynamic variables and array
    ~ArrayList() {
        delete[]Array;
        delete curr;
    }
//Function used to print the array 
    void printList() {
        if (count > 0) {
            GoTohead();
            for (int x = 0; x < count; x++)
                cout << *curr++ << "\t";
        }
        else cout << "Array is Empty" << endl;
    }
//Function used to Insert element in array
    void Insert(int val) {
        if (!IsFull()) {
            GoTohead();
            curr = curr + count;
            *curr = val;
            count++;
        }
        else {
            cout << "ArrayList is Full" << endl;
        }
    }
//Function used to insert element at some position
    void InsertAt(int pos, int val) {
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
                GoTohead();
                curr = curr + pos - 1;
                *curr = val;
                count++;
            }
            else
                cout << "Invalid Position" << endl;
    }
   
//Function used to check array is full
    bool IsFull() {
        if (count == SIZE)
            return true;
        else return false;
    }
//Function used to check array is empty

    bool IsEmpty() {
        if (count == 0)
            return true;
        else return false;
    }
//Function used to count elements in  array


    int Count() {
        return count;
    }
//Function used to make array empty

    void emptylist() {
        GoTohead();
        for (int x = 0; x < SIZE; x++) {
            *curr++ = 0;
        }
    }
    // void emptyList()
    // {
    //     Array=0;
    // }
//Function used to sort array 

    void sort()

    {
        int *p1;
			int *p2, *temp;
			//sorting - ASCENDING ORDER
			for(int i=0; i<SIZE; i++) {
				p1 = Array+i; 
				for(int j=i+1; j<SIZE; j++) {
					p2 = Array+j;
					if(*p1>*p2) {
						*temp  =*p1;
						*p1=*p2;
						*p2=*temp;
					}
				}
			
			}

    }
//Function used to reverse array 
    void reverseList()
    {
        int *p1,*pn,temp;
            p1 = Array;
            pn = Array+SIZE-1;
            int val = SIZE/2;
            for(int i = 0;i<val;i++)
            {
                temp = *p1;
                *p1 = *pn;
                *pn = temp;
                p1++;
                pn--;
            }

    }
//Function used to search element in  array 
    bool searchElement(int val)
    {
        GoTohead();
        for(int i=1;i<=SIZE;i++)
        {
            if(*curr==val)
            {
                return true;
            }
            else{
                return false;
            }
        }


    }
//Function used to delete element in  array 
    void DeleteElement(int val)
    {
        GoTohead();
        if(!IsEmpty())
        {
        for(int i=1;i<SIZE;i++)
        {
            *curr= *curr+1;
            next();
        }
        length--;
        }
        // if (!IsEmpty()) {
		// 		int *curr= Array;
		// 		for (int x=0; x<SIZE; x++) {
		// 			if(*curr==val) {
		// 				int *ptr2= curr;
		// 				for (int j=x; j<SIZE; j++) {
		// 					ptr2++;
		// 					*curr= *ptr2;
		// 					curr++;
		// 				}
		// 				length--;
		// 				break;
		// 			}
		// 			curr++;
		// 		}
		// 	} else cout<<"Array is Empty, Delete operation failed"<<endl;
        
        


    }
    



};
int main() {
    //ArrayList* obj = new ArrayList();

    int x;
    ArrayList obj;
//Here using switch statement to print menue and select which operation to perform
    do
    {
        cout<<"1. Insert(x)"<<endl;
        cout<<"2. InsertAt(x,loc)"<<endl;
        cout<<"3. PrintLIst"<<endl;
        cout<<"4. SearchElement"<<endl;
        cout<<"5. Delete Element"<<endl;
        cout<<"6. Reverse list"<<endl;
        cout<<"7. Sort"<<endl;
        cout<<"8. IsFull"<<endl;
        cout<<"9. IsEmpty"<<endl;
        cout<<"10. EmptyList"<<endl;
        cout<<"0. Exit"<<endl;

        cout<<"Enter your choice:"<<endl;
        cin>>x;
        switch (x)
        {
        case 1:
            
            int element;
            cout<<"Enter element to insert"<<endl;
            cin>>element;
            obj.Insert(element);
            break;
        case 2:
            obj.InsertAt(3,1);
            int loc;
            cout<<"Enter element to insert "<<element<<"at location"<<loc<<endl;
            break;
        case 3:
            obj.printList();
            cout<<"Arraylist is "<<endl;
            break;    
        case 4:
            obj.searchElement(6);
            cout<<"Search element is :"<<endl;
            break;
        case 5:
            obj.DeleteElement(2);
            cout<<"Deleted element is :"<<endl;
            break;
        case 6:
            obj.reverseList();
            cout<<"Reveresd list is :"<<endl;
            break;
        case 7:
            obj.sort();
            cout<<"Sorted list is :"<<endl;
            break;
        case 8:
            obj.IsFull();
            break;  
        case 9:
            obj.IsEmpty();
            break;                
        case 10:
            obj.emptylist();
            break;                    
        default:
            break;
        }

    } while (x!=0);
   

    return 0;
}