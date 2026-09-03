class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k=2;
        int n=prices.size();
        vector<vector<int>>curr(2,vector<int>(k+1,0));
        vector<vector<int>>next(2,vector<int>(k+1,0));

        for(int index=n-1;index>=0;index--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int limit=1;limit<=k;limit++)
                {
                    int profit=0;
                    if(buy)
                    {
                        int will_buy=-prices[index]+next[0][limit];
                        int will_skip=next[1][limit];
                        profit=max(will_buy,will_skip);
                    }
                    else
                    {
                        int will_sell=prices[index]+next[1][limit-1];
                        int will_skip=next[0][limit];
                        profit=max(will_sell,will_skip);
                    }
                    curr[buy][limit]= profit; 
                }
                next=curr;
            }
        }
        return next[1][k];
    
    }
};