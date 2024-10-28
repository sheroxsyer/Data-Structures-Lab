#include <iostream>
using namespace std;

struct Node {
   int key;
   Node *left;
   Node *right;
};

Node* search(Node* root, int key) {
   if (root == NULL || root->key == key)
      return root;

   if (root->key < key)
      return search(root->right, key);

   return search(root->left, key);
}

Node* newNode(int item) {
   Node* temp = new Node;
   temp->key = item;
   temp->left = temp->right = NULL;
   return temp;
}

Node* insert(Node* root, int key) {
   if (root == NULL)
      return newNode(key);

   if (key < root->key)
      root->left = insert(root->left, key);

   else if (key > root->key)
      root->right = insert(root->right, key);

   return root;
}

void inorder(Node* root) {
   if (root != NULL) {
      inorder(root->left);
      cout << root->key << " ";
      inorder(root->right);
   }
}

int main() {
   Node* root = NULL;
   root = insert(root, 50);
   insert(root, 30);
   insert(root, 20);
   insert(root, 40);
   insert(root, 70);
   insert(root, 60);
   insert(root, 80);

   cout << "Inorder traversal of the BST: ";
   inorder(root);
   cout << endl;

   int keyToSearch = 60;
   Node* searchResult = search(root, keyToSearch);

   if (searchResult == NULL)
      cout << keyToSearch << " not found in the BST" << endl;
   else
      cout << keyToSearch << " found in the BST" << endl;

   return 0;
}












// void searchBST(int val) {
//         node* result = searchBST(root, val);
//         if (result) {
//             cout << "Found " << val << " in the tree." << endl;
//         }
//         else {
//             cout << "Could not find " << val << " in the tree." << endl;
//         }
//     }
// void floorCeil(int key) {
//         int floor = -1, ceil = -1;
//         floorCeil(root, key, floor, ceil);
//         if (floor == -1 && ceil == -1) {
//             cout << "Key is not present in the tree" << endl;
//         }
//         else {
//             cout << "Floor: " << floor << " Ceil: " << ceil << endl;
//         }
//     }