//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    long long max(long long a, int b) {
        return a >= b ? a : b;
    }
  
    long long findMax(int arr[], int n) {
        long long maximum = INT_MIN;
        for(int i = 0; i < n; i++) {
            maximum = max(maximum, arr[i]);
        }
        return maximum;
    }    
    
    long long summation(int arr[], int n) {
        long long sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }
        return sum;
    }
    
    bool canSplit(int arr[], int n, long long maxCapacity, int ways) {
        long long capacity = 0, calculatingWays = 1;
        for(int i = 0; i < n; i++) {
            if(arr[i] + capacity <= maxCapacity) capacity += arr[i];
            else {
                calculatingWays++;
                capacity = arr[i];
            }
            if(calculatingWays > ways) return true;
        }
        return false;
    }
    
    long long minTime(int arr[], int n, int k) {
        long long low = findMax(arr, n);
        long long high = summation(arr, n);
        
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(canSplit(arr, n, mid, k)) low = mid + 1;
            else high = mid -1;
        }
        return low;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends