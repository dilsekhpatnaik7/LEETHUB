//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution {
    public:
    bool areIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;

        unordered_map<char, char> map1;
        unordered_map<char, bool> map2;

        for(int i = 0; i < s.length(); i++) {
            char ch1 = s[i], ch2 = t[i];
            if(map1.find(ch1) != map1.end()) {
                if(map1[ch1] != ch2) return false;
            } else {
                if(map2.find(ch2) != map2.end()) return false;
                else {
                    map1[ch1] = ch2;
                    map2[ch2] = true;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends