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
        return 0;
    } else {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

void printLevel(TreeNode* root, int level, bool isEven) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        cout << root->val << " ";
    } else if (level > 1) {
        if (isEven) {
            printLevel(root->left, level-1, isEven);
            printLevel(root->right, level-1, isEven);
        } else {
            printLevel(root->right, level-1, isEven);
            printLevel(root->left, level-1, isEven);
        }
    }
}

void zigzag(TreeNode* root) {
    int h = height(root);
    bool isEven = true;
    for (int i = 1; i <= h; i++) {
        printLevel(root, i, isEven);
        isEven = !isEven;
    }
}

void insert(TreeNode* root, int val) {
    if (val < root->val) {
        if (root->left == NULL) {
            root->left = new TreeNode(val);
        } else {
            insert(root->left, val);
        }
    } else {
        if (root->right == NULL) {
            root->right = new TreeNode(val);
        } else {
            insert(root->right, val);
        }
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    insert(root, 7);
    insert(root, 8);
    insert(root, 9);

    cout << "The values of the binary tree in zigzag order are: ";
    zigzag(root);
    cout << endl;

    return 0;
}
