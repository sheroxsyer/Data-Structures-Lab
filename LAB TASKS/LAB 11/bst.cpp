#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        int a;
        Node* left;
        Node* right;
        Node * root;
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
    Node* Insert(Node* root,int val);
    void remove(Node* root, int val);
    void inOrderTraversal(Node* root);
    void preOrderTraversal(Node* root);
    void postOrderTraversal(Node* root);
    void count(Node*node);
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
    countnode(root);

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
void BinarySearchTree :: countnode(Node* root){
{
    int a;
    int queue;
	if (!node)
		return 0;
	queue < Node *> a;
	
	int count = 0; 
    a.insert(node);
	while (!a.empty())
	{
		 Node *t = a;

		if (temp->left && temp->right)
			count++;
			
		if (temp->left != NULL)
			a.insert(temp->left);
		if (temp->right != NULL)
			a.insert(temp->right);
	}
    cout<<"Total nodes in BST are:"<<count<<endl;
	return count;
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