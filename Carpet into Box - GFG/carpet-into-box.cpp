//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int carpetBox(int A, int B, int C, int D){
        int a = 0, b = 0, c= 0, d = 0;
        while(A > C || A > D){
            if(A > C) a++;
            if(A > D) b++;
            A /= 2;
        }
        while(B > C || B > D){
            if(B > C) c++;
            if(B > D) d++;
            B /= 2;
        }
        return min((a + d), (b + c));
    }
};


//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int A,B,C,D;
        cin>>A>>B>>C>>D;
        
        Solution ob;

        int ans = ob.carpetBox(A,B,C,D);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends