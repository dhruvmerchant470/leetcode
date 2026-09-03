class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev_1=cost[1];
        int prev_2=cost[0];
        for(int i=2;i<cost.size();i++)
        {
            int curr=min(prev_1,prev_2)+cost[i];
            prev_2=prev_1;
            prev_1=curr;
        }
        return min(prev_1,prev_2);
    }
};