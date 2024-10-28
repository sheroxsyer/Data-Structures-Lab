#include<iostream>
using namespace std;

struct Queue
{
    stack *obj1;
    stack*obj2;

    
    
	


};
class stack
{
 int *arr;
 int size;
 int len;
 int* curr;
 int top;
 public:
 void  EnQueue();
 int DeQueue();
 Queue obj1;
 Queue obj2;
  stack()
  {
   size=10;
   len=0;
   arr=new int [size];
   top=-1;
   Queue*obj1;
   Queue*obj2;

   
  }
  void stack::EnQueue(int x)
	{
		
		while (!obj1.IsEmpty()) {
			obj2.push(obj1.peek());
			obj1.pop();
		}

		
		obj1.push(x);

		
        		while (!obj2.IsEmpty()) {
			obj1.push(obj2.peek());
			obj2.pop();
		}
	}
int stack:: DeQueue()
	{
		
		if (obj1.IsEmpty()) {
			cout << "obj is Empty";
			exit(0);
		}

		
		int x = obj1.peek();
		obj1.pop();
		return x;
	}

  

  
  void print()
  {
   while(!IsEmpty())
   {
    cout<<arr[top]<<" ";
    pop();
   }
   cout<<endl;
  }
  void push(int val)
  {
   
   if(top==size-1)
   {
    cout<<"Stack Overflow"<<endl;
   }
   else
   {
    top++;
    arr[top]=val;
    len++;
   }
  }
  
  int pop()
  {
   if (top==-1)
   {
    cout<<"Stack Underflow"<<endl;
   }
   else
   {
    
    int x=arr[top];
    top--;
    len--;
    return x;
   }
  }
  
  int peek()
  {
   if(top==-1)
   {
    cout<<"Stack Underflow"<<endl;
   }
   else
   {
    
    return arr[top];
    
   }
  }
  bool IsEmpty()
  {
   if (top==-1)
   {
    return true;
   }
   else
   {
    return false;
   }
  }
  
};


int main()
{
	Queue obj;
	obj.EnQueue(1);
	obj.EnQueue(2);
	obj.EnQueue(3);

	cout << obj.DeQueue() << '\n';
	cout << obj.DeQueue() << '\n';
	cout << obj.DeQueue() << '\n';

	return 0;
}
// int main()
// {
//  Queue obj1,obj2;
//  obj1.push(1);
//  obj1.push(2);
//  obj1.push(3);
//  obj1.push(4);
//  obj1.push(5);
//  obj1.pop();
//  cout<<endl;
//  cout<<obj1.peek();
//  cout<<endl;
//  obj1.print();
//  cout<<endl;
	
//  return 0;
// }


