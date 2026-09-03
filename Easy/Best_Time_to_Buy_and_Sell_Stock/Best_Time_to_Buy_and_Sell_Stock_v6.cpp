class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost=prices[0];
        int profit=0;
        for(int i=0;i<prices.size();i++){
            cost=min(prices[i],cost);
            profit=max(profit,prices[i]-cost);
        }
        return profit;
        
    }
};