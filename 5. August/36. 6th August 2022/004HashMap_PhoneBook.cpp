#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main(){
	
	unordered_map<string, vector<string>> phoneBook;

	phoneBook["Gurditt"].push_back("123456");
	phoneBook["Gurditt"].push_back("34536");

	phoneBook["Hargun"].push_back("34534");

	phoneBook["Junet"].push_back("873094");

	phoneBook["Abhishek"].push_back("00001111");

	for(pair<string, vector<string>> p : phoneBook){
		cout << p.first << " ";
		for(string num : p.second){
			cout << num << " ";
		}
		cout << endl;
	}

	return 0;
}