class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int power=0;
        for(int i=0;i<n;i++){
            if(i<=power) {
                power=max(power,i+nums[i]);
                if(power>=n-1) return 1;
            }
            else return 0;
        }
        return 0;
    }
};