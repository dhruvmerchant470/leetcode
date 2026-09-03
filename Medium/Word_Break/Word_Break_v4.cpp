class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool>dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(auto word: wordDict){
                if(i-(int)word.size()>=0 && dp[i-word.size()] && s.substr(i-word.length(),word.size())==word){
                    dp[i]=true;
                }
            }
        }
        return dp[n];
    }
};