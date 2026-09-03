class Solution {
public:
    void recurse(set<vector<int>>& subsets, int index, vector<int>& nums, int n,
                 vector<int> subset) {
        if (index == n) {
            subsets.insert(subset);
            return;
        }

        recurse(subsets,index+1,nums,n,subset);
        subset.push_back(nums[index]);
        recurse(subsets,index+1,nums,n,subset);
        subset.pop_back();
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>subsets;
        vector<int>subset;
        recurse(subsets,0,nums,n,subset);
        vector<vector<int>>ans;
        for(auto it: subsets){
            ans.push_back(it);
        }
        return ans;
    }
};