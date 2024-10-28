#include <iostream>

// define the structure of a BST node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// function to count non-leaf nodes in a BST
int countNonLeafNodes(Node* root) {
    // base case
    if (!root || (!root->left && !root->right)) {
        return 0; // empty tree or leaf node
    }

    // recursive cases
    int count = 0;
    if (root->left) {
        count++; // increment count for left child
        count += countNonLeafNodes(root->left); // traverse left subtree
    }
    if (root->right) {
        count++; // increment count for right child
        count += countNonLeafNodes(root->right); // traverse right subtree
    }
    return count;
}

// test the function
int main() {
    // create a BST
    Node* root = new Node{4, 
                          new Node{2, new Node{1, nullptr, nullptr}, new Node{3, nullptr, nullptr}}, 
                          new Node{6, new Node{5, nullptr, nullptr}, new Node{7, nullptr, nullptr}}};

    // count non-leaf nodes
    int count = countNonLeafNodes(root);
    std::cout << "Number of non-leaf nodes: " << count << std::endl;

    return 0;
}
