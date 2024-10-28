//file que.h
#include<iostream>
#include<string>
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
class Node
{
public:
Message data;
Node *next;
};
class Queue
{
public:
Node *front;
Node *rear;
int Item;
Queue()
{
front=NULL;
rear=NULL;
Item=0;
}
void add(Message m)
{
Node *newNode;
newNode=new Node;
newNode->data=m;
newNode->next=NULL;
if(isEmpty())
{
front=newNode;
rear=newNode;
}
else 
{            
            rear->next=newNode;
            rear=newNode;
            }
Item++;
            }
Message remove()
{
Message m;
Node *temp;
if(isEmpty())
{
cout<<"the queue is empty.";
}
else 
{
    m=front->data;
    temp=front;
    front=front->next;
    delete temp;
    Item--;
    return m;
}
}  
bool isEmpty()
{
bool status;
if(Item>0)
        status=false;
else 
        status=true;
return status;
}
int size(){return Item;}
bool isFull()               
{
return false;
}
};
class Message
{
public:
char sender[20],recipient[20],content[100],date[10];
Message()
{
strcpy(sender," ");
strcpy(recipient," ");
strcpy(content," ");
strcpy(date,"00/00/0000");
}
Message(char* se,char* re,char* cont,char* da)
{
        strcpy(sender,se);
        strcpy(recipient,re);
        strcpy(content,cont);
        strcpy(date,da);
        }
char* getDate()
{
    return date;
    }
};

class MessageSender
{
      public:
      void sendMessage(char* send,char* re,char* cont,char* da,Queue q)
      {
           Message m(send,re,cont,da);
           if(!q.isFull())
           {
                          q.add(m);
                          cout<<"Message is placed in queue.";
           }
           else cout<<"Cannot send - Queue 's full.";
      }
};

            

class MessageReceiver
{
      public:
      void receiveMessage(Que q)
      {
           Message m=q.remove();
           if(strcmp(m.sender," ")!=0)
           {
                      cout<<"Date: "<<m.getDate()<<endl;
                      cout<<"From: "<<m.sender<<endl;
                      cout<<"To: "<<m.recipient<<endl;
                      cout<<"Content:"<<m.content<<endl;
           }
           else
                      cout<<"No messages to receive.";
      }
      void showQueue(Queue q)
      {
           Message m;
           cout<<"Queue contains "<<q.size()<<" messages"<<endl;
           if(q.isEmpty()==true)
                          cout<<"Queue is empty.";
           else
           {
               Node *currNode=q.front;
               while(currNode)
               {
                              m=currNode->data;
                              cout<<m.getDate()<<"        From: "<<m.sender<<"        To: "<<m.recipient<<endl;
                              currNode=currNode->next;
               }
           }
      }
};
int main()
{
    Queue holder;
    MessageSender m1,m2,m3;
    m1.sendMessage("Munzir","Aimal","Assalamu'alaikum","20/09/2007",holder);
    m2.sendMessage("Rafay","Ali","What are u doing?","12/2/1999",holder);
    m3.sendMessage("Shahzaib","Huzaifa","hy","21/10/2022",holder);
    MessageReceiver m4;
    m4.receiveMessage(holder);
    m4.showQueue(holder);
    getchar();
    return 0;
}