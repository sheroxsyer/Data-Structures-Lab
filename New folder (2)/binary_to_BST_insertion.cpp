#include <iostream>
using namespace std;

// Define the structure of the binary tree node
struct node {
    int data;
    node* left;
    node* right;
};

// Function to create a new node for the BST
node* newNode(int key) {
    node* new_node = new node;
    new_node->data = key;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the BST
node* insert(node* root, int key) {
    // If the tree is empty, create a new node and return it
    if (root == NULL) {
        return newNode(key);
    }
    // Otherwise, recur down the tree
    if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        root->right = insert(root->right, key);
    }
    return root;
}

// Function to traverse the binary tree in inorder and insert nodes into the BST
node* createBST(node* root, node* binary_tree) {
    if (binary_tree != NULL) {
        createBST(root, binary_tree->left);
        root = insert(root, binary_tree->data);
        createBST(root, binary_tree->right);
    }
    return root;
}

// Function to print the inorder traversal of the BST
void inorderTraversal(node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    // Create the binary tree
    node* binary_tree = newNode(10);
    binary_tree->left = newNode(5);
    binary_tree->right = newNode(15);
    binary_tree->left->left = newNode(3);
    binary_tree->left->right = newNode(7);
    binary_tree->right->left = newNode(12);
    binary_tree->right->right = newNode(17);

    // Create the BST from the binary tree
    node* bst = NULL;
    bst = createBST(bst, binary_tree);

    // Print the inorder traversal of the BST
    cout << "Inorder traversal of the BST: ";
    inorderTraversal(bst);

    return 0;
}
