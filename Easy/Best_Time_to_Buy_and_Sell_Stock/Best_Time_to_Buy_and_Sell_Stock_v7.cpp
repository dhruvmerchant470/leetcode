class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
            cost=min(cost,prices[i]);
            profit=max(profit,prices[i]-cost);
        }
        return profit;
    }
};