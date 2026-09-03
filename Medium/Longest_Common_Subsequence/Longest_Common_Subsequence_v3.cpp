class Solution {
public:
    int solve(string &text1,string &text2,int i,int j,vector<vector<int>>&dp)
    {
        if(i==text1.length()||j==text2.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j]=1+solve(text1,text2,i+1,j+1,dp);
        else return dp[i][j]=max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));
    }
    int solveTab(string text1, string text2)
    {
        vector<int>curr(text2.length()+1,0);
        vector<int>next(text2.length()+1,0);

        for(int i=text1.length()-1;i>=0;i--)
        {
            for(int j=text2.length()-1;j>=0;j--)
            {
                if(text1[i]==text2[j]) curr[j]=1+next[j+1];
                else curr[j]=max(curr[j+1],next[j]);
            }         
            next=curr;
        }
        return curr[0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // vector<vector<int>>dp(text1.length()+1,vector<int>(text2.length(),-1));
        return solveTab(text1,text2);
    }
};