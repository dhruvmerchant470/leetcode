class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        vector<bool>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(auto words: wordDict){
                int index=i-words.length();
                if(index>=0 && dp[index] && s.substr(index,words.length())==words){
                    dp[i]=1;
                }
            }
        }
        return dp[n];
    }
};