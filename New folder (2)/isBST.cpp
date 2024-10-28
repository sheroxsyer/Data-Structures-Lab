#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isValidBSTHelper(TreeNode* root, int minVal, int maxVal) {
    if (!root) return true;
    if (root->val <= minVal || root->val >= maxVal) return false;
    return isValidBSTHelper(root->left, minVal, root->val) && isValidBSTHelper(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTHelper(root, INT_MIN, INT_MAX);
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

    bool isBST = isValidBST(root);
    if (isBST)
        cout << "The given binary tree is a binary search tree." << endl;
    else
        cout << "The given binary tree is not a binary search tree." << endl;

    return 0;
}
