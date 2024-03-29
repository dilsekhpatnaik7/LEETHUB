//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
public:
    void merge(long long arr1[], long long arr2[], int n, int m) {
        int i = 0, j = 0, k = 0;
        int res[n+m];
        
        while(i < n && j < m){
            if(arr1[i] < arr2[j]) {
                res[k++] = arr1[i++];
            }
            else {
                res[k++] = arr2[j++];
            }
        }
        while(i < n) {
            res[k++] = arr1[i++];
        }
        while(j<m) {
            res[k++] = arr2[j++];
        }
        int index1 = 0;
        int index2 = n;
        for(int i = 0; i < n; i++){
           arr1[i] = res[index1++];
        }
        for(int i = 0; i < m; i++){
            arr2[i] = res[index2++];
        }
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	
	int T;
	cin >> T;
	
	while(T--){
	    int n, m;
	    cin >> n >> m;
	    
	    long long arr1[n], arr2[m];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    ob.merge(arr1, arr2, n, m); 

        for (int i = 0; i < n; i++) 
            cout<<arr1[i]<<" "; 
        
       
	    for (int i = 0; i < m; i++) 
		    cout<<arr2[i]<<" "; 
	    
	    cout<<endl;
	}

	return 0; 
} 

// } Driver Code Ends