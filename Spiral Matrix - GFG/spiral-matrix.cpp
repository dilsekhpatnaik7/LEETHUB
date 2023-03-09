//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
	int findK(vector<vector<int>> &a, int n, int m, int k) {
	    vector<int> ans;
        int row = n;
        int col = m;
        int total = row * col, count = 0;

        int startingRow = 0, endingRow = row - 1, startingCol = 0, endingCol = col - 1;
        while(count < total) {
            // Starting Row
            for(int index = startingCol; index <= endingCol && count < total; index++) {
                ans.push_back(a[startingRow][index]);
                count++;
            }
            startingRow++;
            
            // Ending Column
            for(int index = startingRow; index <= endingRow && count < total; index++) {
                ans.push_back(a[index][endingCol]);
                count++;
            }
            endingCol--;

            // Ending Row
            for(int index = endingCol; index >= startingCol && count < total; index--) {
                ans.push_back(a[endingRow][index]);
                count++;
            }
            endingRow--;

            // Starting Column
            for(int index = endingRow; index >= startingRow && count < total; index--) {
                ans.push_back(a[index][startingCol]);
                count++;
            }
            startingCol++;
        }
        return ans[k - 1];
    }

};

//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        vector<vector<int>> a(n, vector<int>(m, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }

        Solution obj;

        cout<< obj.findK(a, n, m, k) << "\n";
        
       
    }
}
// } Driver Code Ends