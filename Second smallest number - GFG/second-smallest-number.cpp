//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        if(S>D * 9-1) return "-1";
        S = S - 1; 
        int x = D;
        string ans = string(D,'0');
        ans[0]='1';
        for(int i = D - 1; i >= 0; i--) {
            if(S-9 > 0) ans[i]='9';
            else if(i == D - 1) {
                ans[i] += S - 1;
                ans[i - 1] += 1;
                break;  
            }
            else if(S == 9) {
                ans[i] += S - 1;
                ans[i - 1] += 1;
                break;
            }
            else {
                ans[i] += S + 1;
                ans[i + 1] = '8';
                break;
            }
            S = S - 9;
        }
         return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends