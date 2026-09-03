class Solution {
public:
    int findTargetSumWays(vector<int>& arr, int diff) {
        int tot_sum = 0;
        int n = arr.size();
        for(int num: arr) tot_sum+=num;
        tot_sum = (tot_sum+diff);
        if(tot_sum&1 || tot_sum<0) return 0;
        tot_sum/=2;
        vector<vector<int>>dp(n+1,vector<int>(tot_sum+1));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=tot_sum;j++){
                if(arr[i-1]<=j) dp[i][j]=dp[i-1][j-arr[i-1]]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][tot_sum];
    }
};