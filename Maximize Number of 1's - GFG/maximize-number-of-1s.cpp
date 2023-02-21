//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        int start = 0, end = 0, ans = 0;
        while(end != n) {
            if(m > 0) {
                if(arr[end] == 0) m--;
            }
            else {
                if(arr[end] == 0) {
                    while(arr[start] != 0) {
                        start++;
                    }
                    start++;
                }
            }
            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends