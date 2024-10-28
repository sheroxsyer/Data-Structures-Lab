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

Node* insert(Node* root, int key) {
   if (root == NULL)
      return new Node{key, NULL, NULL};

   if (key < root->key)
      root->left = insert(root->left, key);

   else if (key > root->key)
      root->right = insert(root->right, key);

   return root;
}

void floorCeil(Node* root, int key, int& floor, int& ceil) {
   if (root == NULL)
      return;

   if (root->key == key) {
      floor = root->key;
      ceil = root->key;
      return;
   }

   if (root->key > key) {
      ceil = root->key;
      floorCeil(root->left, key, floor, ceil);
   } else {
      floor = root->key;
      floorCeil(root->right, key, floor, ceil);
   }
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

   int keyToFind = 55;
   int floor = -1, ceil = -1;
   floorCeil(root, keyToFind, floor, ceil);

   if (floor == -1 && ceil == -1)
      cout << "The BST is empty" << endl;
   else if (floor == -1)
      cout << "The ceil of " << keyToFind << " is " << ceil << endl;
   else if (ceil == -1)
      cout << "The floor of " << keyToFind << " is " << floor << endl;
   else
      cout << "The floor of " << keyToFind << " is " << floor << " and the ceil is " << ceil << endl;

   return 0;
}
