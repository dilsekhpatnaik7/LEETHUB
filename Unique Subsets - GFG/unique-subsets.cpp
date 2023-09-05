//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    void solve(int index, vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans) {
        ans.push_back(ds);
    
        for(int i = index; i < arr.size(); i++) {
            if(i > index && arr[i] == arr[i - 1]) continue;
            ds.push_back(arr[i]);
            solve(i + 1, arr, ds, ans);
            ds.pop_back();
        }
    }
    
    vector<vector<int> > AllSubsets(vector<int> arr, int n) {
        sort(arr.begin(), arr.end());
        vector<int> ds;
        vector<vector<int>> ans;
        
        solve(0, arr, ds, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   



// } Driver Code Ends