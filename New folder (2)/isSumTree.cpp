#include<iostream>
using namespace std;

// Node of Binary Tree
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

// Function to check if a binary tree is a sum tree
bool isSumTree(node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;

    // Calculate the sum of left subtree and right subtree
    int leftSum = 0, rightSum = 0;
    if (root->left)
        leftSum = root->left->data;
    if (root->right)
        rightSum = root->right->data;

    // Check if the root's data is equal to the sum of left subtree and right subtree
    if (root->data == (leftSum + rightSum) && isSumTree(root->left) && isSumTree(root->right))
        return true;
    else
        return false;
}

int main() {
    // Create a binary tree
    node* root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(6);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->right = newNode(7);

    // Check if the binary tree is a sum tree
    if (isSumTree(root))
        cout << "The binary tree is a sum tree." << endl;
    else
        cout << "The binary tree is not a sum tree." << endl;

    return 0;
}
