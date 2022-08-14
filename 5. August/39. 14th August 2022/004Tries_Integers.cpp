/*

Implementation of the TRIE data structure to store non-negative integers.

Assume integer has 32-bit representation.

*/

#include<iostream>

using namespace std;

class node {

public:
	
	node* left;  // indicates if node has a child that represents bit 0
	node* right; // indicates if node has a child that represents bit 1
	
	node() {
		this->left = NULL;
		this->right= NULL;
	}
};


class trie {
	
	node* root;

	public :

		trie() {
			root = new node();
		}

		void insert(int n) {
			node* cur = root;
			for(int i=31; i>=0; i--) {
				int ith_bit = (n>>i)&1;
				if(!ith_bit) { // ith_bit == 0
					// ith_bit of n is unset, check if the current node has a left child
					if(!cur->left) { // cur->left == NULL
						cur->left = new node();
					}
					cur = cur->left;
				} else {
					// ith_bit of n is set, check if the current node has right child
					if(!cur->right) { // cur->right == NULL
						cur->right = new node;
					}
					cur = cur->right;
				}
			} 
		}

		bool search(int n) {
			node* cur = root;
			for(int i=31; i>=0; i--) {
				int ith_bit = (n>>i)&1;
				if(!ith_bit) {
					// ith_bit of n is not set, check if the current node has a left child
					if(!cur->left) { // cur->left == NULL
						return false;
					}
					cur = cur->left;
				} else {
					// ith_bit of n is set, check if the current node has a right child
					if(!cur->right) { // cur->right == NULL
						return false;
					}
					cur = cur->right;
				}
			}

			return true;
		}
};

int main() {

	int arr[] = {25, 10, 2, 8, 5, 3};
	int n = sizeof(arr) / sizeof(int);

	trie t;
	for(int i=0; i<n; i++) {
		t.insert(arr[i]);
	}

	int brr[] = {1, 2, 5, 10, 25, 0};
	int m = sizeof(brr) / sizeof(int);

	for(int i=0; i<m; i++) {
    	t.search(brr[i]) ? cout << brr[i] << " is present" << endl :
    	                   cout << brr[i] << " is absent" << endl;
    }

    cout << endl;

	return 0;
}