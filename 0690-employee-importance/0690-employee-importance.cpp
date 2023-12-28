/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    void dfs(vector<Employee*> employees, int node, vector<int>& vis, map<int, int> index, int& ans){
        vis[node] = 1;
        ans += employees[node]->importance;

        vector<int> adj = employees[node]->subordinates;
        for(auto it: adj){
            if(!vis[index[it]]) dfs(employees, index[it], vis, index, ans);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size(), ans = 0;
        
        vector<int> vis(n, 0);
        map<int, int> index;
        
        for(int i = 0; i < n; i++) {
            index[employees[i]->id] = i;
        }
        
        dfs(employees, index[id], vis, index, ans);
        return ans;
    }
};