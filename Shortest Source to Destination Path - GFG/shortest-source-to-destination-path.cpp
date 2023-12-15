//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(int nrow, int ncol, int n, int m, vector<vector<int>>& A) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && A[nrow][ncol] == 1;
    }
  
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        if(A[0][0] == 0) return -1;
        
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(N, vector<int>(M, 1e9));
        int delRow[] = {-1, 0, +1, 0};
	    int delCol[] = {0, +1, 0, -1};
	    
	    q.push({0, {0, 0}});
	    dist[0][0] = 0;
	    
	    while(!q.empty()) {
	        int distance = q.front().first;
	        int row = q.front().second.first;
	        int col = q.front().second.second;
	        q.pop();
	        
	        if(row == X && col == Y) return distance;
	        for(int i = 0; i < 4; i++) {
	            int nrow = row + delRow[i];
	            int ncol = col + delCol[i];
	            if(isValid(nrow, ncol, N, M, A)) {
	                if(distance + 1 < dist[nrow][ncol]) {
	                    dist[nrow][ncol] = distance + 1;
	                    q.push({distance + 1, {nrow, ncol}});
	                }
	            }
	        }
	    }
	    
	    return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends