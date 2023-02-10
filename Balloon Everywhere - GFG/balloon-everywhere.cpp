//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        vector<int>v;
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            if(s[i]=='b'||s[i]=='a'||s[i]=='l'||s[i]=='o'||s[i]=='n'){
                m[s[i]]++;
            }
        }
        m['l'] = m['l']/2;
        m['o'] = m['o']/2;
        v.push_back(m['b']);
        v.push_back(m['l']);
        v.push_back(m['o']);
        v.push_back(m['n']);

        return *min_element(v.begin(),v.end());
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends