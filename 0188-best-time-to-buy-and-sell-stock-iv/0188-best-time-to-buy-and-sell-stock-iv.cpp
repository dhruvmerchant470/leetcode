class Solution {
public:
    int solve(vector<int>& prices, int k, int canBuy, int index,vector<vector<vector<int>>>&dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][canBuy][k]!=-1) return dp[index][canBuy][k];
        if(canBuy){
            if(k>0){
                return dp[index][canBuy][k] = max(-prices[index]+solve(prices,k,false,index+1,dp),solve(prices,k,canBuy,index+1,dp));
            }
        }else{
            if(k>0){
                return dp[index][canBuy][k] = max(prices[index]+solve(prices,k-1,true,index+1,dp),solve(prices,k,canBuy,index+1,dp));
            }
        }
        return dp[index][canBuy][k] = 0;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(prices,k,true,0,dp);
    }
};