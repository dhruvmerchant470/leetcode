class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        bool dp[n][n];
        int cnt=0;
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

                    if(dp[i][j]==true) cnt++;
            }    
        }
        return cnt;
    }
};