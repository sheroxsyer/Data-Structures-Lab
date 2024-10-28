#include<iostream>
using namespace std;
class node {
public:
    node* next;
    int data;
    node(int val) {
        data = val;
        next = NULL;
    }
};
class SingleLinkedList
{
private:
    node* head;
    int length;
public:
    SingleLinkedList() {
        head = NULL;
        length = 0;
    }
    // Insertion in Single Linklist
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
            length++;
        }
    }
    void insertAt(int pos, int val) {
            if (pos<1 || pos>length + 1) {
                cout << "Invalid position." << endl;
                return;
            }
            node* t = new node(val);
            if (pos == 1) { // When we want to inserting new node before  head..
                if (head == NULL)  // Head is Empty
                    head = t;        
                else { //head is already exist,  inserting new node before existing head..
                    t->next = head;
                    head = t;
                }
                length++;
            }
            else { // position can be in center or in last
                node* curr = head;
                node* pre = head;
                for (int i = 1; i < pos-1; i++) {
                    pre = curr;
                    curr = curr->next;
                }
                pre->next = t;
                if (curr != NULL) // If its not a Last node
                    t->next = curr;
                length++;
            }
    }
    // What about insert through Recursion.... ???
    // Printing
    void printing() {
        cout << "Printing the Single Linked List" << endl;
        cout << "Head---> ";
        node* curr = head;
        while (curr != NULL) {
            cout << curr->data << "---> ";
            curr = curr->next;
        }
        cout << "NULL";
    }
    // Removing Node from List
    // What about removing node through Recursion.... ???
    void removeAt(int pos) {
        node* curr = head;
        if (head == NULL) {
            cout << "LIST is empty " << endl;
            return;
        }
        if (pos == 1) {  // for deleting head
            head = curr->next;
            delete curr;
            length--;
        }
        else {   // for deleting any other node
            node* temp = NULL;
            for (int i = 0; i < pos - 1; i++) {
                temp = curr;
                curr = curr->next;
            }
            temp->next = curr->next;
            curr->next = NULL;
            delete curr;
            length--;
        }
    }
    int size() {
        return length;
    }
    node* getHead() {
        node* curr = head;
        return curr;
    }
    void duplicates()
    {
        node *curr=head;
        int count;
        count = 0;
        if(head = NULL)
        {
            cout<<"List is empty"<<endl;
            return;
        }
        else
        {
            while(curr != NULL)
            {
                cout<<curr->data<<"------>";
                curr= curr->next;
            }
            if(curr->next->data ==curr->next->next->data)
            {
                for(int i=0;i<curr->data;i++)
                {
                    cout<<curr->data<<" --------->";
                    curr=curr->next;
                    count++;
                }
                cout<<"No of duplicates "<<count;
                
            }

        }
    }
};


int main() {
    SingleLinkedList obj;
    obj.insert(11);
    obj.insert(12);
    obj.insert(11);
    obj.insert(14);
    obj.insert(11);
    obj.insert(16);
    obj.insert(17);
    obj.insert(18);
    obj.printing();
    obj.duplicates();

    return 0;
}