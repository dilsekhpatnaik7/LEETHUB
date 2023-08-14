//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    bool areRotations(string s1,string s2) {
        queue<char> q1, q2;
        for(int i = 0; i < s1.size(); i++) {
            q1.push(s1[i]);
        }
        for(int i = 0; i < s2.size(); i++) {
            q2.push(s2[i]);
        }

        int k = s2.size();
        while(k) {
            char ch = q2.front();
            q2.pop();
            q2.push(ch);
            if(q1 == q2) return true;
            k--;
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends