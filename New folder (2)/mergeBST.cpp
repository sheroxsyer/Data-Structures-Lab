#include<iostream>
using namespace std;

// Node of BST
struct node {
    int data;
    node* left;
    node* right;
};

// Function to create a new node
node* newNode(int key) {
    node* temp = new node();
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to insert a new node in BST
node* insert(node* root, int key) {
    if (root == NULL)
        return newNode(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else if (key > root->data)
        root->right = insert(root->right, key);
    return root;
}

// Function to merge two BSTs
node* mergeTrees(node* root1, node* root2) {
    if (root1 == NULL)
        return root2;
    if (root2 == NULL)
        return root1;

    // Traverse the first tree in in-order
    if (root1->left)
        root2 = mergeTrees(root1->left, root2);
    root2 = insert(root2, root1->data);
    if (root1->right)
        root2 = mergeTrees(root1->right, root2);

    return root2;
}

// Function to traverse a BST in in-order and print the nodes
void inOrderTraversal(node* root) {
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    // Create the first BST
    node* root1 = NULL;
    root1 = insert(root1, 4);
    root1 = insert(root1, 2);
    root1 = insert(root1, 7);
    root1 = insert(root1, 1);
    root1 = insert(root1, 3);
    root1 = insert(root1, 6);
    root1 = insert(root1, 9);

    // Create the second BST
    node* root2 = NULL;
    root2 = insert(root2, 10);
    root2 = insert(root2, 8);
    root2 = insert(root2, 13);
    root2 = insert(root2, 5);
    root2 = insert(root2, 11);
    root2 = insert(root2, 12);
    root2 = insert(root2, 15);

    // Merge the two BSTs
    node* mergedRoot = mergeTrees(root1, root2);

    // Print the merged BST in in-order
    cout << "Merged BST: ";
    inOrderTraversal(mergedRoot);
    cout << endl;

    return 0;
}
