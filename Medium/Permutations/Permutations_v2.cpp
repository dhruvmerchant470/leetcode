class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>nums,int index){
        if(index>=nums.size()) ans.push_back(nums);
        for(int i=index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            solve(ans,nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        solve(ans,nums,0);
        return ans;
    }
};