class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        int n=nums.size();
        for(int elt:nums) sum+=elt;
        int t=(sum+target);
        if(t&1 || sum<target) return 0;
        if(t<0) return 0;
        t/=2;
        
        vector<vector<int>>dp(n+1,vector<int>(t+1));
        cout<<dp.max_size()<<endl;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=t;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=t;j++){
                if(nums[i-1]<=j) dp[i][j]=dp[i-1][j-nums[i-1]]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }

        return dp[n][t];
    }
};