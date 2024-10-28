#include<iostream>
using namespace std;
  
struct Node
{
   int data;
   struct Node *next;
};
struct Node *insert(struct Node *end, int data)
{
   if (end != NULL)
   return end;
  
   struct Node *temp = new Node;
  
   temp -> data = data;
   end = temp;
  
   end->next = end;
  
   return end;
}
struct Node *insertAtBegin(struct Node *end, int data)
{
   if (end == NULL)
   return insert(end, data);
  
   struct Node *temp = new Node;
  
   temp -> data = data;
   temp -> next = end -> next;
   end -> next = temp;
  
   return end;
}
struct Node *insertAtEnd(struct Node *end, int data)
{
   if (end == NULL)
   return insert(end, data);
  
   struct Node *temp = new Node;
  
   temp -> data = data;
   temp -> next = end -> next;
   end -> next = temp;
   end = temp;
  
   return end;
}
  
struct Node *insertAfter(struct Node *end, int data, int item)
{
   if (end == NULL)
   return NULL;
  
   struct Node *temp, *p;
   p = end -> next;
   do
   {
      if (p ->data == item)
      {
         temp = new Node;
         temp -> data = data;
         temp -> next = p -> next;
         p -> next = temp;
        
         if (p == end)
         end = temp;
         return end;
       }
   p = p -> next;
 } while(p != end -> next);
  
   cout << "The node with data "<<item << " is not present in the list." << endl;
   return end;
  
}
void traverse(struct Node *end) {
   struct Node *p;
  
   if (end == NULL) {
      cout << "List is empty." << endl;
      return;
      }
p = end -> next; 
do {
      cout << p -> data << "==>";
      p = p -> next;
      } while(p != end->next);
   if(p == end->next)
   cout<<p->data;
   cout<<"\n\n";
   }
  
void deleteAtend(Node** head, int key)
{
   if (*head == NULL)
   return;
  
   if((*head)->data==key && (*head)->next==*head) {
      free(*head);
      *head=NULL;
      }
Node *end=*head,*d;
  
if((*head)->data==key) {
   while(end->next!=*head) 
   end=end->next;
  
   end->next=(*head)->next;
   free(*head);
   *head=end->next;
   }
  
while(end->next!=*head&&end->next->data!=key) {
   end=end->next;
}
if(end->next->data==key) {
      d=end->next;
      end->next=d->next;
      cout<<"The node with data "<<key<<" deleted from the list"<<endl;
      free(d);
      cout<<endl;
      cout<<"Circular linked list after deleting "<<key<<" is :"<<endl;
      traverse(end);
      }
   else
   cout<<"The node with data "<< key << " not found in the list"<<endl;
   }
 void showMenu();



int main()
{
    
   struct Node *end = NULL;
  
   end = insert(end, 30);
   end = insertAtBegin(end, 20);
   end = insertAtBegin(end, 10);
   end = insertAtEnd(end, 40);
   end = insertAtEnd(end, 60);
   end = insertAfter(end, 50,40 );
   cout<<"The circular linked list is:"<<endl;
   traverse(end);
   deleteAtend(&end,10);
   return 0;
}