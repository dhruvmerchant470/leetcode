class Solution {
public:
    #define ll long long
    #define MOD 10000000007
    int change(int amount, vector<int>& coins) {
        ll n = coins.size();
        vector<vector<ll>>dp(n+1,vector<ll>(amount+1,0));
        for(ll i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=amount;j++){
                if(coins[i-1]<=j) dp[i][j] = (dp[i-1][j]%MOD+dp[i][j-coins[i-1]]%MOD)%MOD;
                else dp[i][j]=dp[i-1][j]%MOD;
            }
        }
        return dp[n][amount];
    }
};