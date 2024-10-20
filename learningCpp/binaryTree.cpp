#include <iostream>
#include <vector>

using namespace std;

class BinarySearchTree {
	struct node {
		node* right;
		node* left;
		int value;
	};

	node* root;
	
	node* buildTree(vector<int>& arr, int size) {
		int midVal = arr[size/2];
		vector<int> lowerHalf;
		vector<int> upperHalf;
		
		for (int i=0;i<(size/2)-1;i++) {
			lowerHalf.push_back(arr[i]);
		}
		for (int i=size/2;i<size;i++) {
			upperHalf.push_back(arr[i]);
		}
		
		/*if (root == NULL) {
			root->value = midVal;
			cout << root->value << endl;
			root->right = root->left = nullptr;
		} else if (midVal > root->value) {
			root->right = buildTree(upperHalf, size/2);
			cout << root->right << endl;
		} else if (midVal < root->value) {
			root->left = buildTree(lowerHalf, size/2);
			cout << root->left << endl;
		} */
		return root;
	}

	public:
		BinarySearchTree() {
			root = NULL;
		}		

		void initTree(vector<int> arr, int size) {
			root = buildTree(arr, size);
		}
};

int main() {
	vector<int> testArray = {1,2,3,4,5,6,7,8,9,10};
	BinarySearchTree newTree;
	
	newTree.initTree(testArray, 10);

	return 0;
}
