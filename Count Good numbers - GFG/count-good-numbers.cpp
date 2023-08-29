//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long myPow(long long x, long long n,int mod) {
        if(n==0) return 1;
        if(n%2==0) return myPow((x*x)%mod,n/2,mod)%mod;
        else return x*myPow(x,n-1,mod) %mod;
    }
    
    int countGoodNumbers(long long N) {
        int mod = 1e9+7;
        long long four = N/2;
        long long five =N/2+N%2;

        return (myPow(5,five,mod) * myPow(4,four,mod))%mod;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;

        cout << ob.countGoodNumbers(N) << endl;
    }
}
// } Driver Code Ends