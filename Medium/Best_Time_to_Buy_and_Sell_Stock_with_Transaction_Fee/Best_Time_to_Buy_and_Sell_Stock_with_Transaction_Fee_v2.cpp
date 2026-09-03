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
        vector<int>curr(2,0);
        vector<int>next(2,0);
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                    int profit=0;
                    if(buy)
                    {
                        int will_buy= -prices[index]+next[0];
                        int will_skip=next[1];
                        profit=max(profit,max(will_buy,will_skip));
                    }
                    else
                    {
                        int will_sell=prices[index]+next[1]-fee;
                        int will_skip=next[0];
                        profit=max(profit,max(will_skip,will_sell));
                    }
                    curr[buy]=profit;
            }
            next=curr;
        }
        return next[1];

    }
};