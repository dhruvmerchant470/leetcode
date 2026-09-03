class Solution {
public:

    int solve(vector<int>&cost,vector<int>&dp,int n)
{
    //base case
    if(n==1||n==0) return cost[n];

    if(dp[n]!=-1) return dp[n];

    //step2: memorisation
    dp[n]=min(solve(cost,dp,n-1),solve(cost,dp,n-2))+cost[n];

    return dp[n];
}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        //STEP 1
        vector<int>dp(n,-1);
        int ans=min(solve(cost,dp,n-1),solve(cost,dp,n-2));
        for(int i=0;i<n;i++) cout<<dp[i]<<" ";
        return ans;
    }
};