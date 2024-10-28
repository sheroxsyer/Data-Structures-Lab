
#include<iostream>
using namespace std;

class node
{
	public:
	int data;
	node* left;
	node* right;
};

int *merge(int arr1[], int arr2[], int m, int n);

void storeTree(node* node, int inorder[],
							int *index_ptr);

node* sortedToBST(int arr[], int start, int end);
node* mergeTrees(node *root1, node *root2, int m, int n)
{
	int *arr1 = new int[m];
	int i = 0;
	storeTree(root1, arr1, &i);

	int *arr2 = new int[n];
	int j = 0;
	storeTree(root2, arr2, &j);

	int *mergedArr = merge(arr1, arr2, m, n);


	return sortedToBST (mergedArr, 0, m + n - 1);
}
node* newNode(int data)
{
	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return(Node);
}




int *merge(int arr1[], int arr2[], int m, int n)
{
	int *mergedTree = new int[m + n];
	int i = 0, j = 0, k = 0;

	
	while (i < m && j < n)
	{
		
		if (arr1[i] < arr2[j])
		{
			mergedTree[k] = arr1[i];
			i++;
		}
		else
		{
			mergedTree[k] = arr2[j];
			j++;
		}
		k++;
	}


	while (i < m)
	{
		mergedTree[k] = arr1[i];
		i++; k++;
	}


	while (j < n)
	{
		mergedTree[k] = arr2[j];
		j++; k++;
	}

	return mergedTree;
}
void printTree(node* node)
{
	if (node == NULL)
		return;
	printTree(node->left);

	cout << node->data << " ";
	printTree(node->right);
}


void storeTree(node* node, int inorder[], int *index_ptr)
{
	if (node == NULL)
		return;

	
	storeTree(node->left, inorder, index_ptr);

	inorder[*index_ptr] = node->data;
	(*index_ptr)++; 

	
	storeTree(node->right, inorder, index_ptr);
}

node* sortedToBST(int arr[], int start, int end)
{

	if (start > end)
	return NULL;


	int mid = (start + end)/2;
	node *root = newNode(arr[mid]);
	root->left = sortedToBST(arr, start, mid-1);

	root->right = sortedToBST(arr, mid+1, end);

	return root;
}


int main()
{
	node *root1 = newNode(1000);
	root1->left	 = newNode(500);
	root1->right = newNode(300);
	root1->left->left = newNode(200);
	root1->left->right = newNode(7);

	node *root2 = newNode(800);
	root2->left	 = newNode(400);
	root2->right = newNode(120);

	node *mergedTree = mergeTrees(root1, root2, 5, 3);

	cout << "Merged Tree is:";
	printTree(mergedTree);

	return 0;
}
