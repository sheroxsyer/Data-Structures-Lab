#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodesWithSumChildren(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int leftSum = 0;
    if (root->left != NULL) {
        leftSum = root->left->val;
    }

    int rightSum = 0;
    if (root->right != NULL) {
        rightSum = root->right->val;
    }

    int count = 0;
    if (root->val == leftSum + rightSum) {
        count = 1;
    }

    int leftCount = countNodesWithSumChildren(root->left);
    int rightCount = countNodesWithSumChildren(root->right);

    return count + leftCount + rightCount;
}

int main() {
    /*
    *         8
    *       /   \
    *      3     5
    *     / \     \
    *    2   1     7
    *               \
    *                3
    */
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(3);

    int count = countNodesWithSumChildren(root);
    cout << "The number of nodes with info equal to sum of its children info in the given binary tree is: " << count << endl;

    return 0;
}
