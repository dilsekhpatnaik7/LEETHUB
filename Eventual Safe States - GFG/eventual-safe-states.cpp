//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjRev[V];
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++) {
            for(auto adjacentNode: adj[i]) {
                adjRev[adjacentNode].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;
        vector<int> safeNodes;
        
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) q.push(i);
        }
        
        while(!q.empty()) {
            int node = q.front(); q.pop();
            safeNodes.push_back(node);
            
            for(auto adjacentNode: adjRev[node]) {
                indegree[adjacentNode]--;
                if(indegree[adjacentNode] == 0) q.push(adjacentNode);
            }
        }
    
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends