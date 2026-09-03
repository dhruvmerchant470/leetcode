class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curr=0;
        int ans=INT_MAX;
        int l=0,r=0;
        while(r<nums.size()){
            curr+=nums[r];
            while(curr>=target){
                ans=min(ans,r-l+1);
                curr-=nums[l];
                l++;
            }
            r++;
        }
        return ans==INT_MAX?0:ans;
    }   
};