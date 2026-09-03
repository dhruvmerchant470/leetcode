class Solution {
public:
    int solve(vector<int>& obstacles, vector<vector<int>>& dp, int currlane,
              int currpos) {
        int n = obstacles.size() - 1;
        if (currpos == n)
            return 0;
        if (dp[currlane][currpos] != -1)
            return dp[currlane][currpos];
        if (obstacles[currpos + 1] != currlane)
            return solve(obstacles, dp, currlane, currpos + 1);
        else {
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++) {
                if (obstacles[currpos] != i &&
                    currlane !=
                        i) // 1st condition-->jaha sidejump karna hai vaha
                           // obstacle nahi hona chaiye cond2-->jaha jump kar
                           // rahe ho vo same lane nahi honi chaiye;
                    ans = min(ans, 1 + solve(obstacles, dp, i, currpos));
            }
            dp[currlane][currpos] = ans;
            return dp[currlane][currpos];
        }
    }
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp(4, vector<int>(n, -1));
        return solve(obstacles, dp, 2, 0);
    }
};