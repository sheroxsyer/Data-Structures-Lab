#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countParentNodes(TreeNode* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) return 0;
    int leftCount = countParentNodes(root->left);
    int rightCount = countParentNodes(root->right);
    return leftCount + rightCount + 1;
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

    int parentCount = countParentNodes(root);
    cout << "The number of parent nodes in the given binary tree is: " << parentCount << endl;

    return 0;
}
