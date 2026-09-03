class Solution {
public:
    int solve(vector<int>&prices, bool canBuy, bool prevSell, int index, vector<vector<vector<int>>>&dp){
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][canBuy][prevSell]!=-1) return dp[index][canBuy][prevSell];
        if(canBuy){
            if(!prevSell){
                return dp[index][canBuy][prevSell] = max(-prices[index]+solve(prices,false,false,index+1,dp),solve(prices,canBuy,prevSell,index+1,dp));
            }else{
                return dp[index][canBuy][prevSell] = solve(prices,canBuy,false,index+1,dp);
            }
        }else{
            return dp[index][canBuy][prevSell] = max(prices[index]+solve(prices,true,true,index+1,dp),solve(prices,canBuy,prevSell,index+1,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(2,-1)));
        return solve(prices,true,false,0,dp);
    }
};