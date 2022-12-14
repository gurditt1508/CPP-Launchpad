#include<iostream>
#include<set>

using namespace std;

int main(){
	set<int> s;
	s.insert(5);
	s.insert(4);
	s.insert(3);
	s.insert(2);
	s.insert(1);

	for(auto x : s){
		cout << x << " ";
	}

	cout << endl;

	cout << "size: " << s.size() << endl;

	// s.erase(5);
	// cout << "size: " << s.size() << endl;

	for(auto it = s.begin(), end = s.end(); it != end; it++){ //instead of using auto, we can also use 
		//set<int>::iterator
		cout << *it << " ";
	}

	cout << endl;

	//we can print using for-each loop
	// for(auto x : s){
	// 	cout << x << " ";
	// }

	if(s.find(3) != s.end()) {
		cout << "3 is present!" << endl;
	} else {
		cout << "3 is absent!" << endl;
	}

	if(s.count(5)) {
		cout << "5 is present!" << endl;
	} else {
		cout << "5 is not present!" << endl;
	}

	s.clear();
	if(s.empty()) cout << "Set is empty now!" << endl;

	return 0;
}