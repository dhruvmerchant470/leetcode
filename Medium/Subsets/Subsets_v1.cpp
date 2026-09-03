class Solution {
public:
    void sub(vector<vector<int>>&ans,vector<int>&temp,vector<int>nums,int index,int n){
        if(index<=n){
            ans.push_back(temp);
        }
        for(int i=index;i<n;i++){
            temp.push_back(nums[i]);
            sub(ans,temp,nums,i+1,n);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>t;
        sub(ans,t,nums,0,nums.size());
        return ans;
    }
};