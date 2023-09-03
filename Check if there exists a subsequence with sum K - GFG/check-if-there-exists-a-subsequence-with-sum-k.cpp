//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    bool subsetSum(int index, int sum, int k, vector<int>& a) {
        if(index == a.size()) {
            if(sum == k) return true;
            else return false;
        }
    
        if(sum <= k) {
            sum += a[index];
            if(subsetSum(index + 1, sum, k, a)) return true;
            sum -= a[index];
        }
        if(subsetSum(index + 1, sum, k, a)) return true;
    
        return false;
    }

    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return subsetSum(0, 0, k, arr);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        bool ans = obj.checkSubsequenceSum(n, arr, k);
        cout<<( ans ? "Yes" : "No")<<"\n";
    }
    return 0;
}
// } Driver Code Ends