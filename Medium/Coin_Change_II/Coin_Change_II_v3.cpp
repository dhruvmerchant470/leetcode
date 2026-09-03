class Solution {
public:
    int help(int amount,vector<int>&coins,int index,vector<vector<int>>&dp){
        if(amount==0) return 1;
        if(index==0){
            if(amount==0) return 1;
            else return 0;
        }
        if(dp[index][amount]!=-1) return dp[index][amount];
        if(coins[index-1]<=amount) return dp[index][amount]=help(amount-coins[index-1],coins,index,dp)+help(amount,coins,index-1,dp);
        else return dp[index][amount]=help(amount,coins,index-1,dp);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        return help(amount,coins,coins.size(),dp);
    }
};