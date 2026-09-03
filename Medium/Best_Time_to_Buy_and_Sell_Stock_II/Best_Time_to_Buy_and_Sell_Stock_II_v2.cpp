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
    int solveTab(vector<int>& prices)
    {
        int n=prices.size();
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,0));
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                int profit=0;
                if(buy)
                {
                    int will_buy= -prices[index]+dp[index+1][0];
                    int will_skip=dp[index+1][1];
                    profit=max(will_buy,will_skip);
                }
                else
                {
                    int will_sell=prices[index]+dp[index+1][1];
                    int will_skip=dp[index+1][0];
                    profit=max(will_skip,will_sell);
                }
                dp[index][buy]=profit;
            }
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices) {
       
        return solveTab(prices);
    }
};