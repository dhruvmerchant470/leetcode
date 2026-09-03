class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit = 0;
       int curr = prices[0];
       int diff = 0;
       for(int i=1;i<prices.size();i++){
            diff = max(prices[i]-curr,diff);
            curr = min(curr,prices[i]);
            profit = max(profit,diff);
       }
       return profit;
    }
};