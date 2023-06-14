//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
int binarySearch(int arr[], int n, int x, bool findStartIndex) {
    int low = 0, high = n - 1, ans = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == x) {
            ans = mid;
            if(findStartIndex) high = mid - 1;
            else low = mid + 1;
        } else {
            if(arr[mid] < x) low = mid + 1;
            else high = mid - 1;
        }
    }
    return ans;
}
vector<int> find(int arr[], int n , int x ) {
    int startingIndex = binarySearch(arr, n, x, true);
    int endingIndex = binarySearch(arr, n, x, false);
    return {startingIndex, endingIndex};
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends