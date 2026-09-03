class Solution {
public:
    int solve(vector<int>&prices,int index,int buy,vector<vector<int>>&dp)
    {
        if(index==prices.size()) return 0;
        if(dp[index][buy]!=-1) return dp[index][buy];
        int profit=0;
        if(buy)
        {
            int will_buy= -prices[index]+solve(prices,index+1,0,dp);
            int will_skip=solve(prices,index+1,1,dp);
            profit=max(profit,max(will_buy,will_skip));
        }
        else
        {
            int will_sell=prices[index]+solve(prices,index+1,1,dp);
            int will_skip=solve(prices,index+1,0,dp);
            profit=max(profit,max(will_skip,will_sell));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        return solve(prices,0,1,dp);
    }
};