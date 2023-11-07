//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int n, int m, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int ans = 0;
        for(int i = 0; i < n; i++) dp[i][0] = matrix[i][0];
        for(int j = 0; j < m; j++) dp[0][j] = matrix[0][j];

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] == 0) dp[i][j] = 0;
                else {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans += dp[i][j];
            }
        }
        return ans;
    }
  
    int countSquares(int N, int M, vector<vector<int>> &matrix) {
        vector<vector<int>> dp(N, vector<int>(M, 0));
        return solve(N, M, matrix, dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.countSquares(N, M, matrix) << endl;
    }
    return 0;
}
// } Driver Code Ends