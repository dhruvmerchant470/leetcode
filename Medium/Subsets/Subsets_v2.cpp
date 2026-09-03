class Solution {
public:
    void recurse(vector<vector<int>>&subsets, vector<int>subset, vector<int>&nums, int index){
        if(index==nums.size()) {
            subsets.push_back(subset);
            return;
        }

        recurse(subsets,subset,nums,index+1); //don't pick
        subset.push_back(nums[index]); //pick it
        recurse(subsets,subset,nums,index+1);
        subset.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>subsets;
        vector<int>subset;
        recurse(subsets,subset,nums,0);
        return subsets;
    }
};