#include <iostream>
#include <vector>

struct node {
	node* right;
	node* left;
	int value;
};

class BinarySearchTree {
	node* root;

	node* insertNode(int x, node* root) {
		if (root == NULL) {
			root = new node;
			root->value = x;
			root->left = root->right = NULL;
		} else if (x > root->value) {
			root->right = insertNode(x, root->right);
		} else if (x < root->value) {
			root->left = insertNode(x, root->left);
		}
		return root;
	}
/*
	node* buildTree(std::vector<int>& arr, int size, node* root) {
		int midVal = arr[size/2];
		std::vector<int> lowerHalf;
		std::vector<int> upperHalf;

    // Create the upper and lower halves for right and left child nodes
		for (int i=0;i<(size/2)-1;i++) {
			lowerHalf.push_back(arr[i]);
		}
		for (int i=(size/2)+1;i<size;i++) {
			upperHalf.push_back(arr[i]);
		}

		if (root == NULL) {
			std::cout << "made it" << std::endl;
			root = new node;
			root->value = midVal;
      std::cout << root->value << std::endl;

			root->right = root->left = nullptr;
		} else if (midVal > root->value) {
			root->right = buildTree(upperHalf, size/2, root);
		} else if (midVal < root->value) {
			root->left = buildTree(lowerHalf, size/2, root);
		} 
		return root;
	}
*/
	public:
		BinarySearchTree() {
			root = NULL;
		}
/*
		void initTree(std::vector<int> arr, int size) {
			root = buildTree(arr, size, root);
			std::cout << root->value << std::endl;
		}
*/

		void insert(int x) {
				insertNode(x, root);
		}

		node* findRoot() {
			return root;
		}
};

int main() {
	std::vector<int> testArray = {1,2,3,4,5,6,7,8,9,10};
	BinarySearchTree newTree;
	
	for (int i : testArray) {
		newTree.insert(testArray[i]);
	}

	node newRoot = newTree.findRoot();

	std::cout << newRoot->value << std::endl;

	return 0;
}
