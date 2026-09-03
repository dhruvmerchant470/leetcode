#define ll long long
class Solution {
public:
    int recursive(int x, int y,int n, int m,vector<vector<int>>&dp){
        if(x==m-1 && y==n-1) return 1;
        if(x<0 || x>=m || y<0 || y>=n) return 0;
        // cout<<x<<" "<<y<<endl;
        if(dp[x][y]!=-1) return dp[x][y];
        return dp[x][y]=recursive(x+1,y,n,m,dp)+recursive(x,y+1,n,m,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return recursive(0,0,n,m,dp);
    }
};