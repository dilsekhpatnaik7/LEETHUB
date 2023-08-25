//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution {
public:
    void getSubsetSum(int index, vector<int>& arr, int sum, vector<int>& ans) {
        if(index == arr.size()) {
            ans.push_back(sum);
            return;
        }
        
        sum += arr[index];
        getSubsetSum(index + 1, arr, sum, ans);
        
        sum -= arr[index];
        getSubsetSum(index + 1, arr, sum, ans);
    }

    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ans;
        getSubsetSum(0, arr, 0, ans);
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
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends