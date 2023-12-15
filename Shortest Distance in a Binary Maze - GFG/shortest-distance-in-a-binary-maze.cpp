//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isValid(int nrow, int ncol, int n, int m, vector<vector<int>>& grid) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1;
    }
  
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        int delRow[] = {-1, 0, +1, 0};
	    int delCol[] = {0, +1, 0, -1};
	    
	    q.push({0, {source.first, source.second}});
	    dist[source.first][source.second] = 0;
	    
	    while(!q.empty()) {
	        int distance = q.front().first;
	        int row = q.front().second.first;
	        int col = q.front().second.second;
	        q.pop();
	        
	        if(row == destination.first && col == destination.second) return distance;
	        for(int i = 0; i < 4; i++) {
	            int nrow = row + delRow[i];
	            int ncol = col + delCol[i];
	            if(isValid(nrow, ncol, n, m, grid)) {
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends