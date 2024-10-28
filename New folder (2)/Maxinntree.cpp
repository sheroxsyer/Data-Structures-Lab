#include <iostream>

using namespace std;

// Structure for a node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Recursive function to find the maximum value in a binary tree
int findMaxValue(Node* root) {
    // Base case: If the root is null, return the minimum possible value
    if (root == nullptr) {
        return INT_MIN;
    }
    // Recursive case: Compare the root value with the maximum values in the left and right subtrees
    int maxVal = root->data;
    int maxLeft = findMaxValue(root->left);
    int maxRight = findMaxValue(root->right);
    
    if (maxLeft > maxVal) {
        maxVal = maxLeft;
    }
    if (maxRight > maxVal) {
        maxVal = maxRight;
    }
    return maxVal;
}

// Sample usage
int main() {
    // Create a binary tree
    Node* root = new Node();
    root->data = 1;

    Node* node2 = new Node();
    node2->data = 2;
    root->left = node2;

    Node* node3 = new Node();
    node3->data = 3;
    root->right = node3;

    Node* node4 = new Node();
    node4->data = 4;
    node2->left = node4;

    Node* node5 = new Node();
    node5->data = 5;
    node2->right = node5;

    node2->left = nullptr;
    node2->right = nullptr;

    // Call the findMaxValue function
    int maxValue = findMaxValue(root);

    cout << "Maximum value in the binary tree: " << maxValue << endl;

    // Clean up the memory
    delete node5;
    delete node4;
    delete node3;
    delete node2;
    delete root;

    return 0;
}
