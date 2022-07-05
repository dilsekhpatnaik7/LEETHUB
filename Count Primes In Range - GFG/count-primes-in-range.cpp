// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPrimes(int L, int R) {
        // code here
        vector<bool> r(R+1,true);
        r[0]=r[1]=false;
        for(int i=2;i<=sqrt(R);i++){
            if(r[i]){
                for(int j=i*i;j<=R;j+=i){
                    r[j]=false;
                }
            }
        }
        int c=0;
        for(int i=L;i<=R;i++){
            if(r[i])
                c++;
        }
        return c;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R;
        Solution ob;
        int ans = ob.countPrimes(L, R);
        cout << ans << "\n";
    }
}  // } Driver Code Ends