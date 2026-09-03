class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp,
              bool swapped, int index) {
        if (index == nums1.size())
            return 0;
        if (dp[index][swapped] != -1)
            return dp[index][swapped];
        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];
        int ans = INT_MAX;
        if (swapped) {
            swap(prev1, prev2);
        }
        // no swap
        if (nums1[index] > prev1 && nums2[index] > prev2) {
            ans = solve(nums1, nums2, dp, 0, index + 1);
        }
        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, dp, 1, index + 1));

        return dp[index][swapped] = ans;
    }
    int solveTab(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int index = n-1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];
                int ans = INT_MAX;
                if (swapped) {
                    swap(prev1, prev2);
                }
                // no swap
                if (nums1[index] > prev1 && nums2[index] > prev2) {
                    ans = dp[index + 1][0];
                }
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + dp[index + 1][1]);

                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }
     int solveSO(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        int n = nums1.size();
        vector<int>next(2,0);
        vector<int>curr(2,0);
        for (int index = n-1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {
                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];
                int ans = INT_MAX;
                if (swapped) {
                    swap(prev1, prev2);
                }
                // no swap
                if (nums1[index] > prev1 && nums2[index] > prev2) {
                    ans = next[0];
                }
                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + next[1]);

                curr[swapped] = ans;
            }
            next=curr;
        }
        return curr[0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        // adding -1 in the begging of each array so to get prev1 and prev2
        // nums1.insert(nums1.begin(), -1);
        // nums2.insert(nums2.begin(), -1);
        // int n = nums1.size();
        // vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        // return solve(nums1, nums2, dp, 0, 1);
        return solveSO(nums1,nums2);
    }
};