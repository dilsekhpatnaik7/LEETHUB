class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(count(nums.begin(),nums.end(),nums[i])==1)
                ans+=nums[i];
        }
        return ans;
    }
};