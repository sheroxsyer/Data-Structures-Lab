#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int height(TreeNode* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int balance(TreeNode* root, int nodeVal) {
    if (root == NULL) {
        return 0;
    }

    if (root->val == nodeVal) {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return rightHeight - leftHeight;
    }

    if (nodeVal < root->val) {
        return balance(root->left, nodeVal);
    } else {
        return balance(root->right, nodeVal);
    }
}

int main() {
    /*
    *         8
    *       /   \
    *      3     10
    *     / \      \
    *    1   6     14
    *       / \    /
    *      4   7  13
    */
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    int nodeVal = 4;
    int nodeBalance = balance(root, nodeVal);
    cout << "The balance of the node with value " << nodeVal << " is: " << nodeBalance << endl;

    return 0;
}
