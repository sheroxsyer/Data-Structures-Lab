// #include<iostream>
// using namespace std;
// #define SIZE  20
// class ArrayList {
// private:
//     int count;
//     int pos;
//     int* Array;
//     int* curr;

//     void head() {
//         curr = Array;
//     }
//     void tail() {
//         curr = Array + count - 1;
//     }

//     void back() {
//         curr = curr - 1;
//     }
//     void next() {
//         curr = curr + 1;
//     }
// public:
//     ArrayList() {
       
//         Array = new int[SIZE];
//         count = 0;
//         pos = 0;
//         curr = Array;
//     }
//     ~ArrayList() {
//         delete[]Array;
//         delete curr;
//     }
//     void printArray() {
//         if (count > 0) {
//             head();
//             for (int x = 0; x < count; x++)
//                 cout << *curr++ << "\t";
//         }
//         else cout << "Array is Empty" << endl;
//     }
//     void reverseArray()
//         {
//             int *p1,*pn,temp;
//             p1 = Array;
//             pn = Array+length-1;
//             int val = length/2;
//             for(int i = 0;i<val;i++)
//             {
//                 temp = *p1;
//                 *p1 = *pn;
//                 *pn = temp;
//                 p1++;
//                 pn--;
//             }
//         }
//         void sortArray() {
// 			int *p1;
// 			int *p2, *temp;
// 			//sorting - ASCENDING ORDER
// 			for(int i=0; i<SIZE; i++) {
// 				p1 = Array+i; 
// 				for(int j=i+1; j<SIZE; j++) {
// 					p2 = Array+j;
// 					if(*p1>*p2) {
// 						*temp  =*p1;
// 						*p1=*p2;
// 						*p2=*temp;
// 					}
// 				}
			
// 			}

// 		}
// 		void deleteElement(int n) {
// 			if (!IsEmpty()) {
// 				int *ptr= Array;
// 				for (int x=0; x<length; x++) {
// 					if(*ptr==n) {
// 						int *ptr2= ptr;
// 						for (int j=x; j<length; j++) {
// 							ptr2++;
// 							*ptr= *ptr2;
// 							ptr++;
// 						}
// 						length--;
// 						break;
// 					}
// 					ptr++;
// 				}
// 			} else cout<<"Array is Empty, Delete operation failed"<<endl;
// 		}
// 		void deleteElementAtPos(int pos) {
// 			if (!IsEmpty()) {
// 				if (pos<=SIZE && pos>0){
// 					head();  //curr= &Array[0]
// 					curr = curr+pos-1;
// 					for (int x=0; x<=length-pos; x++){
// 						*(curr)= *(curr+1);
// 						next(); //curr= curr+1;
// 					}
// 						length--;
// 				}
// 			} else cout<<"Array is Empty, Delete operation failed"<<endl;
// 		}
//     void InsertElement(int val) {
//         if (!IsFull()) {
//             head();
//             curr = curr + count;
//             *curr = val;
//             count++;
//         }
//         else {
//             cout << "ArrayList is Full" << endl;
//         }
//     }
//     int main()
//     {
        
//         return 0;

//     }
