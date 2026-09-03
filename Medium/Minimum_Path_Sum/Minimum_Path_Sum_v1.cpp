class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid[0].size();
        int m=grid.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        dp[0][0]=grid[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
            if(j==0) if(i!=0) dp[i][0]=dp[i-1][0]+grid[i][0];
            if(i==0) if(j!=0) dp[0][j]=dp[0][j-1]+grid[0][j];
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m-1][n-1];
    }
};