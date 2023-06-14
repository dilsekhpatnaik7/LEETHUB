//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int binarySearch(int arr[], int n, int x, bool findStartIndex) {
        int low = 0, high = n - 1, ans = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] == x) {
                ans = mid;
                if(findStartIndex) high = mid - 1;
                else low = mid + 1;
            }
            else {
                if(arr[mid] < x) low = mid + 1;
                else high = mid - 1;
            }
        }
        return ans;
    }
    
	int count(int arr[], int n, int x) {
	    int startingIndex = binarySearch(arr, n, x, true);
        int endingIndex = binarySearch(arr, n, x, false);
        if(arr[startingIndex] != x || arr[endingIndex] != x) return 0;
        return endingIndex - startingIndex + 1;
	}
};

//{ Driver Code Starts.

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
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends