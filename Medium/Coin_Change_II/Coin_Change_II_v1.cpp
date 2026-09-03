#define ll long long
#define MOD 100000000007
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        ll n=coins.size();
        vector<vector<ll>>dp(n+1,vector<ll>(amount+1,-1));
        for(ll i=0;i<=n;i++){
            for(ll j=0;j<=amount;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }

        for(ll i=1;i<=n;i++){
            for(ll j=0;j<=amount;j++){
                if(coins[i-1]<=j) dp[i][j]=dp[i][j-coins[i-1]]%MOD+dp[i-1][j]%MOD;
                else dp[i][j]=dp[i-1][j]%MOD;
            }
        }

        return dp[n][amount];
    }
};