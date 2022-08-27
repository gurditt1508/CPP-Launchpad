#include<iostream>
#include<vector>

using namespace std;

int LIS_K(vector<int> arr, int n, int i){

	//base case
	if(i == n-1) return 1; //or (i==n) return 0;


	//recursive case
	int ans = 0;
	for(int j =i+1; j<n; j++){

		if(arr[j] >= arr[i]) ans = max(ans, LIS_K(arr, n, j));
	}

	return 1 + ans;

}

int LIS_KBottomUp(vector<int> arr, int n, int k){

	vector<int> dp(n);

	dp[n-1] = 1;
	for(int i=n-2; i>=k; i--){ //we only need to fill till kth index
		int ans = 0;
		for(int j=i+1; j<n; j++){
			if(arr[j] >= arr[i]){
				ans = max(ans, dp[j]);
			}
		}
		dp[i] = 1 + ans;
	}

	return dp[k];
}

int main(){

	vector<int> arr = {1,2,5,3,0,4,6};
	int n = arr.size();

	int k = 1;

	cout << LIS_K(arr, n, k) << endl;
	cout << LIS_KBottomUp(arr, n, k) << endl;

	return 0;
}