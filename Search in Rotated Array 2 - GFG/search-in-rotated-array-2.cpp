//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool binarySearch(vector<int>& A, int low, int high, int key) {
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(key == A[mid]) return true;
            if(A[low] == A[mid] && A[mid] == A[high]) {
                low++;
                high--;
                continue;
            }
            if(A[low] <= A[mid]) {
                if((A[low] <= key) && (key < A[mid])) high = mid - 1;
                else low = mid + 1;
            }
            else {
                if((A[mid] <= key) && (key <= A[high])) low = mid + 1;
                else high = mid - 1;
            }
        }
        return false;
    }   
  
    bool Search(int N, vector<int>& A, int Key) {
        return binarySearch(A, 0, N - 1, Key);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends