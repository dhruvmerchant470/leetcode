class Solution {
public:
    #define ll long long
    #define MOD 10000000007
    int change(int amount, vector<int>& coins) {
        vector<vector<ll>>dp(coins.size()+1,vector<ll>(amount+1,0));
        dp[0][0]=1;
        for(ll i=1;i<=coins.size();i++){
            for(ll j=0;j<=amount;j++){
                if(coins[i-1]<=j) dp[i][j]=(dp[i][j-coins[i-1]]+dp[i-1][j])%MOD;
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[coins.size()][amount];
    }
};