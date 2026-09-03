class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,0));
        int maxi=-1;
        string ans="";
        for(int gaps=0;gaps<n;gaps++){
            for(int i=0,j=gaps;j<n;j++,i++){ //travelling across diagonals
                    if(gaps==0) dp[i][j]=true;
                    else if(gaps==1){
                        if(s[i]==s[j]) dp[i][j]=true;
                        else dp[i][j]=false;
                    }
                    else{
                        if(s[i]==s[j] && dp[i+1][j-1]==true) dp[i][j]=true;
                        else dp[i][j]=false;
                    }

                    if(dp[i][j]==true) {
                        if(gaps>maxi){
                            ans=s.substr(i,gaps+1);
                        }
                    }
            }    
        }
        return ans;
    }
};