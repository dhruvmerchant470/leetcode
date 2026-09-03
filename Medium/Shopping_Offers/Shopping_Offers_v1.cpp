class Solution {
public:
    unordered_map<string, int> dp;

    int solve(vector<int>& price,
              vector<vector<int>>& special,
              vector<int>& needs) {

        string key;

        for (int x : needs) {
            key += to_string(x) + ",";
        }

        if (dp.count(key))
            return dp[key];

        // Buy everything normally
        int ans = 0;

        for (int i = 0; i < needs.size(); i++) {
            ans += needs[i] * price[i];
        }

        // Try every special offer
        for (auto& offer : special) {

            bool possible = true;

            for (int i = 0; i < needs.size(); i++) {
                if (offer[i] > needs[i]) {
                    possible = false;
                    break;
                }
            }

            if (!possible)
                continue;

            // Apply offer
            for (int i = 0; i < needs.size(); i++) {
                needs[i] -= offer[i];
            }

            ans = min(ans, offer.back() +
                           solve(price, special, needs));

            // Backtrack
            for (int i = 0; i < needs.size(); i++) {
                needs[i] += offer[i];
            }
        }

        return dp[key] = ans;
    }

    int shoppingOffers(vector<int>& price,
                       vector<vector<int>>& special,
                       vector<int>& needs) {

        return solve(price, special, needs);
    }
};