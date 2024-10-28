#include <iostream>
using namespace std;


struct node
{
	int data;
	node* next;
};
//simple implementation of stack
node* top;

void push(int data)
{
	
	node* temp = new node();
	if (!temp)
	{
		cout << " your stack is  overflow";
	}
	temp->data = data;
    temp->next = top;
	top = temp;
}
int isEmpty()
{
	return top == NULL;
}
int peek()
{
	
	if (!isEmpty())
		return top->data;
	else
		return 1;
}
void pop()
{
	node* temp;

	if (top == NULL)
	{
		cout << " your sstack is  Underflow" << endl;
		
	}
	else
	{
	temp = top;
		top = top->next;
		delete(temp);
	}
}
void reverseStack() {
        // use 3 variables to traverse list
        node* prev = NULL;
        node* curr = top;
        node* next = NULL;

        while (curr) {
            // Store next in list
            next = curr->next;

            // Reverse list
            curr->next = prev;

            // Move the pointers 
            prev = curr;
            curr = next;
        }

        // Update top
        top = prev;
    }

void display()
{
	node* temp;
	if (top == NULL)
	{
		cout << "your stack is underflow";
	}
	else
	{
		temp = top;
		while (temp != NULL)
		{
	cout << temp->data << " ";

			temp = temp->next;
		}
	}
}
int main()
{
	cout<<"your stack contains elements:"<<endl;	
	push(11);
	push(22);
	push(33);
	push(44);
	display();
	cout<<endl;
	cout << " Peek element is : "<< peek() << endl;
	cout<<"after removal of one element"<<endl;
	pop();
	display();
	cout<<endl;
	cout<<"Reverse stack is :"<<endl;
	reverseStack();
	display();
	return 0;
}
