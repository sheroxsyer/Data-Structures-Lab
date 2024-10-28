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
		Node *newNode
        }
};

class BinarySearchTree{
    public:
    Node* root;
    BinarySearchTree(){
        root=NULL;
    }
    Node* Insert(Node* root,int val);
    void remove(Node* root, int val);
    void inOrderTraversal(Node* root);
    void preOrderTraversal(Node* root);
    void postOrderTraversal(Node* root);
	int countLeaf();
};
int main (){
    BinarySearchTree tree;
    tree.Insert(tree.root, 10);
    tree.Insert(tree.root, 8);
    tree.Insert(tree.root, 6);
    tree.Insert(tree.root, 9);
	tree.Insert(tree.root, 15);
    tree.Insert(tree.root, 14);
    tree.Insert(tree.root, 20);
    
    cout<<"\n        In-Order"<<endl;
    cout<<"Left ---- Root ---- Right"<<endl;
    tree.inOrderTraversal(tree.root);


    cout<<"\n        Pre-Order"<<endl;
    cout<<"Root ---- Left ---- Right"<<endl;
    tree.preOrderTraversal(tree.root);

    cout<<"\n        Post-Order"<<endl;
    cout<<"Left ---- Right ---- Root"<<endl;
    tree.postOrderTraversal(tree.root);
	tree.countLeaf();
cout << "Leaf of BST is : "<<countLeaf() << endl;
    return 0;
}
Node* BinarySearchTree::Insert(Node * r, int val){
   
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
        r->left= Insert(r->left, val);
    }
    else if (val > r->data){
        r->right= Insert(r->right, val);
    }
   
   
}

void BinarySearchTree::inOrderTraversal(Node* r){
    if (r==NULL)
      return ;
    inOrderTraversal(r->left);
    cout<<" "<< r->data <<" -> ";
    inOrderTraversal(r->right);
}
void BinarySearchTree::preOrderTraversal(Node* r){
    if (r==NULL)
      return ;
     
    cout<<" "<< r->data <<" -> ";
    inOrderTraversal(r->left);
    inOrderTraversal(r->right);
}
void BinarySearchTree::postOrderTraversal(Node* r){
    if (r==NULL)
      return ;  
    inOrderTraversal(r->left);
    inOrderTraversal(r->right);
    cout<<" "<< r->data <<" -> ";
}


int BinarySearchTree :: countLeaf(Node* node)
{
	Node* left;
    Node* right;
	if(node == NULL){
		cout<<"empty BST"<<endl;
	}	
		return 0;

	if(node->left == NULL && node->right == NULL)
		return 1;		
	else
		return countLeaf(node->left)+
			countLeaf(node->right);
}
