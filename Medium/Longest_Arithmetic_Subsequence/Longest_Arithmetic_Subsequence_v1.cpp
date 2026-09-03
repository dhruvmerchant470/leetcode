class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dp[j][nums[j] - nums[i]] = dp[i][nums[j] - nums[i]] + 1;
            }
        }
        int maxi = -1;
        for (auto it1 : dp) {
            for (auto it : it1) {
                maxi = max(maxi, it.second);
            }
        }

        return maxi + 1;
    }
};