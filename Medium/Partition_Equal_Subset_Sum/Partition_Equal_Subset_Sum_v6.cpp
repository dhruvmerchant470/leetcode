class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total_sum=0;
        int n = nums.size();
        for(auto &num: nums) total_sum+=num;
        if(total_sum&1) return false;
        total_sum/=2;
        vector<vector<bool>>dp(n+1,vector<bool>(total_sum+1,false));
        for(int i=0;i<=n;i++) dp[i][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=total_sum;j++){
                if(nums[i-1]<=j) dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][total_sum];
    }
};