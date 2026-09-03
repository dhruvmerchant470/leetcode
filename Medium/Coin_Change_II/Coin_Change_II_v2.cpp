#define ll long long
#define MOD 100000000007
class Solution {
public:
    int solve(int n, vector<int>&coins, int amount,vector<vector<ll>>&dp){
        if(n==0) {
            if(amount == 0) return 1;
            else return 0;
        }
        if(amount == 0) return 1;
        if(dp[n][amount]!=-1) return dp[n][amount];
        if(coins[n-1]<=amount) return dp[n][amount]=solve(n,coins,amount-coins[n-1],dp)%MOD+solve(n-1,coins,amount,dp)%MOD;
        else return dp[n][amount]=solve(n-1,coins,amount,dp)%MOD;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<ll>>dp(coins.size()+1,vector<ll>(amount+1,-1));
        return solve(coins.size(),coins,amount,dp);
    }
};