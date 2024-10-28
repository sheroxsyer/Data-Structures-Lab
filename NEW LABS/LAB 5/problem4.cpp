#include <iostream>
using namespace std;
class Doublelinkedlist
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
    node *head1;
    node* head2;
    int length;

public:
    Doublelinkedlist()
    {
        head1 = head2=NULL;
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
    node *gethead1()
    {
        node *curr = head1;
        return curr;
    }
    node *gethead2()
    {
        node *curr = head2;
        return curr;
    }
    void insert1(int val)
    {
        node *t = new node(val);
        if (head1 == NULL)
        {
            head1 = t;
            length++;
        }
        else
        {
            node *curr = head1;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = t;
            t->previous = curr;
            length++;
        }
    }
    void insert2(int val)
    {
        node *t = new node(val);
        if (head2 == NULL)
        {
            head2 = t;
            length++;
        }
        else
        {
            node *curr = head2;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = t;
            t->previous = curr;
            length++;
        }
    }
            void removeAt1(int pos)
        {
            node *curr = head1;
            if (head1 == NULL)
            {
                cout << "list is empty" << endl;
            }
            if (pos == 1)
            {
                head1 = curr->next;
                head1->previous = NULL;
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
                if (curr->next != NULL)
                {
                    curr->next->previous = temp;
                }
                delete curr;
                curr = NULL;
                length--;
            }
        
    }
    void removeAt2(int pos)
        {
            node *curr = head2;
            if (head2 == NULL)
            {
                cout << "list is empty" << endl;
            }
            if (pos == 1)
            {
                head2 = curr->next;
                head2->previous = NULL;
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
                if (curr->next != NULL)
                {
                    curr->next->previous = temp;
                }
                delete curr;
                curr = NULL;
                length--;
            }
        
    }
        void print1()
        {
            node *curr = head1;
            while (curr->next)
            {
                cout << curr->data << "\t" << endl;
                curr = curr->next;
            }
            cout << curr->data << "\t" << endl;
        }
        void print2()
        {
            node *curr = head2;
            while (curr->next)
            {
                cout << curr->data << "\t" << endl;
                curr = curr->next;
            }
            cout << curr->data << "\t" << endl;
        }
        void evenodd()
        {
            
        }
    };
    int main()
    {
        Doublelinkedlist list1;
        list1.insert1(100);
        list1.insert1(1);
        list1.insert1(2);
        list1.insert2(3);
        list1.insert2(4);
        list1.removeAt2(4);
        list1.print1();
        list1.print2();
        return 0;
    }