class Solution {
public:
    int solve(int amount, vector<int>&coins, int index,vector<vector<int>>&dp){
        if(index>=coins.size()){
            if(amount==0) return 1;
            else return 0;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        if(coins[index]<=amount) return dp[index][amount]=solve(amount-coins[index],coins,index,dp) + solve(amount,coins,index+1,dp);
        else return dp[index][amount]=solve(amount,coins,index+1,dp);
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        return solve(amount,coins,0,dp);
    }
};