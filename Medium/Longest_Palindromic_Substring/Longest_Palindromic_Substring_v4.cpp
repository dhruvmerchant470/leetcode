class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int maxi = -1;
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int gaps=0;gaps<n;gaps++){
            for(int i=0,j=gaps;j<n;j++,i++){
                if(gaps==0) dp[i][j]=true;
                else if(gaps==1 && s[i]==s[j]) dp[i][j]=true;
                else if(gaps>1 && s[i]==s[j] && dp[i+1][j-1]==true) dp[i][j]=true;
                if(dp[i][j] && maxi<gaps){
                    maxi = gaps;
                    ans = s.substr(i,gaps+1);
                }
            }
        }
        return ans;
    }
};