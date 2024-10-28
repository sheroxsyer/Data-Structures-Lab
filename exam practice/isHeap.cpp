// #include<iostream>
// #include<string>

// using namespace std;

// // Definition of a binary tree node
// struct Node {
//     int data;
//     Node *left, *right;
//     Node(int value)
//     {
//         data = value;
//         left = right = NULL;
//     }
// };

// // Function to check if the binary tree is complete
// bool isComplete(Node* root, int index, int numNodes)
// {
//     // Base case
//     if (root == NULL)
//         return true;

//     // If index assigned to current node is more than number of nodes in tree
//     if (index >= numNodes)
//         return false;

//     // Recur for left and right subtrees
//     return isComplete(root->left, 2 * index + 1, numNodes)
//            && isComplete(root->right, 2 * index + 2, numNodes);
// }

// // Function to check if the binary tree is a max-heap
// bool isHeapUtil(Node* root)
// {
//     // Base case
//     if (root == NULL)
//         return true;

//     // Check if the left child exists and is greater than the current node
//     if (root->left != NULL && root->left->data > root->data)
//         return false;

//     // Check if the right child exists and is greater than the current node
//     if (root->right != NULL && root->right->data > root->data)
//         return false;

//     // Recur for left and right subtrees
//     return isHeapUtil(root->left) && isHeapUtil(root->right);
// }

// // Function to check if the binary tree is a max-heap
// bool isMaxHeap(Node* root)
// {
//     // Count the number of nodes in the binary tree
//     int numNodes = 0;
//     queue<Node*> q;
//     q.push(root);
//     while (!q.empty()) {
//         Node* curr = q.front();
//         q.pop();
//         numNodes++;

//         if (curr->left != NULL)
//             q.push(curr->left);

//         if (curr->right != NULL)
//             q.push(curr->right);
//     }

//     // Check if the binary tree is complete and satisfies the max-heap property
//     return isComplete(root, 0, numNodes) && isHeapUtil(root);
// }
// int main() {
//     // Create a binary tree that satisfies the max-heap property
//     Node* root1 = new Node(10);
//     root1->left = new Node(9);
//     root1->right = new Node(8);
//     root1->left->left = new Node(7);
//     root1->left->right = new Node(6);
//     root1->right->left = new Node(5);
//     root1->right->right = new Node(4);

//     // Check if the binary tree satisfies the max-heap property
//     if (isMaxHeap(root1))
//         cout << "The binary tree is a max-heap" << endl;
//     else
//         cout << "The binary tree is not a max-heap" << endl;

//     // Create a binary tree that does not satisfy the max-heap property
//     Node* root2 = new Node(10);
//     root2->left = new Node(8);
//     root2->right = new Node(9);
//     root2->left->left = new Node(7);
//     root2->left->right = new Node(6);
//     root2->right->left = new Node(5);
//     root2->right->right = new Node(4);

//     // Check if the binary tree satisfies the max-heap property
//     if (isMaxHeap(root2))
//         cout << "The binary tree is a max-heap" << endl;
//     else
//         cout << "The binary tree is not a max-heap" << endl;

//     return 0;
// }
#include<iostream>
using namespace std;

// Node of Binary Tree
struct node {
    int data;
    node* left;
    node* right;
};

// Function to create a new node
node* newNode(int key) {
    node* temp = new node();
    temp->data = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to check if a binary tree satisfies the max-heap property
bool isMaxHeap(node* root) {
    // If the tree is empty or has only one node, it is a max-heap
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;

    // If the node has only one child, it must be the left child
    if (root->right == NULL)
        return root->data >= root->left->data;

    // If the node has two children, check if the heap property is satisfied recursively
    if (root->data >= root->left->data && root->data >= root->right->data)
        return isMaxHeap(root->left) && isMaxHeap(root->right);

    // If the heap property is not satisfied, return false
    return false;
}

int main() {
    // Create a binary tree
    node* root = newNode(98);
    root->left = newNode(83);
    root->right = newNode(76);
    root->left->left = newNode(68);
    root->left->right = newNode(75);
    root->right->left = newNode(54);

    // Check if the binary tree satisfies the max-heap property
    if (isMaxHeap(root))
        cout << "The binary tree satisfies the max-heap property." << endl;
    else
        cout << "The binary tree does not satisfy the max-heap property." << endl;

    return 0;
}
