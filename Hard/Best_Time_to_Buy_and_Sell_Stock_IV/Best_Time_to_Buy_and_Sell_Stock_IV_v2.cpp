class Solution {
public:
    int solve(vector<int>&prices,int limit,int buy,int index,vector<vector<vector<int>>>&dp)
    {
        if(index==prices.size()||limit==0) return 0;
        if(dp[index][buy][limit]!=-1) return dp[index][buy][limit];
        int profit=0;
        if(buy)
        {
            int will_buy=-prices[index]+solve(prices,limit,0,index+1,dp);
            int will_skip=solve(prices,limit,1,index+1,dp);
            profit=max(will_buy,will_skip);
        }
        else
        {
            int will_sell=prices[index]+solve(prices,limit-1,1,index+1,dp);
            int will_skip=solve(prices,limit,0,index+1,dp);
            profit=max(will_sell,will_skip);
        }
        return dp[index][buy][limit]= profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return solve(prices,k,1,0,dp);
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int limit=1;limit<=k;limit++)
                {
                    int profit=0;
                    if(buy)
                    {
                        int will_buy=-prices[index]+dp[index+1][0][limit];
                        int will_skip=dp[index+1][1][limit];
                        profit=max(will_buy,will_skip);
                    }
                    else
                    {
                        int will_sell=prices[index]+dp[index+1][1][limit-1];
                        int will_skip=dp[index+1][0][limit];
                        profit=max(will_sell,will_skip);
                    }
                    dp[index][buy][limit]= profit; 
                }
            }
        }
        return dp[0][1][k];
    }
};