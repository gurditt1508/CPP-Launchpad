#include<iostream>
#include<queue>
#include<vector>

using namespace std;

void printTopK(priority_queue<int, vector<int>, greater<int>> minHeap){

	while(!minHeap.empty()){
		cout << minHeap.top() << " ";
		minHeap.pop();
	}

}

int main(){

	vector<int> v = {10, 30, 50, 40, 20, 60};
	priority_queue<int, vector<int>, greater<int>> minHeap;

	int k = 2;

	for(int i = 0; i<k; i++){
		minHeap.push(v[i]);
	}

	for(int j = k; j<v.size(); j++){
		if(minHeap.top() < v[j]){
			minHeap.pop();
			minHeap.push(v[j]);
		}
	}

	printTopK(minHeap);

	return 0;
}