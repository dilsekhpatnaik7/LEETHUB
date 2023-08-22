//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    public:
    int findMinOpeartion(vector<vector<int>> matrix, int n) {
        vector<int> values(n);
        int need = 0;
        for(int i = 0; i < n; i++) {
            int row = 0, col = 0;
            for(int j = 0; j < n; j++) {
                row += matrix[i][j];
                col += matrix[j][i];
            }
            need = max({need, row, col});
            values[i] = row;
        }
        int ans = 0;
        for(auto i: values) {
            ans += need - i;
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
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends