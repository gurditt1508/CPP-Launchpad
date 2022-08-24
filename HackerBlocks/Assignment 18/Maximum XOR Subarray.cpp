#include<iostream>
#include<climits>

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

public:
	
	trie() {
		root = new node();
	}

	void insert(int n) {
		node* temp = root;
		for(int i=31; i>=0; i--) {
			int bit = (1<<i)&n;
			if(!bit) {
				if(!temp->left) {
					node* n = new node();
					temp->left = n;
				}
				temp = temp->left;
			} else {
				if(!temp->right) {
					node* n = new node();
					temp->right = n;
				}
				temp = temp->right;
			}
		}
	}

	int helper(int n) {
		node* cur = root;
		int y = 0;
		int XOR = 0;
		for(int i=31; i>=0; i--) {
			int ith_bit = (n>>i)&1;
			if(ith_bit == 0) {
				if(cur->right != NULL) {
					XOR += (1<<i);
					y += (1<<i);
					cur = cur->right;
				} else {
					cur = cur->left;
				}

			} else {
				if(cur->left != NULL) {
					XOR += (1<<i);
					cur = cur->left;
				} else {
					cur = cur->right;
					y += (1<<i);
				}
			}
		}

		return XOR;
	}

	int maximumXOR(int* x, int n) {
		int out = 0;
		for(int i=0; i<n; i++) {
			out = max(out, helper(x[i]));
		}
		return out;
	}

};

int main() {

	int n;
	cin >> n;
	int* arr = new int[n];

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}

	int cxor_arr[n+1];
	cxor_arr[0] = 0;
	for(int i=1; i<=n; i++) {
		cxor_arr[i] = cxor_arr[i-1]^arr[i-1];
	}

	trie t;

	for(int i=0; i<=n; i++) {
		t.insert(cxor_arr[i]);
	}

	cout << t.maximumXOR(cxor_arr, n) << endl;
  
	return 0;
}