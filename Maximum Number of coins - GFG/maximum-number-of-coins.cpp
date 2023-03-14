//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int f(int i, int j, vector<int>& a, vector<vector<int>>& dp) {
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = -1e9;
        for(int k = i; k <= j; k++) {
                int curr = a[i-1] * a[k] * a[j+1] + f(i, k-1, a, dp) + f(k+1, j, a, dp);
                ans = max(ans, curr);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(int N, vector <int> &a) {
        a.insert(a.begin(),1);
        a.push_back(1);
        vector<vector<int>> dp(N+1, vector<int>(N+1, -1));
        return f(1, N, a, dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution S;
        cout<<S.maxCoins(n,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends