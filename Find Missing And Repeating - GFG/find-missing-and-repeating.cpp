//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        unordered_map<int,int>map;
        int ans[2];
        int sum = 0, flag = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            flag += i+1;
            map[arr[i]]++;
        }
        sum = sum - flag;
        for(int i = 0; i < n; i++){
            if(map[arr[i]] == 2) ans[0] = arr[i];
        }
        ans[1] = ans[0] - sum;
        int *cnt = ans;
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends