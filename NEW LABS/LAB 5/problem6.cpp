#include <iostream>
using namespace std;
class Circularlinkedlist
{
    class node
    {
    public:
        node *next;
        node *previous;
        int data;
        node(int val)
        {
            data = val;
            next = previous = NULL;
        }
    };

private:
    node *head;
    int length;

public:
    Circularlinkedlist()
    {
        head = NULL;
        length = 0;
    }
    int size()
    {
        return length;
    }
    void setsize(int l)
    {
        this->length = l;
    }
    node *gethead()
    {
        node *curr = head;
        return curr;
    }
    void insert(int val)
    {
        node *t = new node(val);
        if (head == NULL)
        {
            head = t;
            length++;
        }
        else
        {
            node *curr = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = t;
            t->previous = head;
            length++;
        }
    }
    // void insertAt(int pos, int val)
    // {
    //     if (pos < 1 || pos > length + 1)
    //     {
    //         cout << "invalid position" << endl;
    //         return;
    //     }
    //     node *t = new node(val);
    //     if (pos == 1)
    //     {
    //         if (head == NULL)
    //         {
    //             head = t;
    //             length++;
    //         }
    //         else
    //         {
    //             t->next = head;
    //             head->previous = t;
    //             head = t;
    //             length++;
    //         }
    //     }
    //     else
    //     {
    //         node *curr = head;
    //         for (int i = 1; i < pos-1; i++)
    //         {
    //             curr = curr->next;
    //         }
    //         t->next = curr->next;
    //         t->previous = curr;
    //         if (curr->next != NULL)
    //         {
    //             curr->next->previous = t;
    //         }
    //         curr->next = t;
    //         length++;
    //     }
    // }
        void removeAt(int pos)
        {
            node *curr = head;
            if (head == NULL)
            {
                cout << "list is empty" << endl;
            }
            if (pos == 1)
            {
                head = curr->next;
                head->previous = curr;
                delete curr;
                curr = NULL;
                length--;
            }
            else
            {
                node *temp = NULL;
                for (int i = 1; i < pos; i++)
                {
                    temp = curr;
                    curr = curr->next;
                }
                temp->next = curr->next;
                if (curr->next != head)
                {
                    curr->next->previous = temp;
                }
                delete curr;
                curr = NULL;
                length--;
            }
        
    }
        void print()
        {
            node *curr = head;
            while (curr->next != head)
            {
                cout << curr->data << "\t" << endl;
                curr = curr->next;
            }
            cout << curr->data << "\t" << endl;
        }
    };
    int main()
    {
        Circularlinkedlist list1;
        list1.insert(100);
        list1.insert(1);
        list1.insert(2);
        list1.insert(3);
        list1.insert(4);
        list1.removeAt(4);
        list1.print();
        return 0;
    }