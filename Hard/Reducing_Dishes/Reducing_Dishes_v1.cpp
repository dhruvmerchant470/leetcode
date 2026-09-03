class Solution {
public:
    int solve(vector<int>&s,int time,int index,vector<vector<int>>&dp)
    {
        if(index==s.size()) return 0;
        if(dp[index][time]!=-1) return dp[index][time];
        int include=s[index]*(time+1)+solve(s,time+1,index+1,dp);
        int exclude=solve(s,time,index+1,dp);
        dp[index][time]= max(include,exclude);
        return dp[index][time];
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(satisfaction,0,0,dp);
    }
};