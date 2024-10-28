#include <iostream>

using namespace std;

// Structure for a node in the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Recursive function to calculate the height of a binary tree
int getHeight(Node* root) {
    if (root == nullptr)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    return 1 + max(leftHeight, rightHeight);
}

// Recursive function to count the number of unbalanced nodes in a binary search tree
int countUnbalancedNodes(Node* root) {
    if (root == nullptr)
        return 0;

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    int balanceFactor = leftHeight - rightHeight;

    int countLeft = countUnbalancedNodes(root->left);
    int countRight = countUnbalancedNodes(root->right);

    // Check if the current node is unbalanced
    int count = (balanceFactor < -1 || balanceFactor > 1) ? 1 : 0;

    // Recursively count unbalanced nodes in the left and right subtrees
    return count + countLeft + countRight;
}

// Sample usage
int main() {
    // Create a binary search tree
    Node* root = new Node();
    root->data = 4;

    Node* node2 = new Node();
    node2->data = 2;
    root->left = node2;

    Node* node6 = new Node();
    node6->data = 6;
    root->right = node6;

    Node* node1 = new Node();
    node1->data = 1;
    node2->left = node1;

    Node* node3 = new Node();
    node3->data = 3;
    node2->right = node3;

    Node* node5 = new Node();
    node5->data = 5;
    node6->left = node5;

    Node* node7 = new Node();
    node7->data = 7;
    node6->right = node7;

    // Call the countUnbalancedNodes function
    int unbalancedCount = countUnbalancedNodes(root);

    cout << "Number of unbalanced nodes: " << unbalancedCount << endl;

    // Clean up the memory
    delete node7;
    delete node5;
    delete node3;
    delete node1;
    delete node6;
    delete node2;
    delete root;

    return 0;
}
