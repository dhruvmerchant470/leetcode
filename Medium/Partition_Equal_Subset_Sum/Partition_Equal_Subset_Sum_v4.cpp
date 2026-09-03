class Solution {
public:
    bool canPartition(vector<int>& num) {
        int sum=0;
        for(int i=0;i<num.size();i++){
            sum+=num[i];
        }
        if(sum&1) return 0;
        int target=sum/2;
        int n=num.size();
        long long dp[n+1][target+1];
    for(long long i=0;i<=n;i++){
        for(long long j=0;j<=target;j++){
            if(i==0) dp[i][j]=0;
            if(j==0) dp[i][j]=1;
        }
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=target;j++){
            if(num[i-1]<=j) dp[i][j]=(dp[i-1][j-num[i-1]]||dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }

    return dp[n][target];
    
    }
};