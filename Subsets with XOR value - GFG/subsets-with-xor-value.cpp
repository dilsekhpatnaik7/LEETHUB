//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int recursion(int index, int prefixXOR, int K, vector<int>&arr) {
        if(index == arr.size() && prefixXOR == K)return 1;
        else if(index == arr.size()) return 0;
            
        int pick = recursion(index + 1, prefixXOR ^ arr[index], K, arr);
        int notpick = recursion(index + 1, prefixXOR, K, arr);
        return pick + notpick;
    }

    int subsetXOR(vector<int> arr, int N, int K) {
        int prefixXOR = 0;
        return recursion(0, prefixXOR, K, arr);
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends