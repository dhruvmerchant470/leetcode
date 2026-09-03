class Solution {
public:
    int solve(int index,bool zeroTake,vector<int>&nums,vector<vector<int>>&dp){
        if(index>=nums.size()) return 0;
        if(dp[index][zeroTake]!=-1) return dp[index][zeroTake];
        int nottake=solve(index+1,zeroTake,nums,dp);
        int take=INT_MIN;
        if(index==nums.size()-1){
            if(!zeroTake) take=nums[index]+solve(index+2,zeroTake,nums,dp);
        }
        else{
            take=nums[index]+solve(index+2,zeroTake,nums,dp);
        }
        // cout<<take<<" "<<nottake<<endl;
        return dp[index][zeroTake]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        int zero1=solve(1,0,nums,dp);
        // cout<<solve(2,1,nums);
        int zero2=nums[0]+solve(2,1,nums,dp);
        return max(zero1,zero2);
    }
};