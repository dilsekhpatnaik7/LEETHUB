//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool check(string& s, string& t) {
        if(s.size() != t.size() + 1) return false;

        int first = 0, second = 0;
        while(first < s.size()) {
            if(second < t.size() && s[first] == t[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }
        if(first == s.size() && second == t.size()) return true;
        return false;
    }

    static bool comp(string& s, string& t) {
        return s.size() < t.size();
    }
  
    int longestChain(int n, vector<string>& words) {
        sort(words.begin(), words.end(), comp);

        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if(check(words[i], words[prev]) && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                }
            }
            if(dp[i] > maxi) {
                maxi = dp[i];
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> words(N);
        for (int i = 0; i < N; i++) {
            cin >> words[i];
        }
        Solution obj;
        cout << obj.longestChain(N, words) << "\n";
    }
    return 0;
}
// } Driver Code Ends