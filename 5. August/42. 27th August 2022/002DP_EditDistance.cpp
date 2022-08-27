#include<iostream>
#include<vector>

using namespace std;

int editDistance(string s1, string s2, int m, int n, int i, int j){

	if(i == m) return n - j; //insert the remaining characters of s2
	if(j == n) return m - i; //delete the remaining characters of s1

	int X = editDistance(s1, s2, m, n, i, j+1); //letter insertion
	int Y = editDistance(s1, s2, m, n, i+1, j); //letter deletion

	int Z = editDistance(s1, s2, m, n, i+1, j+1); //letter substitution

	return min(1 + X, min(1 + Y, int(s1[i] != s2[j]) + Z)); // if s1[i] = s2[j], we don't count this substitution i.e. 0 + Z

}

int editDistanceBottomUp(string s1, string s2, int m, int n){

	vector<vector<int>> dp(m+1, vector<int>(n+1));

	//base case
	for(int j=0; j<=n; j++){
		dp[m][j] = n-j;
	}

	for(int i=0; i<=m; i++){
		dp[i][n] = m-i;
	}

	for(int i=m-1; i>=0; i--){
		for(int j=n-1; j>=0; j--){
			
			dp[i][j] = min(1 + dp[i][j+1], min(1 + dp[i+1][j], 
					int(s1[i]!=s2[j]) + dp[i+1][j+1]));
		}
	}

	return dp[0][0];
}

int main(){

	string s1 = "food";
	string s2 = "money";

	int m = s1.length();
	int n = s2.length();

	cout << editDistance(s1, s2, m, n, 0, 0) << endl;
	cout << editDistanceBottomUp(s1, s2, m, n) << endl;

	return 0;
}