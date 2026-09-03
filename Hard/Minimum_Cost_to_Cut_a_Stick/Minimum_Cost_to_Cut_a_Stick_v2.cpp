class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int size = cuts.size();
        vector<vector<int>> dp(size + 1, vector<int>(size + 1, INT_MAX));
        sort(cuts.begin(), cuts.end());
        for (int i = 0; i < cuts.size() - 1; i++) {
            dp[i][i + 1] = 0;
        }
        for (int i = size - 2; i >= 0; i--) {
            for (int j = i + 2; j < size; j++) {
                for (int k = i + 1; k < j; k++) {
                    if (dp[i][k] != INT_MAX && dp[k][j] != INT_MAX) {
                        dp[i][j] =
                            min(dp[i][j], dp[i][k] + dp[k][j] +
                                              cuts[j] - cuts[i]);
                    }
                }
            }
        }

        return dp[0][size-1];
    }
};