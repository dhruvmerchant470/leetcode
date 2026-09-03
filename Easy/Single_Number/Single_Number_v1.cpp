class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a=0;
        for(auto it: nums) a^=it;
        return a;
    }
};