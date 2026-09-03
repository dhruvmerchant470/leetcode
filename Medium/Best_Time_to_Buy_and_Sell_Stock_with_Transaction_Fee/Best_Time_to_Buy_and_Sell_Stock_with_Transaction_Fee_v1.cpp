class Solution {
public:
 int solve(vector<int>&prices,int index,int buy,vector<vector<int>>&dp,int fee)
    {
        if(index==prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit=0;
        if(buy)
        {
            int will_buy= -prices[index]+solve(prices,index+1,0,dp,fee);
            int will_skip=solve(prices,index+1,1,dp,fee);
            profit=max(profit,max(will_buy,will_skip));
        }
        else
        {
            int will_sell=prices[index]+solve(prices,index+1,1,dp,fee)-fee;
            int will_skip=solve(prices,index+1,0,dp,fee);
            profit=max(profit,max(will_skip,will_sell));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(prices,0,1,dp,fee);
    }
};