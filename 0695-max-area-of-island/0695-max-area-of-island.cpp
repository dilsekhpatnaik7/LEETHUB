class Solution {
public:
    bool isValid(int nrow, int ncol, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol];
    }
    
    int dfs(int row, int col, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        int area = 1;
        
        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};
        
        for(int i = 0; i < 4; i++) {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(isValid(nrow, ncol, n, m, grid, vis)) area += dfs(nrow, ncol, n, m, grid, vis);
        }
        return area;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxArea = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    int currentArea = dfs(i, j, n, m, grid, vis);
                    maxArea = max(maxArea, currentArea);
                }
            }
        }
        
        return maxArea;
    }
};