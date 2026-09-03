class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi_sum=INT_MIN;
        int curr_sum=0;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            maxi_sum=max(maxi_sum,curr_sum);
            if(curr_sum<0) curr_sum=0;
        }
        return maxi_sum;
    }
};