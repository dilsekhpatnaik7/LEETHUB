//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    bool solve(int n, int m, string& pattern, string& text) {
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        for(int j = 1; j <= m; j++) dp[0][j] = false;

        for(int i = 1; i <= n; i++) {
            bool flag = true;
            for(int ii = 1; ii <= i; ii++) {
                if(pattern[ii - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(pattern[i - 1] == text[j - 1] || pattern[i -1] == '?') dp[i][j] = dp[i - 1][j - 1];
                else if(pattern[i - 1] == '*') dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
  
    int wildCard(string pattern, string str) {
        int n = pattern.size(), m = str.size();
        return solve(n, m, pattern, str);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends