class Solution {
public:
    int solve(int startIndex,int endIndex,vector<vector<int>>&dp)
    {
        if(startIndex>=endIndex) return 0;
        if(dp[startIndex][endIndex]!=-1) return dp[startIndex][endIndex];
        int money=INT_MAX;
        for(int i=startIndex;i<=endIndex;i++){
            money=min(money,i+max(solve(startIndex,i-1,dp),solve(i+1,endIndex,dp)));
        }
        return dp[startIndex][endIndex]=money;
    } 
    int solveTab(int n)
    {
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int startIndex=n;startIndex>=1;startIndex--)
        {
            for(int endIndex=startIndex+1;endIndex<=n;endIndex++)
            {
                int money=INT_MAX;
                 for(int i=startIndex;i<=endIndex;i++){
                    money=min(money,i+max(dp[startIndex][i-1],dp[i+1][endIndex]));
                 }
                dp[startIndex][endIndex]=money;
            }
        }
        return dp[1][n];
    }
    int getMoneyAmount(int n) {
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveTab(n);

    }
};