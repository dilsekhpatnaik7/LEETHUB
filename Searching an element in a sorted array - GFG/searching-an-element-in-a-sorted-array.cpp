//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
class Solution{
public:
    int searchInSorted(int arr[], int N, int K) {
        int low = 0, high = N - 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(arr[mid] == K) return 1;
            else if(K > arr[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};

//{ Driver Code Starts.


int main(void) 
{ 
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        Solution ob;
        cout << ob.searchInSorted(arr, n, k) << endl;

    }

	return 0; 
} 

// } Driver Code Ends