//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
    string reverseWords(string S) { 
        string ans = "";
        int i = 0, n = S.length();

        while(i < n) {
            while(i < n && S[i] == '.') i++;
            if(i >= n) break;

            int j = i + 1;
            while(j < n && S[j] != '.') j++;
            string sub = S.substr(i, j - i);
            if(!ans.length()) ans = sub;
            else ans = sub + "." + ans;

            i = j + 1;
        }
        return ans;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends