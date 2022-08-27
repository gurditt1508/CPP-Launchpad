#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int LongestCommonSubsequence(string s1, string s2, int m, int n, int i, int j){

	//base case
	if(i == m || j == n) return 0;

	//recursive case
	if(s1[i] == s2[j]){
		return 1 + LongestCommonSubsequence(s1, s2, m, n, i+1, j+1);

	}else{
		int X = LongestCommonSubsequence(s1, s2, m, n, i+1, j);
		int Y = LongestCommonSubsequence(s1, s2, m, n, i, j+1);
		return max(X, Y);
	} 
}

int LCSBottomUp(string s1, string s2, int m, int n){

	vector<vector<int>> dp(m+1, vector<int>(n+1, 0)); //since dp matrix is initialised with 0, we don't need to handle the base cases, 
													//we just fill the relevant cells.

	// for(int j=0; j<=n; j++){
	// 	dp[m][j] = 0;
	// }

	// for(int i=0; i<=m; i++){
	// 	dp[i][n] = 0;
	// }

	for(int i=m-1; i>=0; i--){
		for(int j=n-1; j>=0; j--){
			if(s1[i] == s2[j]){
				dp[i][j] = 1 + dp[i+1][j+1];
			}else{
				dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
			}
		}
	}

	return dp[0][0];

}

int main(){

	string s1 = "AGGTAB";
	string s2 = "GXTAXB";

	int m = s1.length();
	int n = s2.length();

	cout << LongestCommonSubsequence(s1, s2, m, n, 0, 0) << endl;
	cout << LCSBottomUp(s1, s2, m, n) << endl;

	return 0;
}