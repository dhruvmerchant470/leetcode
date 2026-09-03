class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int buy_price=nums[0],profit=0;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]<buy_price)
            {
                buy_price=nums[i];
            }
            if(nums[i]-buy_price>profit)
            {
                profit=nums[i]-buy_price;
            }
        }
        return profit;
    }
};