// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    int findFloor(vector<long long> v, long long n, long long x){
        long long low = 0, high = n - 1, ans = -1;
        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(v[mid] == x) return mid;
            else if(v[mid] < x) {
                low = mid + 1;
                ans = mid;
            }
            else high = mid - 1;
        }
        return ans != -1 ? ans : -1;
    }
};


// { Driver Code Starts.

int main() {
	
	long long t;
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long x;
	    cin >> x;
	    
	    vector<long long> v;
	    
	    for(long long i = 0;i<n;i++){
	        long long temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}  // } Driver Code Ends