class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int curr = prices[0];
        for(int i=1;i<prices.size();i++){
            curr = min(curr,prices[i]);
            profit = max(profit,prices[i]-curr);
        }
        return profit;
    }
};