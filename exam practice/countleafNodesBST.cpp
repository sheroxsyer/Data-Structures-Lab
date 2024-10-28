#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countLeafNodes(TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    int leftCount = countLeafNodes(root->left);
    int rightCount = countLeafNodes(root->right);
    return leftCount + rightCount;
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

    int leafCount = countLeafNodes(root);
    cout << "The number of leaf nodes in the given binary tree is: " << leafCount << endl;

    return 0;
}
