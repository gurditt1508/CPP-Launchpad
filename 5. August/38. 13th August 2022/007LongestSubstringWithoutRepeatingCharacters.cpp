#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	string s = "abcabcbb";
	int n = s.size();

	int i = 0;
	int j = 0;

	int max_len = 0;

	unordered_map<char, int> freqMap; 

	while(j < n) {

		freqMap[s[j]]++;

		if(freqMap[s[j]] > 1) {
			while(freqMap[s[j]] > 1) {
				freqMap[s[i]]--;
				i++;
			}
		}

		max_len = max(max_len, j-i+1);

		j++;
	}

	cout << max_len << endl;

	return 0;
}