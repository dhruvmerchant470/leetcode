class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int r = dp[i][j-1];
                int d = dp[i-1][j];
                int di = dp[i-1][j-1];
                if(matrix[i-1][j-1]==1){
                    dp[i][j] = 1 + min({r,d,di});
                }
            }
        }
        int sum = 0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
               sum+=dp[i][j];
            }
        }
        return sum;
    }
};