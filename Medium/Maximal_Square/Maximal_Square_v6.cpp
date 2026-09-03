class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = 0;
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                int d = dp[i-1][j];
                int r = dp[i][j-1];
                int di = dp[i-1][j-1];
                if(matrix[i-1][j-1] == '1'){
                    dp[i][j] = 1 + min({d,r,di});
                    maxi = max(maxi,dp[i][j]);
                }
            }
        }
        return maxi*maxi;
    }
};