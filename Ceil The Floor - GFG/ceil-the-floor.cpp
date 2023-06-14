//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    sort(arr, arr + n);
    int low = 0, high = n - 1, flooor = -1, ceilll = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == x) return make_pair(arr[mid], arr[mid]);
        else if(arr[mid] < x) low = mid + 1, flooor = mid;
        else high = mid - 1, ceilll = mid;
    }
    if(ceilll != -1) ceilll = arr[ceilll];
    if(flooor != -1) flooor = arr[flooor];
    return make_pair(flooor, ceilll);
}