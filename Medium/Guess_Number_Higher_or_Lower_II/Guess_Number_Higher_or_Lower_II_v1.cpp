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
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,dp);

    }
};