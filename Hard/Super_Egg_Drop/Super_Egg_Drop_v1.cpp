class Solution {
public:
    int solve(int e, int f, vector<vector<int>>& dp) {
        if (f == 0 || f == 1 || e == 1)
            return f;

        if (dp[e][f] != -1)
            return dp[e][f];

        int low = 1;
        int high = f;
        int ans = INT_MAX;

        while (low <= high) {
            int k = low + (high - low) / 2;

            int t1 = solve(e - 1, k - 1, dp);
            int t2 = solve(e, f - k, dp);

            int worst = 1 + max(t1, t2);
            ans = min(ans, worst);

            if (t1 < t2) {
                low = k + 1;
            }
            else {
                high = k - 1;
            }
        }

        return dp[e][f] = ans;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
        return solve(k, n, dp);
    }
};