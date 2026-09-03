class Solution {
public:
    void recurse(vector<vector<int>>&ans,vector<int>&candidates,int sum,int target, int n, int index,vector<int>tmp){
        if(sum>target || index>=n){
            return ;
        }
        else if(sum==target){
            ans.push_back(tmp);
            return ;
        }

        recurse(ans,candidates,sum,target,n,index+1,tmp);
        tmp.push_back(candidates[index]);
        recurse(ans,candidates,sum+candidates[index],target,n,index,tmp);
        tmp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>ans;
        recurse(ans,candidates,0,target,n,0,{});
        return ans;
    }
};