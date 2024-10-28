
#include<iostream>
using namespace std;
    class node {
    public:
    int data;
    node* left, *right;
    node(int data){
        this->data=  data;
        left= right= NULL;
        }
    };
   
class BinarySearchTree{
    private:
    //node class

    //private data members and methods
    node* root;
    node* Insert( node* root, int val);
    node* Delete(node* root,int data);
    node* InOrderTraversal( node* root);
    node* FindSmallestKthNode(node* root,int k);
    node* FindMax(node* root);
    node* DeleteNodeInBST(node* root,int data);
    int CountNodes(node* root);
    node* RemoveNodesinRange(node* root, int Left, int Right);
    public:
    BinarySearchTree(){
        root= NULL;
    }
    void    Insert(int val){
       
       Insert(this->root,  val);
   }
   
    void    Delete(int val){
   Delete(this->root, val);
   }

    void  DeleteNodeInBST(int val){
        DeleteNodeInBST(this->root,val);
    }
    void FindSmallestKthNode(int k){
        node* result = FindSmallestKthNode(root, k);
        if (result != NULL) {
            cout << "The " << k << "th smallest node in the BST is: " << result->data << endl;
        } else {
            cout << "The BST does not have " << k << " nodes." << endl;
        }
    }
    void InOrderTraversal(){
        InOrderTraversal( this->root);
    }
     int CountNodes(){
        return CountNodes(root);
    }
    void RemoveNodesinRange(int Left, int Right){
        root = RemoveNodesinRange(root, Left, Right);
    }

    
};
int main (){
    BinarySearchTree tree1;
      tree1.Insert(10);
    tree1.Insert(8);
    tree1.Insert(6);
    tree1.Insert(9);
    tree1.Insert(15);
    tree1.Insert(14);
    tree1.Insert(20);
    tree1.Delete(10);
    cout<<"In Order Print (left--Root--Right)"<<endl;
    tree1.InOrderTraversal();
    cout<<"\n-----------------------"<<endl;
    
    tree1.DeleteNodeInBST(15);
    cout<<"After deleting specific node:"<<endl;
    tree1.InOrderTraversal();

    int k = 4;
    cout<<"kth element is:"<<endl;
    tree1.FindSmallestKthNode(k);

    

    tree1.RemoveNodesinRange(8, 15);
    
    cout << "In-order traversal of trimmed tree: ";
    tree1.InOrderTraversal();
    cout << endl;   
    return 0;
}
node* BinarySearchTree::Insert(node* r, int val ){
 if (r==NULL)
    {
        node* t= new node(val);
        if (r==root)
            root=t;
        else
        r=t;
    }
    else if (r->data== val){
        cout<<"Record already exist"<<val;
    }
    else if (val < r->data) // insert on left s
    r->left = Insert(r->left , val );
    else if (val > r->data)
        r->right= Insert( r->right,val);
    return r;
}
node * BinarySearchTree::Delete(node* r, int data)
{
//    node * r= root1;
    if(r==NULL)
     return r;
    else if(data < r->data)
        r->left = Delete(r->left, data);
    else if (data> r->data)
        r->right = Delete(r->right, data);
    else
    {
        //No child
        if(r->right == NULL && r->left == NULL)
        {
            delete r;
            r = NULL;  
            return r;
        }
        //One child on left
        else if(r->right == NULL)
        {
            node* temp = r;
            r= r->left;
            delete temp;
        }
        //One child on right
        else if(r->left == NULL)
        {
            node* temp = r;
            r= r->right;
            delete temp;
        }
        //two child
        else
        {
            node* temp = FindMax(root->left);
            root->data = temp->data;
            r->left = Delete(root->left, temp->data);
        }
    }
    return r;
}
node * BinarySearchTree::InOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
    //first recur on left child
    InOrderTraversal(r->left);
   //then print the data of node
    cout << " "<< r->data << " -> ";
  // now recur on right child
    InOrderTraversal(r->right);
}

node* BinarySearchTree::FindMax(node* r){    
    while(r->right!=NULL){
        r= r->right;
    }
    return r;    
}

node * BinarySearchTree::DeleteNodeInBST(node* root, int data)
{
   
    if(root==NULL)
     return root;
    else if(data<root->data)
        root->left = DeleteNodeInBST(root->left, data);
    else if (data> root->data)
        root->right = DeleteNodeInBST(root->right, data);
    else
    {
        //No child
        if(root->right == NULL && root->left == NULL)
        {
            delete root;
            root = NULL;  
            return root;
        }
        //One child on left
        else if(root->right == NULL)
        {
            node* temp = root;
            root= root->left;
            delete temp;
        }
        //One child on right
        else if(root->left == NULL)
        {
            node* temp = root;
            root= root->right;
            delete temp;
        }
        //two child
        else
        {
            node* temp = FindMax(root->left);
            root->data = temp->data;
            root->left = DeleteNodeInBST(root->left, temp->data);
        }
    }
    return root;
}
int BinarySearchTree::CountNodes(node * root)
{
    if (root == NULL) {
        return 0;
    }
    return 1 + CountNodes(root->left) + CountNodes(root->right);
} 

node* BinarySearchTree::FindSmallestKthNode(node* root, int k) {
    // Count nodes
    int Count = CountNodes(root->left);

    // If k is less than or equal to nodes 
    if (k <= Count) {
        return FindSmallestKthNode(root->left, k);
    } 
    // If k is equal to the nodes,
    // then return the node
    else if (k == Count + 1) {
        return root;
    } 
    // If k is greater than the nodes,

    
    else {
        return FindSmallestKthNode(root->right, k - Count - 1);
    }
}

node* BinarySearchTree::RemoveNodesinRange(node* root, int Left, int Right) {
    if (root == NULL) {
        return root;
    }
    // If node is outside range retun then
    if (root->data < Left) {
        return RemoveNodesinRange(root->right, Left, Right);
    }
    if (root->data > Right) {
        return RemoveNodesinRange(root->left, Left, Right);
    }
    // If node is range then trim from left and right
    root->left = RemoveNodesinRange(root->left, Left, Right);
    root->right = RemoveNodesinRange(root->right, Left, Right);
    return root;
}
