class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])) return 1;
            mp.insert(nums[i]);
        }
        return 0;
    }
};