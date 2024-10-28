#include<iostream>
using namespace std;
class node {
	public:
		node *next;
		node * prev;
        node * curr;
		int data;

        

		node(int val) {
			data= val;
			next= prev=NULL;
		}

        
};


class DoubleLinkedList {
	private:
		node *head;
		int length;

	public:
		DoubleLinkedList() {
			head= NULL;
			length=0;
		}
        void print();
        void insertAtpos();
        void remove();
        void head();

        void head(){
            node*curr=head;
            curr = head;
        }



		void print(){
            
            node*curr=head;

            
            if(length>0)
            {
                node*curr = head;
                //head();
                for (int i=0;i<length;i++)
                {
                cout<<*curr++<<endl;
            }
            }
            else{
                cout<<"Empty"<<endl;
            }


}

void insertAtpos(int val,int pos){
    node*n=new node(val);
    if(pos == 1)
    {
        n->next=head;
        head->prev=n;
        head=n;

    }
    else{
        node*curr = head;
        for(int i =1;i<(pos-1);i++)
        curr = curr->next;
        n->next=curr->next;
        n->prev =curr;
        curr->next->prev=n;
        curr->next=n;
    }
    length++;
    
}

void remove(int pos){
    node*curr=head;
    if(pos==1)
    {
        head=head->next;
        delete curr;

    }
    else{
        node*prev=NULL;
        for(int i = 1;i<pos;i++)
        {
            prev = curr;
            curr = curr->next;
            prev->next=curr->next;
            curr->next=prev->prev;
            delete curr;
        }
        length--;
    }
}

	};
	
int main (){
    //head->data= 1;
	//head->next=NULL;
    
    void insertAtpos(1,1);
    void insertAtpos(1,2);
    void print();
	
	return 0;
}