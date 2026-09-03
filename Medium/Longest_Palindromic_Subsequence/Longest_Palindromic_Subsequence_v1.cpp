class Solution {
public:
int solve(string &text1,string &text2,int i,int j,vector<vector<int>>&dp)
    {
        if(i==text1.length()||j==text2.length()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j]=1+solve(text1,text2,i+1,j+1,dp);
        else return dp[i][j]=max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));
    }
    string reverse(string s)
    {
        int i=0,j=s.length()-1;
        while(i<j)
        {
            swap(s[i++],s[j--]);
        }
        return s;
    }
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        string s1=reverse(s);
        cout<<s1<<endl;
        return solve(s,s1,0,0,dp);
    }
};