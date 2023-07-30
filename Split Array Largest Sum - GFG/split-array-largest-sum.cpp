//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMax(int arr[], int N) {
        int maximum = INT_MIN;
        for(int i = 0; i < N; i++) {
            maximum = max(maximum, arr[i]);
        }
        return maximum;
    }    
    
    int summation(int arr[], int N) {
        int sum = 0;
        for(int i = 0; i < N; i++) {
            sum += arr[i];
        }
        return sum;
    }
    
    bool canSplit(int arr[], int N, long long maxCapacity, int ways) {
        int capacity = 0, calculatingWays = 1;
        for(int i = 0; i < N; i++) {
            if(arr[i] + capacity <= maxCapacity) capacity += arr[i];
            else {
                calculatingWays++;
                capacity = arr[i];
            }
            if(calculatingWays > ways) return true;
        }
        return false;
    }
    
    int splitArray(int arr[] ,int N, int K) {
        int low = findMax(arr, N);
        int high = summation(arr, N);
        
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(canSplit(arr, N, mid, K)) low = mid + 1;
            else high = mid -1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends