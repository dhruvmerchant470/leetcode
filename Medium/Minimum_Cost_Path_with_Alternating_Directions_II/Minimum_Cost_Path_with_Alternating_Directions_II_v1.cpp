class Solution {
public:
    #define ll long long 
    long long minCost(int m,int n, vector<vector<int>>& waitCost) {
        vector<vector<ll>>dp(m,vector<ll>(n,1e18));
        dp[0][0]=1;
        for(ll i=0;i<m;i++){
            for(ll j=0;j<n;j++){
                if(i==0 && j==0) continue;
                else if(i==0) dp[i][j]=dp[i][j-1]+(i+1)*(j+1)+waitCost[i][j];
                else if(j==0)  dp[i][j]=dp[i-1][j]+(i+1)*(j+1)+waitCost[i][j];
                else dp[i][j]=min(dp[i-1][j],dp[i][j-1])+(i+1)*(j+1)+waitCost[i][j];
            }
        }
        return dp[m-1][n-1]-waitCost[m-1][n-1];
    }
};