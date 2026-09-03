class Solution {
public:
    int climbStairs(int n) {
        int prev_1=1;
        int prev_2=1;
        for(int i=2;i<=n;i++)
        {
            int curr= prev_1+prev_2;
            prev_2=prev_1;
            prev_1=curr;
        }
        return prev_1;
    }
};