#include<iostream>
#include <vector>

class BST {

struct node {
	int data;
	node* left;
	node* right;
};

	node* root;
	node* insert(int var, node* tree) {
	if(tree == NULL) {
		tree = new node;
		tree->data = var;
		tree->left = tree->right = NULL;
	} else if(var < tree->data)
		tree->left = insert(var, tree->left);
	else if(var > tree->data)
		tree->right = insert(var, tree->right);
	return tree;
}

void inorder(node* tree) {
	if(tree == NULL)
		return;
	inorder(tree->left);
	std::cout << tree->data << " ";
	inorder(tree->right);
}

public:
	BST() {
		root = NULL;
	}

	void insert(int var) {
		root = insert(var, root);
	}

	void display() {
		inorder(root);
		std::cout << std::endl;
	}
};

int main() {
	BST binaryTree;

	std::vector<int> testArray = {20,25,15,10,30};
	for (int i=0;i<5;i++) {
		binaryTree.insert(testArray[i]);
	}

	binaryTree.display();

	return 0; 
}
