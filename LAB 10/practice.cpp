#include <bits/stdc++.h>
using namespace std;
class nod { //node declaration
   public:
   int data;
   nod* l;
   nod* r;
};
nod* newNod(int d) { //creation of new node
   nod* Nod = new nod();
   Nod->data = d;
   Nod->l = NULL;
   Nod->r = NULL;
   return(Nod);
}
int max(int x, int y) { //return maximum between two values
   return (x >= y)? x: y;
}
int height(nod* node) { //get the height means the number of nodes along the longest path from the root
// node down to the farthest leaf node of the tree. 
   if(node == NULL)
      return 0;
   return 1 + max(height(node->l), height(node->r));
}
bool AVL(nod *root) {
   int lh;
   int rh;
   if(root == NULL)
      return 1;
   lh = height(root->l); // left height
   rh = height(root->r); // right height
   if(abs(lh-rh) <= 1 && AVL(root->l) && AVL(root->r)) return 1;
   return 0;
}
int main() {
   //take the nodes of the tree as input
   nod *root = newNod(7);
   root->l = newNod(6);
   root->r = newNod(12);
   root->l->l = newNod(4);
   root->l->r = newNod(5);
   root->r->r = newNod(13);
   if(AVL(root))
      cout << "The Tree is AVL Tree"<<endl;
   else
      cout << "The Tree is not AVL Tree "<<endl;
   nod *root1 = newNod(7);
   root1->l = newNod(6);
   root1->r = newNod(12);
   root1->l->l = newNod(4);
   root1->l->r = newNod(5);
   root1->r->r = newNod(13);
   root1->r->r->r = newNod(26);
   if(AVL(root1))
      cout << "The Tree is AVL Tree"<<endl;
   else
      cout << "The Tree is not AVL Tree "<<endl;
   return 0;
}