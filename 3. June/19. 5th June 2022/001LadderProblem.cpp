#include<iostream>

using namespace std;

int ladder(int n, int k){
	//base case
	if(n == 0){
		return 1;
	}

	//recursive case
	int count = 0;
	for(int j = 1; j<=k; j++){
		if(n-j >= 0){
			count += ladder(n-j, k);
	}
}

	return count;
}

int main(){

	int n = 4;
	int k = 3;

	cout << ladder(n, k) << endl;

	return 0;
}
