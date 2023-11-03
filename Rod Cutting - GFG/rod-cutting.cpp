//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int index, int target, int price[], vector<vector<int>> &dp) {
    	if(index == 0) return target * price[0];
    	if(dp[index][target] != -1) return dp[index][target];
    
    	int notTake = solve(index - 1, target, price, dp);
    	int take = -1e9;
    	int rodLength = index + 1;
    	if(rodLength <= target) take = price[index] + solve(index, target - rodLength, price, dp);
    
    	return dp[index][target] = max(take, notTake);
    }
  
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
	    return solve(n - 1, n, price, dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends