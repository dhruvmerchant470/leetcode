class Solution {
public:
    vector<vector<int>>dp;
    bool solve(vector<int>& nums, int t1, int sum, int n){
        if(n==0){
            if(t1==sum) return true;
            else return false;
        }

        if(t1==sum) return true;
        if(dp[n][t1]!=-1) return dp[n][t1];
        else if(t1<sum) return dp[n][t1]=solve(nums,t1+nums[n-1],sum-nums[n-1],n-1) || solve(nums,t1,sum,n-1);

        else return dp[n][t1]=solve(nums,t1,sum,n-1);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;

        for(int i=0;i<n;i++) sum+=nums[i];
        if(sum&1) return false;
        dp.assign(n+1,vector<int>(sum+1,-1));
        return solve(nums,0,sum,n);
    }
};