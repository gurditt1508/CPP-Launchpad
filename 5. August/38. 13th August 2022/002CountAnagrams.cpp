#include<iostream>

using namespace std;

bool compareMap(int tFreqMap[], int wFreqMap[]){

	for(int i=0; i<26; i++){
		if(tFreqMap[i] != wFreqMap[i])
			return false;
	}

	return true;
}

int main(){

	string s = "cbaebabacd";
	string t = "abc";

	int n = s.size();
	int k = t.size(); //size of the window;

	int count = 0; //to store the anagrams of 't' in 's';

	int tFreqMap[26] = {0}; //store the mapping b/w characters
							//present in 't' & their frequencies


	for(int i=0; i<k; i++){
		tFreqMap[t[i]-'a']++;
	}

	int i = 0; //to denote start of window
	int j = 0; //to denote the end of the window

	int wFreqMap[26] = {0}; //store a mapping between characters
							//present in window & their frequencies

	//build the frequency map for 1st window
	while(j < k){
		wFreqMap[s[j]-'a']++;
		j++;
	}

	//check if the window is an anagram of 't'
	if(compareMap(tFreqMap, wFreqMap)) count++;

	//build the frequency map for the remaining window
	while(j < n){
		//slide the window
		wFreqMap[s[i]-'a']--;
		i++;
		wFreqMap[s[j]-'a']++;

		if(compareMap(tFreqMap, wFreqMap)) count++;

		j++;

	}

	cout << count << endl;

	return 0;
}