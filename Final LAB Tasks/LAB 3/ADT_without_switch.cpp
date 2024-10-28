//ADT Implementation using 
#include<iostream>
using namespace std;
//Defining  and fix size of array insteas of declaring in class
#define SIZE  20
class ArrayList {
private:
    int length;
    int loc;
    int* Array;
    
    int* curr;
//Function used to go to first position in array 
    void GoTohead() {
        curr = Array;
    }
//Funtion used to go to end of array
    void tail() {
        curr = Array + length - 1;
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
        length = 0;
        
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
        if (length > 0) {
            GoTohead();
            for (int x = 0; x < length; x++)
                cout << *curr++ << "\t";
        }
        else cout << "Array is Empty" << endl;
    }
//Function used to Insert element in array
    void Insert(int val) {
        if (!IsFull()) {
            GoTohead();
            curr = curr + length;
            *curr = val;
            length++;
        }
        else {
            cout << "ArrayList is Full" << endl;
        }
    }
//Function used to insert element at some position
    void InsertAt(int pos, int val) {
        if (!IsFull())
            if (pos <= length && pos > 0) {
                tail();
                for (int i = length; i >= pos; i--) {
                    *(curr + 1) = *curr;
                    back(); //curr= curr-1;
                }
                next();//curr= curr+1;
                *(curr) = val;
                length++;
            }
            else if (pos > length && pos <= SIZE) {
                GoTohead();
                curr = curr + pos - 1;
                *curr = val;
                length++;
            }
            else
                cout << "Invalid Position" << endl;
    }
   
//Function used to check array is full
    bool IsFull() {
        if (length == SIZE)
            return true;
        else return false;
    }
//Function used to check array is empty

    bool IsEmpty() {
        if (length == 0)
            return true;
        else return false;
    }
//Function used to count elements in  array


    int Count() {
        return length;
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
			for(int i=0; i<length-1; i++) {
				p1 = Array+i; 
				for(int j=i+1; j<length; j++) {
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
            pn = Array+length-1;
            int val = length/2;
            //while(p1<pn)
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
        for(int i=1;i<=length;i++)
        {
            if(*curr==val)
            {
                cout<<"value found"<<endl;
                return true;
                next();
            }
            else{
                cout<<"value not found"<<endl;
                return false;
            }
        }


    }
//Function used to delete element in  array 
    void DeleteElement(int val)
    {
        GoTohead();
        // if(!IsEmpty())
        // {
        // for(int i=1;i<SIZE;i++)
        // {
        //     *curr= *curr+1;
        //     next();
        // }
        // length--;
        // }
        if (!IsEmpty()) {
				int *curr= Array;
				for (int x=0; x<length; x++) {
					if(*curr==val) {
						int *ptr2= curr;
						for (int j=x; j<length; j++) {
							ptr2++;
							*curr= *ptr2;
							curr++;
						}
						length--;
						break;
					}
					curr++;
				}
			} else cout<<"Array is Empty, Delete operation failed"<<endl;
        
        


    }
    



};
int main() {
    ArrayList* obj = new ArrayList();
    cout<<"Inserted element are:"<<endl;
    obj->Insert(2);
    obj->Insert(3);
    obj->Insert(4);
    obj->Insert(5);
    obj->Insert(1);
    obj->printList();
    cout<<endl;

    cout<<"Searched element is:"<<endl;
    obj->searchElement(2);
    cout<<"After Deletion:"<<endl;
    
    obj->DeleteElement(3);
    obj->printList();
    cout<<endl;
    cout<<"Insertion at location"<<endl;
    obj->InsertAt(4,7);
    obj->printList();
    cout<<endl;
    
    cout<<"reverse list is:"<<endl;
    obj->reverseList();
    obj->printList();
    cout<<endl;
    
    
    cout<<"sorted list is:"<<endl;
    obj->sort();
    obj->printList();
    

//     int x;
//     ArrayList obj;
// //Here using switch statement to print menue and select which operation to perform
//     do
//     {
//         cout<<"1. Insert(x)"<<endl;
//         cout<<"2. InsertAt(x,loc)"<<endl;
//         cout<<"3. PrintLIst"<<endl;
//         cout<<"4. SearchElement"<<endl;
//         cout<<"5. Delete Element"<<endl;
//         cout<<"6. Reverse list"<<endl;
//         cout<<"7. Sort"<<endl;
//         cout<<"8. IsFull"<<endl;
//         cout<<"9. IsEmpty"<<endl;
//         cout<<"10. EmptyList"<<endl;
//         cout<<"0. Exit"<<endl;

//         cout<<"Enter your choice:"<<endl;
//         cin>>x;
//         switch (x)
//         {
//         case 1:
            
//             int element;
//             cout<<"Enter element to insert"<<endl;
//             cin>>element;
//             obj.Insert(element);
//             break;
//         case 2:
//             obj.InsertAt(3,1);
//             int loc;
//             cout<<"Enter element to insert "<<element<<"at location"<<loc<<endl;
//             break;
//         case 3:
//             obj.printList();
//             cout<<"Arraylist is "<<endl;
//             break;    
//         case 4:
//             obj.searchElement(6);
//             cout<<"Search element is :"<<endl;
//             break;
//         case 5:
//             obj.DeleteElement(2);
//             cout<<"Deleted element is :"<<endl;
//             break;
//         case 6:
//             obj.reverseList();
//             cout<<"Reveresd list is :"<<endl;
//             break;
//         case 7:
//             obj.sort();
//             cout<<"Sorted list is :"<<endl;
//             break;
//         case 8:
//             obj.IsFull();
//             break;  
//         case 9:
//             obj.IsEmpty();
//             break;                
//         case 10:
//             obj.emptylist();
//             break;                    
//         default:
//             break;
//         }

//     } while (x!=0);
   

    return 0;
}