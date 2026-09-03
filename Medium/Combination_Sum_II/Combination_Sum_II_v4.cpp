class Solution {
public:
    void recurse(vector<vector<int>>&ans,vector<int>&candidates,int target,int index,vector<int>tmp){
        if(target==0) {
            ans.push_back(tmp);
            return;
        }
        if(index>=candidates.size() || target<0) return;
        for(int i=index;i<candidates.size();i++){
            if(i!=index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            tmp.push_back(candidates[i]);
            recurse(ans,candidates,target-candidates[i],i+1,tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        recurse(ans,candidates,target,0,{});
        return ans;
    }
};