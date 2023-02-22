//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int A[], int N){
	    int left = 0, right = N - 1;
	    while(left < right) {
	        int mid = (left + right) / 2;
	        if((mid % 2 == 0 && A[mid] == A[mid + 1]) || (mid % 2 == 1 && A[mid] == A[mid - 1]))
	            left = mid + 1;
	        else right = mid;
	    }
	    return A[left];
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends