class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto n:nums) m[n]++;
        for(auto n:m){
            if(n.second>=2)
                return true;
        }
        return false;
    }
};