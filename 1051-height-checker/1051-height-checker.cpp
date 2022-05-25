class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int ans=0;
        vector<int> c=heights;
        sort(heights.begin(),heights.end());
        for(int i=0;i<heights.size();i++){
            if(c[i]!=heights[i]) ans++;
        }
        return ans;
    }
};