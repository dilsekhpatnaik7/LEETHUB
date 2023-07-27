//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  bool sumByDiv(vector<int>& nums, long long mid, int K) {
        if(mid == 0) return false;
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            sum += (nums[i] + mid - 1) / mid;
            if(sum > K) return false;
        }
        return true;
    }
  
    int smallestDivisor(vector<int>& nums, int K) {
        if(nums.size() > K) return -1;
        int low = 0, high = *max_element(nums.begin(), nums.end());
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(sumByDiv(nums, mid, K)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends