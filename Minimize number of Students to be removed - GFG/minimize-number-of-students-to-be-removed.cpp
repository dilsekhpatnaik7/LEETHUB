//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int H[], int N) {
        vector<int> a;
        for(int i = 0; i < N; i++){
            int it = lower_bound(a.begin(), a.end(), H[i]) - a.begin();
            if(it == a.size()){
                a.push_back(H[i]);
            }
            else{
                a[it] = H[i];
            }
        }
        return N - a.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends