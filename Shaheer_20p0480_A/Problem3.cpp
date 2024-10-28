// Binary Search Tree Implementation..  
#include<iostream>
using namespace std;
class Node {
	public:
	int data;
	Node* left;	
	Node* right;
	Node(int data){
		this->data=  data;
		left= right= NULL;
	}
}; 
class BinarySearchTree{
	public:
	Node* root;
	BinarySearchTree(){
		root= NULL;
	}
	Node* insert( Node* root, int val);
	Node* inOrderTraversal( Node* root);
	int  findParent(Node* root);
};

int main (){
	BinarySearchTree tree1;
  	tree1.insert(tree1.root,10);
    tree1.insert(tree1.root, 8);
    tree1.insert(tree1.root, 6);
    tree1.insert(tree1.root, 9);
    tree1.insert(tree1.root, 15);
    tree1.insert(tree1.root, 14);
    tree1.insert(tree1.root, 20);
	cout<<"In Order Print (left--Root--Right)"<<endl;
	tree1.inOrderTraversal(tree1.root);
	cout<<"Parent nodes are : "<< tree1.findParent(tree1.root);
	tree1.findParent(tree1.root);	
	return 0;
}

Node* BinarySearchTree::insert(Node* r, int val ){
	
 if (r==NULL)
	{
		Node* t= new Node(val);		
		if (r==root)
		root= r=t;
		else
		r=t;		
		return r;
	}
//	else if (r->data== val){
//		//cout<<"Duplicate Record  "<<val;
//			return r;
//	}
	else if (val < r->data) 
		r->left = insert(r->left , val );
	
	else if (val > r->data)
		r->right= insert( r->right,val);
}
Node * BinarySearchTree::inOrderTraversal( Node* r){
	 if (r == NULL)
        return NULL;
    inOrderTraversal(r->left);
    cout << " "<< r->data << " -> ";
    inOrderTraversal(r->right);  
}
int  BinarySearchTree :: findParent(Node *r)
{
	int static count = 0;
	if (r==NULL)
		return 0;
	
				
		else if (r->left < root && r->right > root)
		
		r->left->data < r->data   && r->right->data > r->data;
		{
		return 1;
		}
		
		return count + findParent(r->left) + findParent(r->right);
		cout<<"Parent nodes are : "<<endl;


}


