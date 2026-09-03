class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curr_sum=0;
        int max_sum=nums[0];
        int curr_min=0;
        int min_sum=nums[0];
        int total=0;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            max_sum=max(curr_sum,max_sum);
            curr_min+=nums[i];
            min_sum=min(min_sum,curr_min);
            if(curr_sum<0) curr_sum=0;
            if(curr_min>0) curr_min=0; 
            total+=nums[i];
        }
        return max_sum>0?max(max_sum,total-min_sum):max_sum;
    }
};