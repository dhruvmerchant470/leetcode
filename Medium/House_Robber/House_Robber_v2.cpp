class Solution {
public:
    int solve(vector<int>&nums, int index, bool flag, vector<vector<int>>&dp){
        if(index>=nums.size()) return 0;
        if(dp[index][flag]!=-1) return dp[index][flag];
        if(flag) return dp[index][flag]=solve(nums,index+1,false,dp);
        else return dp[index][flag]=max(solve(nums,index+1,false,dp),nums[index]+solve(nums,index+1,true,dp));
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(nums,0,false,dp);
    }
};