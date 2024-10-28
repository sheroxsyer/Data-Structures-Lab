// Binary Search Tree Implementation..  
#include<iostream>
using namespace std;
    class node {
    public:
    int data;
    int sum;
    int count;
    int count1;
    int count2;
    node* left, *right;
    node(int data){
        this->data=  data;
        this->count1=NULL;
        this->count2=NULL;
        this->count=NULL;
        this->sum=count1+count2;

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
    node* PreOrderTraversal( node* root);
    node* PostOrderTraversal( node* root);
    node* FindMax(node* root);
    
    public:
    node* Mean();
    node* Median();
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
    void PreOrderTraversal(){
        PreOrderTraversal( this->root);
    }
    void PostOrderTraversal(){
        PostOrderTraversal( this->root);
    }
    // void Mean()
    // {
    //     Mean();
    // }
};
int main (){
    BinarySearchTree tree1, tree2;
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
    cout<<"Pre Order Print (Root--left--Right)"<<endl;
    tree1.PreOrderTraversal();    
    cout<<"\n-----------------------"<<endl;
    cout<<"Post Order Print (left--Right--Root)"<<endl;
    tree1.PostOrderTraversal();
    tree1.Mean();
    tree1.Median();
    return 0;
}
node *BinarySearchTree::Mean()
{
    node*r;
    int sum;
    int count1;
    int count2;
    int Mean;
    while(r->left!=NULL){
        r= r->left;
    }
    cout<<r<<endl;
    return r;
     count1++;

     while(r->right!=NULL){
        r= r->right;
    }
    cout<<r<<endl;
    return r;
     count2++;

     sum= count1 + count2;

     
     Mean = sum/2;

     cout<<"Mean of tree is "<<Mean<<endl;


}
node *BinarySearchTree::Median()
{
    node *r;
    int count;
    int median;
    count = NULL;
    while(r->left!=NULL){
        r= r->left;
    }
    cout<<r<<endl;
    return r;
     

     while(r->right!=NULL){
        r= r->right;
    }
    cout<<r<<endl;
    return r;

    count++;
    
    cout<<"Total no of nodes in tree is :"<<count<<endl;
    if(count %2 != 0)
    {
        cout<<"As it is odd"<<endl;
        median= count+1/2;
        cout<<"Median is :"<<median<<endl;


    }
    if(count %2 == 0 )
    {
        cout<<"As it is even "<<endl;
        median=count/2;
        cout<<"Median is:"<<median<<endl;


    }



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
node* BinarySearchTree::PreOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
   
    cout << " "<< r->data << " -> ";
    PreOrderTraversal(r->left);
    PreOrderTraversal(r->right);    
}
node* BinarySearchTree::PostOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
    PostOrderTraversal(r->left);
    PostOrderTraversal(r->right);    
    cout << " "<< r->data << " -> ";
}

