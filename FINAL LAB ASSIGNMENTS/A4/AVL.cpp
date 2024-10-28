//Write a C++ function which is passed two AVL trees T1 and T2, where the largest key in T1 is less than the
//smallest key in T2, join (T1, T2) returns an AVL tree containing the union of the elements in T1 and T2.

#include<iostream>
using namespace std;

struct Trunk
{
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);

    cout << p->str;
}

class listnode
{
    public:
    int info;
    listnode *next;

    listnode(int v)
    {
        info=v;
        next=NULL;
    }
};

class list
{
    public:
    listnode *head;

    list()
    {
        head=NULL;
    }

    void insertion(int v)
    {
        if(head==NULL)
        {
            listnode *n=new listnode(v);
            head=n;
        }
        else
        {
            listnode *temp=head;

            while(temp->next!=NULL)
            {
                temp=temp->next;
            }

            listnode *n=new listnode(v);
            temp->next=n;
        }
        
    }
};

class node
{
    public:
    int data;
    node *left;
    node *right;

    public:
    node(int v)
    {
        data=v;
        left=NULL;
        right=NULL;
    }
};

void printTree(node *&root, Trunk *prev, bool isRight)
{
    if (root == NULL)
        return;
    
    string prev_str = "    ";
    Trunk *trunk = new Trunk(prev, prev_str);

    printTree(root->right, trunk, true);

    if (!prev)
        trunk->str = "---";
    else if (isRight)
    {
        trunk->str = ".---";
        prev_str = "   |";
    }
    else
    {
        trunk->str = "`---";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->data << endl;

    if (prev)
        prev->str = prev_str;
    trunk->str = "   |";

    printTree(root->left, trunk, false);
}

class tree : public list
{
    public:
    node *root;
    int duplicate;

    public:
    tree()
    {
        duplicate=0;
        root=NULL;
    }

    bool search(node *n, int v);
    void insert(node *n , int v);
    void del(node *n , int v);
    int depth(node *n , int ll);
    void Inorderlist(node *n);
    node * rightrotate(node *n);
    node * lefttrotate(node *n);
    int balancefactor(node *n);
    node *AVLinsertion(node *n, int v);
    void Union(node *n, node *n1);
    
};

int main()
{
    tree obj; tree obj1 , obj2;

    obj.insert(obj.root, 10);
    obj.insert(obj.root, 5);
    obj.insert(obj.root, 15);
    cout<<"AVL TREE 1 :"<<endl;
    printTree(obj.root, NULL, false);
    cout<<endl;

    obj1.insert(obj1.root, 30);
    obj1.insert(obj1.root, 40);
    obj1.insert(obj1.root, 53);
    cout<<"AVL TREE 2 :"<<endl;
    printTree(obj1.root, NULL, false);
    cout<<endl;

    obj2.Union(obj.root, obj1.root);
    cout<<"After Union :"<<endl;
    printTree(obj2.root, NULL, false);

    return 0;

}

void tree::insert(node *n, int v)
{
    if(n==NULL)
    {
        node *p=new node(v);
        root=p;
        return;
    }

    if(v==n->data)
    {
        cout<<"Value already exists."<<endl;
        duplicate=duplicate+1;
        return;
    }

    if(v<n->data)
    {
        if(n->left!=NULL)
        {   
            insert(n->left, v);
        }
        else
        {
            node *p=new node(v);
            n->left=p;
            return; 
        }
    }
    
    if(v>n->data)
    {
        if(n->right!=NULL)
        {   
            insert(n->right, v);
        }
        else
        {
            node *p=new node(v);
            n->right=p;
            return;
        }
    }
}


bool tree::search(node *n, int v)
{
    if(n==NULL)
        return false;

    if(n->data==v)
        return true;

    if(v<n->data)
        search(n->left, v);
    else
        search(n->right, v);

}


int tree::depth(node *n, int ll)
{
    if(n==NULL)
        return -1;

    int ldepth=depth(n->left, ll+1) ;
    int rdepth=depth(n->right, ll+1);

    if(ldepth>rdepth)
        return ldepth+1;
    else
        return rdepth+1;      
}

void tree::Inorderlist(node *n)
{
    if(n==NULL)
        return ;

    Inorderlist(n->left);
    insertion(n->data);
    Inorderlist(n->right);
}

node * tree::rightrotate(node *n)
{
    node *l=n->left;
    node *t=l->right;

    l->right=n;
    n->left=t;

    return l;
}

node * tree::lefttrotate(node *n)
{
    node *l=n->right;
    node *t=l->left;

    l->left=n;
    n->right=t;

    return l;
}

int tree::balancefactor(node *n)
{
    if(n==NULL)
    {
        return -1;
    }

    else
    {
        return(depth(n->left,0)-depth(n->right,0));
    }
}

node * tree::AVLinsertion(node *n, int v)
{
    if(n==NULL)
    {
        node *k=new node(v);
        return k;
    }

    if(v<n->data)
        n->left=AVLinsertion(n->left, v);
    else if(v>n->data)
        n->right=AVLinsertion(n->right, v );
    else
    {
        cout<<"No dupliactes values"<<endl;
        return n;
    }       
    int bf=balancefactor(n);
    if(bf>1 && v<n->left->data)
        return rightrotate(n);
    if(bf<-1 && v>n->right->data)
        return lefttrotate(n);
    if(bf>1 && v>n->left->data)
    {
        n->left=lefttrotate(n->left);
        return rightrotate(n);
    }
    if(bf<-1 && v<n->right->data)
    {
        n->right=rightrotate(n->right);
        return lefttrotate(n);
    }  

    return n;      
}

void tree::Union(node *n, node *n1)
{
    Inorderlist(n);
    Inorderlist(n1);

    listnode *p=head;

    while(p!=NULL)
    {
        root=AVLinsertion(root, p->info);
        p=p->next;
    }
}
