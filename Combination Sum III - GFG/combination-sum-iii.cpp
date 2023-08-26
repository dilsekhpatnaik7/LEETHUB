//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void getCombinations(int index, vector<int>& nums, int N, int K, vector<int>& ds, vector<vector<int>>& ans) {
        if(index == nums.size()) {
            if(N == 0 && ds.size() == K) {
                ans.push_back(ds);
            }
            return;
        }
        
        if(nums[index] <= N && ds.size() < K) {
            ds.push_back(nums[index]);
            getCombinations(index + 1, nums, N - nums[index], K, ds, ans);
            ds.pop_back();
        }
        getCombinations(index + 1, nums, N, K, ds, ans);
    }
  
    vector<vector<int>> combinationSum(int K, int N) {
        vector<int> nums;
        for(int i = 1; i <= 9; i++) {
            nums.push_back(i);
        }
        
        vector<int> ds;
        vector<vector<int>> ans;
        
        getCombinations(0, nums, N, K, ds, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends