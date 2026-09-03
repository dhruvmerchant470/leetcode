class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid[0][0]==1) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 && j==0) || grid[i][j]==1) continue;
                int t1 = 0;
                int t2 = 0;
                if(i>0) t1 = dp[i-1][j];
                if(j>0) t2 = dp[i][j-1];
                dp[i][j] = t1+t2;
            }
        }
        return dp[n-1][m-1];
    }
};