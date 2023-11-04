//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int solve(string& s, string& t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= m; j++) {
			if(i == 0 || j == 0) dp[i][j] = 0;
			else if(s[i - 1] == t[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n][m];
}

int minDeletions(string str, int n) { 
    string t = str;
    reverse(t.begin(), t.end());
    return n - solve(str, t);
} 