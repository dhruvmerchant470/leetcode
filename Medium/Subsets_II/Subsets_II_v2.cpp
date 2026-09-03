class Solution {
public:
    vector<vector<int>>ans;
    void recurse(vector<int>tmp,vector<int>&nums,int index){
        ans.push_back(tmp);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i-1]==nums[i]) continue;
            tmp.push_back(nums[i]);
            recurse(tmp,nums,i+1);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        recurse({},nums,0);
        return ans;
    }
};