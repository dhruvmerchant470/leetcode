class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0,right=0;
        int curr_sum=0;
        int ans=INT_MAX;
        int n=nums.size();
        while(right<n){
            curr_sum+=nums[right];
            while(curr_sum>=target){
                ans=min(ans,right-left+1);
                curr_sum-=nums[left++];
            }
            right++;
        }
        return ans==INT_MAX?0:ans;
    }
};