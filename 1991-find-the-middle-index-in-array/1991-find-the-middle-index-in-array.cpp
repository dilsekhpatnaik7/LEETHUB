class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        int t=0;
        for(int i=0;i<nums.size();i++){
            t+=nums[i];
            if(sum-t+nums[i] == t)
                return i;
        }
        return -1;
    }
};