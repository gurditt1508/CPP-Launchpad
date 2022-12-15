#include<bits/stdc++.h>
using namespace std;

int LCS(string a, string b, int m, int n, int i, int j) {
    if(i==m || j==n) 
        return 0;

    if(a[i]==b[j])
        return 1+LCS(a, b, m, n, i+1, j+1);
    
    int X = LCS(a, b, m, n, i+1, j);
    int Y=LCS(a, b, m, n, i, j+1);

    return max(X, Y);
}

vector<vector<int>> dp;

int LCS_iterative(string a, string b, int m, int n) {

    dp=vector<vector<int>>(m+1, vector<int>(n+1));
    for(int i=m-1; i>=0; i--) {
        for(int j=n-1; j>=0; j--) {
            if(a[i]==b[j]) {
                dp[i][j]=1+dp[i+1][j+1];
            }
            else {
                dp[i][j]=max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    return dp[0][0];
}

string lcs(string a, string b, int m, int n) {
    string ans="";
    int i=m-1, j=n-1;
    while(i>=0 && j>=0) {
        if(a[i]==b[j]) {
            ans+=a[i];
            i--; j--;
        } else if(dp[i-1][j]>dp[i][j-1]){
            i--;
        } else {
            j--;
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {

    string a = "abced";
    string b="blocmegfgdyr";

    int m=(int)a.size();
    int n=(int)b.size();
    cout<<LCS(a, b, m, n, 0, 0)<<endl;
    cout<<LCS_iterative(a,b,m,n)<<endl;

    cout<<lcs(a, b, m, n)<<endl;

    return 0;
}