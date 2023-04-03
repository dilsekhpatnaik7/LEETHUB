//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++


class Solution {
public:
    int xmod11(string x) {
        int n = x.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = ((ans * 10) + (x[i] - '0')) % 11;
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
        string x;
        cin>>x;
        Solution ob;
        int ans = ob.xmod11(x);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends