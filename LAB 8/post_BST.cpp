
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
  
    node* root;
    node* Insert( node* root, int val);
    node* Delete(node* root,int data);
    int CountNodes (node* root);
    node* InOrderTraversal( node* root);
    node* PostOrderTraversal( node* root);
    node* FindMax(node* root);
    node* FindSmall(node* root);
    // node *search(int , node*const& );
    node* searchBST(node*root,int val);
    node* getSubtree(node* root, int key);
    void floorCeil(node* root, int key, int& floor, int& ceil);
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
    void InOrderTraversal(){
        InOrderTraversal( this->root);
    }
    void PostOrderTraversal(){
        PostOrderTraversal( this->root);
    }
    void FindSmall(){
        FindSmall(this->root);
    }
    int  CountNodes()
    {
        return CountNodes(this->root);
    }
    void searchBST(int val) {
    node* result = searchBST(root, val);
    if (result) {
        cout << "Found " << val << " in the tree." << endl;
    } else {
        cout << "Could not find " << val << " in the tree." << endl;
    }
}
void floorCeil(int key) {
        int floor = -1, ceil = -1;
        floorCeil(root, key, floor, ceil);
        if (floor == -1 && ceil == -1) {
            cout << "Key is not present in the tree" << endl;
        }
        else {
            cout << "Floor: " << floor << " Ceil: " << ceil << endl;
        }
    }
};
int main (){
    BinarySearchTree tree;
      tree.Insert(10);
    tree.Insert(8);
    tree.Insert(6);
    tree.Insert(9);
    tree.Insert(15);
    tree.Insert(14);
    tree.Insert(20);
    tree.Delete(10);
    cout<<"In Order Print (left--Root--Right)"<<endl;
    tree.InOrderTraversal();    
    cout<<"\n-----------------------"<<endl;
    cout<<"Post Order Print (left--Right--Root)"<<endl;
    tree.PostOrderTraversal();
    cout<<endl;
    cout<<"smallest node is :"<<endl;
    tree.FindSmall();
    cout<<"The total node in tree are: "<<endl;
    cout << "The total  node in tree are: " << tree.CountNodes() << endl; 
    // cout<<"The total number of nodes in the tree are: "<<endl;
    // tree.CountNodes();
    int value_to_search = 11;
    tree.searchBST(value_to_search);
    // cout<<"Searching is:"<<endl;
    // tree1.
    

    
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
    else if (val < r->data) 
    r->left = Insert(r->left , val );
    else if (val > r->data)
        r->right= Insert( r->right,val);
    return r;
}
node * BinarySearchTree::Delete(node* r, int data)
{

    if(r==NULL)
     return r;
    else if(data < r->data)
        r->left = Delete(r->left, data);
    else if (data> r->data)
        r->right = Delete(r->right, data);
    else
    {
        
        if(r->right == NULL && r->left == NULL)
        {
            delete r;
            r = NULL;  
            return r;
        }
        
        else if(r->right == NULL)
        {
            node* temp = r;
            r= r->left;
            delete temp;
        }
        
        else if(r->left == NULL)
        {
            node* temp = r;
            r= r->right;
            delete temp;
        }
        
        else
        {
            node* temp = FindMax(root->left);
            root->data = temp->data;
            r->left = Delete(root->left, temp->data);
        }
    }
    return r;
}


node* BinarySearchTree::FindMax(node* r){    
    while(r->right!=NULL){
        r= r->right;
    }
    
    return r;    
}
node* BinarySearchTree::FindSmall(node* r){    
    while(r->left!=NULL){
        r= r->left;
        cout<<r->left->data;
    }
    
    return r;    
}

node * BinarySearchTree::InOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
    
    InOrderTraversal(r->left);
    cout << " "<< r->data << " -> ";
    InOrderTraversal(r->right);
}

node* BinarySearchTree::PostOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
    PostOrderTraversal(r->left);
    PostOrderTraversal(r->right);    
    cout << " "<< r->data << " -> ";
}
int BinarySearchTree::CountNodes(node * r){
    
    if(r == NULL)
    { 
        return 0;
    }
       

    return  1 + CountNodes(r->left) + CountNodes(r->right);
}
// node *BinarySearchTree::search(int key , node * const &temp)
// {
//     if (root == nullptr)
//     {
//         cout<<"Tree is empty."<<endl;
//         return NULL;
//     }
    
//     if (key == temp->data)
//     {
//         return temp;
//     }
    
//     if ( (temp->left != NULL) && (key < temp->data) )
//     {
//         return search(key , temp->left );
//     }
    
//     if ( (temp->right != NULL) && (key > temp->data) )
//     {
//         return search(key , temp->right );
//     }
//     cout<<"Search not found."<<endl;
//     return NULL;
// }
// node*BinarySearchTree:: searchBST(node* r, int val) {
//         if (root == NULL) 
//         {
//             return NULL;
//         }
//          else if (root->data == val) {
//             return root;
//         }
//          else if (root->data > val) {
//             return searchBST(root->left, val);
//         } 
//         else 
//         {
//             return searchBST(root->right, val);
//         }
//     }
    node* searchBST(node* root, int key) 
    {
   if (root == NULL || root->data == key)
      return root;

   if (root->data < key)
      return searchBST(root->right, key);

   return searchBST(root->left, key);
}
node* getSubtree(node* root, int key) 
{
   node* node = searchBST(root, key);
   if (node == NULL)
      return NULL;

   return node;
}



node*BinarySearchTree::floorCeil(node* root, int key, int& floor, int& ceil) {
   if (root == NULL)
      return;

   if (root->data == key) {
      floor = root->data;
      ceil = root->data;
      return;
   }

   if (root->data > key) {
      ceil = root->data;
      floorCeil(root->left, key, floor, ceil);
   } else {
      floor = root->data;
      floorCeil(root->right, key, floor, ceil);
   }
}