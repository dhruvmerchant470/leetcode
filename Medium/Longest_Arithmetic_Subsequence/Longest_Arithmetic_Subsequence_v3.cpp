class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(2001,0));
        int maxi = -1;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dp[j][nums[j] - nums[i]+1000] = dp[i][nums[j] - nums[i]+1000] + 1;
                maxi = max(maxi,dp[j][nums[j]-nums[i]+1000]);
            }
        }
        return maxi + 1;
    }
};