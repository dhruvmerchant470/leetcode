class Solution {
public:
    int solve(vector<int>& nums, int index, int prev_index,
              vector<vector<int>>& dp) {
        if (index >= nums.size())
            return 0;
        if (dp[index][prev_index+1] != -1)
            return dp[index][prev_index+1];
        int not_take = solve(nums, index + 1, prev_index, dp);
        int take = 0;
        if (prev_index == -1 || nums[prev_index] < nums[index])
            take = 1 + solve(nums, index + 1, index,dp);
        return dp[index][prev_index+1] = max(take, not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(nums, 0, -1, dp);
    }
};