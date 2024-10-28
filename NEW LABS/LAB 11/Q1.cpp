// AVL Tree Implementation..  
#include<iostream>
using namespace std;
    class node {
    public:
    int data;
    node* left, *right;
    int height;
    node(int data){
        this->data=  data;
        left= right= NULL;
        height=0;
        }
    };    
class AVLTree{
    private:
    //private data member and methods
    node* root;
    node* Insert( node* root, int val);
    node* Delete(node* root,int data);
    node* PreOrderTraversal( node* root);
    node*InOrderTraversal(node*root);
    node* FindMax(node* root);
        // Rotation
    node* singleRightRotate(node* &t);
    node* singleLeftRotate(node* &t);
    node* doubleRightLeftRotate(node* &t);
    node* doubleLeftRightRotate(node* &t);
    int getBalance(node* t);
    
    node*BST_To_AVL();
    public:
    AVLTree(){
        root= NULL;
    }
    void    Insert(int val){
       root= Insert(this->root,  val);
   }
   
    void    Delete(int val){
    root = Delete(this->root, val);
   }
   void InOrderTraversal()
   {
    InOrderTraversal(this->root);
   }
    void PreOrderTraversal(){
        PreOrderTraversal( this->root);
    }
     int height(node* t)
    {
        return (t == NULL ? -1 : t->height);
    }
    
     
    int length(node* r){
        int  lh=0,rh=0;
        if(r==NULL)
         return -1;
        if(r->left!=NULL){
            lh++;
            lh+=length(r->left);
        }
        if(r->right!=NULL){
            rh++;
            rh+=length(r->right);
        }
        if(rh>lh) return rh;
        else return lh;
    }
   
    int treeHeight(node *t)
    {
    int static l_height=0;
    int static r_height=0;
    if (t == NULL)
        return -1;
    else
    {
    l_height = treeHeight(t->left);
       r_height = treeHeight(t->right);
        if (l_height > r_height)
            return (l_height + 1);
        else
            return (r_height + 1);
    }
    }

};
int main (){
    AVLTree tree1, tree2;
      tree1.Insert(1);
    tree1.Insert(2);
    tree1.Insert(3);
    tree1.Insert(4);
    tree1.Insert(5);
    tree1.Insert(6);
    tree1.Insert(7);
    tree1.Insert(8);
    tree1.Insert(9);
    tree1.Insert(10);
    //tree1.Delete(4);
    cout<<"Pre Order Print (Root--left--Right)"<<endl;
    tree1.PreOrderTraversal();    
    return 0;
}

node* AVLTree::Insert(node* t, int val ){
 if (t==NULL)
    {
         t= new node(val);
    }
    else if (t->data== val){
        cout<<"Record already exist"<<val<<endl;
    }
    else if (val < t->data) // insert on left s
    {
        t->left = Insert(t->left , val );
         int bf= height(t->left) - height(t->right);
            if(bf == 2)
            {
                if(val < t->left->data)
                    t = singleRightRotate(t);
                else
                    t = doubleLeftRightRotate(t);
            }
    }
    else if (val > t->data) // Right side
        {
        t->right= Insert( t->right,val);
       
        int bf=height(t->right) - height(t->left);
           
            if(bf == 2)
            {
                if(val > t->right->data)
                    t = singleLeftRotate(t);
                else
                    t = doubleRightLeftRotate(t);
            }
    }
    t->height = max(height(t->left), height(t->right))+1;
    return t;
}



node* BST_To_AVL( int Start_Node,int End_Node)
{
    int n;
    Start_Node =0;
    End_Node=n;
	
	if (Start_Node > End_Node)
		return NULL;

	
	int Mid_Node = (Start_Node + End_Node)/2;
	node *root = InOrderTraversal(Mid_Node);

	
	root->left = BST_To_AVL( Start_Node, Mid_Node-1);
	root->right = BST_To_AVL( Mid_Node+1, End_Node);

	return root;
}


node* AVLTree::doubleRightLeftRotate(node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }
   
   
node* AVLTree::doubleLeftRightRotate(node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }
   
node* AVLTree::singleRightRotate(node* &t)
    {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    }
node* AVLTree::singleLeftRotate(node* &t)
    {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->right), t->height)+1 ;
        return u;
    }
   
node * AVLTree::Delete(node* r, int data)
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
            node* temp = FindMax(r->right);
            int x= r->data;  //
            r->data = temp->data;
            temp->data= x;
            r->left = Delete(r->left, temp->data);
        }
    }
     if(r == NULL)
            return r;

        r->height = max(height(r->left), height(r->right))+1;
        int bal = height(r->left) - height(r->right);
            if(bal>1){
                if(height(r->left) >= height(r->right)){
                    return singleRightRotate(r);
                }else{
                    r->left = singleLeftRotate(r->left);
                    return singleRightRotate(r);
                }
            }else if(bal < -1){
                if(height(r->right) >= height(r->left)){
                    return singleLeftRotate(r);
                }else{
                    r->right = singleRightRotate(r->right);
                    return singleLeftRotate(r);
                }
            }
     
        return r;
}
node* AVLTree::FindMax(node* r){    
    while(r->right!=NULL){
        r= r->right;
    }
    return r;    
}
node* AVLTree::PreOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
    cout << " "<< r->data << " -> ";
    PreOrderTraversal(r->left);
    PreOrderTraversal(r->right);    
}
node* AVLTree::InOrderTraversal( node* r){
     if (r == NULL)
        return NULL;
        InOrderTraversal(r->left);
    cout << " "<< r->data << " -> ";
    
    InOrderTraversal(r->right);    
}










