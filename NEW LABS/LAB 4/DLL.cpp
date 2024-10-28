#include<iostream>
using namespace std;
class DoubleLinkedList {
    class node
    {
        public:
    node* next;
    node*prev;
    int data;
    node(int val) {
        data = val;
        next =prev= NULL;
    }
};

private:
    node* head;
    int length;
public:
    DoubleLinkedList() {
        head = NULL;
        length = 0;
    }
    int size()
    {
        return length;
    }
    void setSize(int l)
    {
        this->length =l;

    }
    node*getHead()
    {
        node*curr = head;
        return curr;
    }

    void insert(int val) {
        node* t = new node(val);
        if (head == NULL) { // Head is Empty
            head = t;
            length++;
        }
        else {
            node* curr = head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = t;
            t->prev = curr;
            length++;
        }
    }
    void print() {
        
        cout << "Printing the Single Linked List" << endl;
        cout << "Head---> ";
        node* curr = head;
        while (curr->next) {
            cout << curr->data << "\t "<<endl;
            curr = curr->next;
        }
        cout << curr->data<<"\t"<<endl;
    }
    void removeAt(int pos) 
    {
        node* curr = head;
        if (head == NULL) {
            cout << "LIST is empty " << endl;
        }
        if (pos == 1) {  // for deleting head
            head = curr->next;
            head->prev=NULL;
            delete curr;
            curr = NULL;
            length--;
        }
        else {   // for deleting any other node
            node* temp = NULL;
            for (int i = 1; i < pos; i++) {
                temp = curr;
                curr = curr->next;
            }
            temp->next = curr->next;
            if(curr->next != NULL)

            curr->next->prev = temp;

            delete curr;
            curr = NULL;
            length--;
        }
    }


    // void insertAt(int pos, int val) 
    // {
    //         if (pos<1 || pos>length + 1) 
    //         {
    //             cout << "Invalid position." << endl;
    //             return;
    //         }
    //         node* t = new node(val);
    //         if (pos == 1) 
    //         { // When we want to inserting new node before  head..
    //             if (head == NULL)  // Head is Empty
    //                 head = t;
    //                 length++;
    //         }

    //             else 
    //             { //head is already exist,  inserting new node before existing head..
    //                 t->next = head;
    //                 head->prev=t;
    //                 head = t;
    //                 length++;
    //             }
                
    //         }
    //         else 
    //         { // position can be in center or in last
    //             node* curr = head;
                
    //             for (int i = 1; i < pos; i++) 
    //             {
                    
    //                 curr = curr->next;
    //             }
    //             t->next=curr->next;
    //             t->prev=curr;

                
    //             if (curr->next  != NULL) // If its not a Last node
    //                 curr->next->prev=t;
    //                 curr->next=t;
    //             length++;
    //         }
    // };
    
    // Removing Node from List
    // What about removing node through Recursion.... ???
    
    
    
    
    
    
};


int main() {
    DoubleLinkedList list1;
    list1.insert(100);
    // list1.insertAt(1,1);
    // list1.insertAt(2,2);
    // list1.insertAt(3,3);
    // list1.insertAt(4,4);
    
    list1.removeAt(4);
    list1.print();

    return 0;
}