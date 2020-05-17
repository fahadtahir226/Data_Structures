#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Node
{
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = 0;
	}
};
int size(Node* root)
{
	if (root == 0)
		return 0;

	return 1 + size(root->left) + size(root->right);
}

bool isHeap(Node* root, int i, int n)
{
	// base case
	if (root == 0)
		return true;

	if (i >= n)
		return false;

	if ((root->left && root->left->data <= root->data) ||
			(root->right && root->right->data <= root->data))
		return false;

	return isHeap(root->left, 2*i + 1, n) &&
			isHeap(root->right, 2*i + 2, n);
}

bool isHeap(Node* root)
{
	int i = 0;
	return isHeap(root, i, size(root));
}

// main function
int main()
{

	Node* root = new Node(2);
	root->left = new Node(3);
	root->right = new Node(4);
	root->left->left = new Node(5);
	root->left->right = new Node(6);
	root->right->left = new Node(8);
	root->right->right = new Node(10);

	if (isHeap(root))
		cout << "Given Binary Tree is a min-Heap";
	else
		cout << "Given Binary Tree is not a min-Heap";

	return 0;
}