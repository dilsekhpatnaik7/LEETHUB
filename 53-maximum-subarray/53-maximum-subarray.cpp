class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,smax=INT_MIN;
        for(auto n:nums){
            sum+=n;
            smax=max(smax,sum);
            if(sum<0) sum=0;
        }
        return smax;
    }
};