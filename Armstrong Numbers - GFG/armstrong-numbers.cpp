//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int sendCube(int n){
        return n*n*n;
    }
    string armstrongNumber(int n){
        int ans = 0, temp = n;
        while(n != 0){
            int d = n % 10;
            ans += sendCube(d);
            n /= 10;
        }
        return ans == temp ? "Yes" : "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends