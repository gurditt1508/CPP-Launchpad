#include<iostream>
#include<deque>
#include<vector>

using namespace std;

int main() {

	int arr[] = {1,3,0,1,2,0,5};
	int n = sizeof(arr) / sizeof(int);

	int k = 4;

	deque<int> deq; //to store numbers of interest in a window
	vector<int> v; //to store the maximum element for each window

	int i=0; //denotes start of window
 	int j=0; //denotes end of window

	//find the maximum element in the 1st window

	while(j<k) {
		while(!deq.empty() && deq.back() < arr[j]) {
			deq.pop_back();
		}
		deq.push_back(arr[j]);
		j++;
	}

	v.push_back(deq.front());

	//find the maximum in the remaining windows

	while(j < n) {

		//slide the window
		if(deq.front() == arr[i]) deq.pop_front();
		i++;
		while(!deq.empty() && deq.back() < arr[j])  {
			deq.pop_back();
		}
		deq.push_back(arr[j]);

		v.push_back(deq.front());

		//update the ans
		j++;
	}

	for(int i=0; i<v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}