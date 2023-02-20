//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution {   
public:
    const int mod = 1e9+7;
    int countPaths(int N) {
        vector<vector<int>> dp(4, vector<int>(N + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= N; i++) {
            for(int j = 0; j <= 3; j++) {
                dp[j][i] = (dp[j][i] + dp[(j + 1) % 4][i - 1]) % mod;
                dp[j][i] = (dp[j][i] + dp[(j + 2) % 4][i - 1]) % mod;
                dp[j][i] = (dp[j][i] + dp[(j + 3) % 4][i - 1]) % mod;
            }
        }
        return dp[0][N];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends