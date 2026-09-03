class Solution {
public:
    void recurse(vector<vector<int>>&ans,vector<int>&nums,int index,vector<int>tmp){
        ans.push_back(tmp);
        if(index>=nums.size()) return;
        for(int i=index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            tmp.push_back(nums[i]);
            recurse(ans,nums,i+1,tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        recurse(ans,nums,0,{});
        return ans;
    }
};