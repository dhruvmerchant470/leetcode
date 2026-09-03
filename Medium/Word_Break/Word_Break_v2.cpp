class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool>dp(n+1,0);
        // for(int i=0;i<=n;i++) dp[i]=0;
        dp[0]=1;
        for(int i=1;i<=s.length();i++){
            for(auto word:wordDict){
                int start=i-word.size();
                if(start>=0 && dp[start] && s.substr(start,word.size())==word){
                    dp[i]=1;
                }
            }
        }
        return dp[n];
    }
};