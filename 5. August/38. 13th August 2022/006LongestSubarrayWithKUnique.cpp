#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
	
	string s = "aabacbebebe";
	int n = s.size();
	int k = 3;

	int i = 0; //to denote the start of the window
	int j = 0; //to denote the end of the window

	int max_len = 0; //to track the length of the longest substring
					//i.e. window that contains k unique characters

	int count = 0; //to keep track of no. of unique characters in the window

	unordered_map<char, int> characterMap;

	int s_index;

	while(j < n) {
		//expand the window
		characterMap[s[j]]++;
		if(characterMap[s[j]] == 1) count++;

		//check for the violation of the window property
		if(count > k) {
			//shrink the window
			while(count > k) {
				characterMap[s[i]]--;
				if(characterMap[s[i]] == 0) count--;
				i++;
			}
		}

		//check for the validity of the window
		if(count == k) {
			if(j-i+1 > max_len) {
				max_len = j-i+1;
				s_index = i;
			}
			// max_len = max(max_len, j-i+1);
		}

		//continue the expansion
		j++;
	}

	cout << s.substr(s_index, max_len) << endl;

	cout << max_len << endl;

	return 0;
}