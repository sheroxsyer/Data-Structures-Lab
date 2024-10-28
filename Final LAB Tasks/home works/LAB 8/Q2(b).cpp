
#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
};

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
int precedence(char ch)
{
	if (ch == '^')//3rd priority
		return 3;
	else if (ch == '/' || ch == '*')//2nd priority
		return 2;
	else if (ch == '+' || ch == '-')//1st priority
		return 1;
	else
		return -1;
}


void infixToPostfix(string s)
{

	 
	string res;

	for (int i = 0; i < s.length(); i++) {
		char c = s[i];

		
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			res += c;

		
		else if (c == '(')
			push('(');

		
		else if (c == ')') {
			while (peek() != '(') {
				res += peek();
				pop();
			}
			pop();
		}

		else {
			while (!isEmpty()
				&& precedence(s[i]) <= precedence(peek())) {
				if (c == '^' && peek() == '^')
					break;
				else {
					res += peek();
					pop();
				}
			}
			push(c);
		}
	}

	while (!isEmpty()) {
		res += peek();
		pop();
	}

	cout << res << endl;
}

int main()
{
	
    string exp = "abc++";
	cout<<"Converted exponential is:"<<endl;
    infixToPostfix(exp);
    
	return 0;
}
