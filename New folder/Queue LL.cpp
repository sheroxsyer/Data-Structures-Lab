#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
};

node*rear;
node*front;

struct Queue {
	node *front;
	node*rear;
	Queue()
	{
		front = NULL;
        rear = NULL;
	}

	void Enqueue(int val)
	{

		node* curr = new node;

		
		if (rear == NULL) {
			front = curr;
			rear  =curr;
			return;
		}
		else
		{
		rear->next = curr;
		rear = curr;
	}
	}

	int isEmpty()
{
	return front == NULL;
}
	int isfull()
	{
		return rear == NULL;
	}

	void display()
{
	node* curr;
	if (front == NULL)
	{
		cout << "your Queue is underflow";
	}
	else
	{
		curr = front;
		while (curr != NULL)
		{
	cout << curr->data;

			curr = curr->next;
		}
	}
}
	void Dequeue()
	{
		if (front == NULL)
		{
			cout<<"Queue underflow"<<endl;
		}
			return;

		node* curr = front;
		front = front->next;

		if (front == NULL)
			rear = NULL;

		delete curr;
	}
};

int main()
{

	Queue q;
	q.Enqueue(1);
	q.Enqueue(2);
	q.Dequeue();
	q.Dequeue();
	q.Enqueue(3);
	q.Enqueue(4);
	q.Enqueue(5);
	q.Dequeue();
	q.display();
	}