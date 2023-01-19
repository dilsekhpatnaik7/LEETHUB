//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    long long maxSubarraySum(int arr[], int n){
        // Kadane's Algorithm
        int sum = 0, maxSum = INT_MIN;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            maxSum = max(maxSum, sum);
            if(sum < 0) sum = 0;
        }
        return maxSum;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends