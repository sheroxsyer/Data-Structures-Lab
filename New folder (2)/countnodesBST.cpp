#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodes(TreeNode* root) {
    if (!root) return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int main() {
    /*
    *        5
    *       / \
    *      1   7
    *         / \
    *        6   9
    */
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(1);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    int numNodes = countNodes(root);
    cout << "The number of nodes in the BST is: " << numNodes << endl;

    return 0;
}
