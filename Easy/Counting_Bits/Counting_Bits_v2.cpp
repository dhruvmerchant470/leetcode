class Solution {
public:
    
    vector<int> countBits(int n) {
        if(n==0) return {0};
        if(n==1) return {0,1};
        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=1;
        dp[2]=1;
        int prev_2=2;
        for(int i=3;i<=n;i++){
            if(i%prev_2==0 && dp[i-prev_2]==1){
                dp[i]=1;
                prev_2=i;
            }
            else dp[i]=dp[i-prev_2]+dp[prev_2];
        }
        return dp;
    }
};