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
    node* head1;
    node* head2;
    int length;
public:
    SingleLinkedList() {
        head1 = NULL;
        head2 = NULL;
        length = 0;
    }
    // Insertion in Single Linklist
    void insert_1(int val) {
        node* t = new node(val);
        if (head1 == NULL) { // Head is Empty
            head1 = t;
            length++;
        }
        else {
            node* curr = head1;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = t;
            length++;
        }
    }
    void insertAt_1(int pos, int val) {
            if (pos<1 || pos>length + 1) {
                cout << "Invalid position." << endl;
                return;
            }
            node* t = new node(val);
            if (pos == 1) { // When we want to inserting new node before  head..
                if (head1 == NULL)  // Head is Empty
                    head1 = t;        
                else { //head is already exist,  inserting new node before existing head..
                    t->next = head1;
                    head1 = t;
                }
                length++;
            }
            else { // position can be in center or in last
                node* curr = head1;
                node* pre = head1;
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
    void printing_1() {
        cout << "Printing the Single Linked List" << endl;
        cout << "Head---> ";
        node* curr = head1;
        while (curr != NULL) {
            cout << curr->data << "---> ";
            curr = curr->next;
        }
        cout << "NULL";
    }
    // Removing Node from List
    // What about removing node through Recursion.... ???
    void removeAt_1(int pos) {
        node* curr = head1;
        if (head1 == NULL) {
            cout << "LIST is empty " << endl;
            return;
        }
        if (pos == 1) {  // for deleting head
            head1 = curr->next;
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
    node* getHead_1() {
        node* curr = head1;
        return curr;
    }
    // Insertion in Single Linklist
    void insert_2(int val) {
        node* t = new node(val);
        if (head2 == NULL) { // Head is Empty
            head2 = t;
            length++;
        }
        else {
            node* curr = head2;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = t;
            length++;
        }
    }
    void insertAt_2(int pos, int val) {
            if (pos<1 || pos>length + 1) {
                cout << "Invalid position." << endl;
                return;
            }
            node* t = new node(val);
            if (pos == 1) { // When we want to inserting new node before  head..
                if (head2 == NULL)  // Head is Empty
                    head2 = t;        
                else { //head is already exist,  inserting new node before existing head..
                    t->next = head2;
                    head2 = t;
                }
                length++;
            }
            else { // position can be in center or in last
                node* curr = head2;
                node* pre = head2;
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
    void printing_2() {
        cout << "Printing the Single Linked List" << endl;
        cout << "Head---> ";
        node* curr = head2;
        while (curr != NULL) {
            cout << curr->data << "---> ";
            curr = curr->next;
        }
        cout << "NULL";
    }
    // Removing Node from List
    // What about removing node through Recursion.... ???
    void removeAt_2(int pos) {
        node* curr = head2;
        if (head2 == NULL) {
            cout << "LIST is empty " << endl;
            return;
        }
        if (pos == 1) {  // for deleting head
            head2 = curr->next;
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
    node* getHead_2() {
        node* curr = head2;
        return curr;
    }
    void concatenate()
        {
        node*curr;
        if(head1 == NULL)
        {
            cout<<"list is empty"<<endl;
        }
        else
        {
            curr = head1;
            while(curr->next != NULL)
            {
                cout<<curr->data<<endl;
                curr = curr->next;
            }
            curr->next=head2;
            while(curr->next != NULL)
            {
                cout<<curr->data<<endl;
                curr = curr->next;
            }
        }
    }

    
};


int main() {
    SingleLinkedList obj;
    obj.insert_1(11);
    obj.insert_1(12);
    obj.insert_1(13);
    obj.insert_1(14);
    obj.printing_1();
    obj.insert_2(15);
    obj.insert_2(16);
    obj.insert_2(17);
    obj.insert_2(18);
    obj.printing_2();
    obj.concatenate();

    return 0;
}
