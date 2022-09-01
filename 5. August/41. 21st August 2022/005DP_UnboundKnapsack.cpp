#include<bits/stdc++.h>

using namespace std;

int fBottomUp(vector<int>& wt, vector<int>& val, int w, int n) {

	vector<vector<int>> dp(n, vector<int>(w+1));

	for(int W=0; W<=w; W++) {
		dp[0][W] = (int)((W/wt[0]) * val[0]);
	}

	for(int i=1; i<n; i++) {
		for(int W=0; W<=w; W++) {
			int notTake = dp[i-1][W];
			int take = 0;
			if(wt[i] <= W) {
				take = val[i] + dp[i][W-wt[i]];
			}
			dp[i][W] = max(take, notTake);
		}
	}

	return dp[n-1][w];

}

int main() {

	int n;
	cin >> n;

	int w;
	cin >> w;

	vector<int> val(n);
	vector<int> wt(n);

	for(int i=0; i<n; i++) {
		cin >> wt[i];
	}

	for(int i=0; i<n; i++) {
		cin >> val[i];
	}

	//cout << f(n-1, wt, val, w) << endl;
	cout << fBottomUp(wt, val, w, n) << endl;

	return 0;
}