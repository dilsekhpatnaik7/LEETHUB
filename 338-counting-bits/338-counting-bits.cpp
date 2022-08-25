class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int n = i, c = 0;
            while(n){
                c++;
                n = n & (n-1);
            }
            ans.push_back(c);
        }
        return ans;
    }
};