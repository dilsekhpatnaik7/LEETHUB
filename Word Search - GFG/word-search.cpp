//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool solve(int i, int j, int index, vector<vector<char>>& board, string& word, vector<vector<int>>& vis, int di[], int dj[]) {
        if(index == word.length()) return true;

        for(int k = 0; k < 4; k++) {
            int nexti = i + di[k], nextj = j + dj[k];
            if(nexti >= 0 && nexti < board.size() && nextj >= 0 && nextj < board[0].size() && !vis[nexti][nextj] && board[nexti][nextj] == word[index]) {
                vis[nexti][nextj] = 1;
                if(solve(nexti, nextj, index + 1, board, word, vis, di, dj)) return true;
                vis[nexti][nextj] = 0;
            }
        }
        return false;
    }

    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == word[0]) {
                    vis[i][j] = 1;
                    if(solve(i, j, 1, board, word, vis, di, dj)) return true;
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends