class Solution {
public:
    void recurse(vector<vector<int>>&ans, int index,vector<int>&candidates,int target,vector<int>tmp){
        if(index >= candidates.size() || target<0){
            return;
        }
        if(target == 0){
            ans.push_back(tmp);
            return;
        }
        //i don't take it
        recurse(ans,index+1,candidates,target,tmp);
        //i take it
        tmp.push_back(candidates[index]);
        recurse(ans,index,candidates,target-candidates[index],tmp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        recurse(ans,0,candidates,target,{});
        return ans;
    }
};