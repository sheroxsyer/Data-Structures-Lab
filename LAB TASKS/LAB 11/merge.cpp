#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data){
            this->data=data;
            left= right=NULL;
        }
};

class BinarySearchTree{
    public:
    Node* root;
    BinarySearchTree(){
        root=NULL;
    }
    Node* Insert1(Node* root,int val);
    void remove1(Node* root, int val);
    void inOrderTraversal1(Node* root);
    void preOrderTraversal1(Node* root);
    void postOrderTraversal1(Node* root);
    Node* Insert2(Node* root,int val);
    void remove2(Node* root, int val);
    void inOrderTraversal2(Node* root);
    void preOrderTraversal2(Node* root);
    void postOrderTraversal2(Node* root);
    void mergeBST();
    void insert(Node ** head_ref, int new_data);
};
class BinarySearchTree{
    public:
    Node* root;
    BinarySearchTree(){
        root=NULL;
    }
    Node* Insert1(Node* root,int val);
    void remove1(Node* root, int val);
    void inOrderTraversal1(Node* root);
    void preOrderTraversal1(Node* root);
    void postOrderTraversal1(Node* root);
    Node* Insert2(Node* root,int val);
    void remove2(Node* root, int val);
    void inOrderTraversal2(Node* root);
    void preOrderTraversal2(Node* root);
    void postOrderTraversal2(Node* root);
    void mergeBST(Node *first, Node **second);
};
int main (){
    BinarySearchTree tree;
    tree.Insert1(tree.root, 10);
    tree.Insert1(tree.root, 8);
    tree.Insert1(tree.root, 6);
    tree.Insert1(tree.root, 9);
    tree.Insert1(tree.root, 15);
    tree.Insert1(tree.root, 14);
    tree.Insert1(tree.root, 20);

    cout<<"\n        In-Order"<<endl;
    cout<<"Left ---- Root ---- Right"<<endl;
    tree.inOrderTraversal1(tree.root);


    cout<<"\n        Pre-Order"<<endl;
    cout<<"Root ---- Left ---- Right"<<endl;
    tree.preOrderTraversal1(tree.root);

    cout<<"\n        Post-Order"<<endl;
    cout<<"Left ---- Right ---- Root"<<endl;
    tree.postOrderTraversal1(tree.root);

    tree.Insert2(tree.root, 8);
    tree.Insert2(tree.root, 6);
    tree.Insert2(tree.root, 3);
    tree.Insert2(tree.root, 10);
    cout<<"\n        In-Order"<<endl;
    cout<<"Left ---- Root ---- Right"<<endl;
    tree.inOrderTraversal2(tree.root);


    cout<<"\n        Pre-Order"<<endl;
    cout<<"Root ---- Left ---- Right"<<endl;
    tree.preOrderTraversal2(tree.root);

    cout<<"\n        Post-Order"<<endl;
    cout<<"Left ---- Right ---- Root"<<endl;
    tree.postOrderTraversal2(tree.root);
    return 0;
}
Node* BinarySearchTree::Insert1(Node * r, int val){
   
    if (r==NULL){
        Node* t= new Node(val);
        if (r==root)
        {
            root=r=t;
            }
        else
        {
            r=t;
        }
        return r;
    }
    else if (val==r->data){
        cout<<" Duplicate Data: "<< val<<endl;
    }
    else if (val < r->data){
        r->left= Insert1(r->left, val);
    }
    else if (val > r->data){
        r->right= Insert1(r->right, val);
    }
   
   
}
Node* BinarySearchTree::Insert2(Node * r, int val){
   
    if (r==NULL){
        Node* t= new Node(val);
        if (r==root)
        {
            root=r=t;
            }
        else
        {
            r=t;
        }
        return r;
    }
    else if (val==r->data){
        cout<<" Duplicate Data: "<< val<<endl;
    }
    else if (val < r->data){
        r->left= Insert2(r->left, val);
    }
    else if (val > r->data){
        r->right= Insert2(r->right, val);
    }
   
   
}

void BinarySearchTree::inOrderTraversal1(Node* r){
    if (r==NULL)
      return ;
    inOrderTraversal1(r->left);
    cout<<" "<< r->data <<" -> ";
    inOrderTraversal1(r->right);
}
void BinarySearchTree::inOrderTraversal2(Node* r){
    if (r==NULL)
      return ;
    inOrderTraversal2(r->left);
    cout<<" "<< r->data <<" -> ";
    inOrderTraversal2(r->right);
}
void BinarySearchTree::preOrderTraversal1(Node* r){
    if (r==NULL)
      return ;
     
    cout<<" "<< r->data <<" -> ";
    inOrderTraversal1(r->left);
    inOrderTraversal1(r->right);
}
void BinarySearchTree::preOrderTraversal2(Node* r){
    if (r==NULL)
      return ;
     
    cout<<" "<< r->data <<" -> ";
    inOrderTraversal2(r->left);
    inOrderTraversal2(r->right);
}
void BinarySearchTree::postOrderTraversal1(Node* r){
    if (r==NULL)
      return ;  
    inOrderTraversal1(r->left);
    inOrderTraversal1(r->right);
    cout<<" "<< r->data <<" -> ";
}
void BinarySearchTree::postOrderTraversal2(Node* r){
    if (r==NULL)
      return ;  
    inOrderTraversal2(r->left);
    inOrderTraversal2(r->right);
    cout<<" "<< r->data <<" -> ";
}
void BinarySearchTree ::mergeBST(Node *first, Node **second){  
{  
    Node *firstRef = first;  
    
    while (firstRef->data != NULL)  
    {  
         firstRef = firstRef->data;
    }  
   
    firstRef->data = *second;
}
}

void BinarySearchTree :: insert(Node ** head_ref, int new_data)  
{  
    Node* new_node = new node(); 
    new_node->data = new_data;  
    new_node->data = (*head_ref);  
    (*head_ref) = new_node;  
}  


    
