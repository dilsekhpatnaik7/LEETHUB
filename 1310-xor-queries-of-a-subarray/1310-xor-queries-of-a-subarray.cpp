class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& q) {
        vector<int> ans;
        vector<int> pre(arr.size());
        pre[0] = arr[0];
        for(int i = 1; i<arr.size(); i++){
            pre[i] = pre[i-1]^arr[i];
        }
        for(int i=0;i<q.size();i++){
            int l = q[i][0];
            int r = q[i][1];
            
            if(l==0) ans.push_back(pre[r]);
            else ans.push_back(pre[r]^pre[l-1]);
        }
        return ans;
    }
};